#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const int _screen_width, const int _screen_height) : _screen_width(_screen_width), _screen_height(_screen_height)
{   
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    _sdl_window = SDL_CreateWindow("Tetris Game", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, _screen_width,
        _screen_height, SDL_WINDOW_SHOWN );

    if (nullptr == _sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    _sdl_renderer = SDL_CreateRenderer(_sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == _sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    _title_timestamp = SDL_GetTicks();
    _frame_count = 0;
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(_sdl_renderer);
    SDL_DestroyWindow(_sdl_window);
    SDL_Quit();
}

SDL_Renderer* Renderer::getRenderer()
{
    return _sdl_renderer;
}

void Renderer::clearRenderer()
{
    SDL_SetRenderDrawColor(_sdl_renderer, 0,0,0,0xff);
    SDL_RenderClear(_sdl_renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(_sdl_renderer);
}

void Renderer::ErrorReporting(ErrorType e, int score) 
{
    std::string score_text = "\rScore: " + std::to_string(score);

    switch(e)
    {
        case GAMEOVER:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Game Over",
                         score_text.c_str(),
                         _sdl_window);
            break;

        case DEBUG:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                         "DEBUG",
                         SDL_GetError(),
                         _sdl_window);
            break;
    }
}

void Renderer::RunWindowTitle(int score, int level, int target_frame_duration) 
{
    _frame_start = SDL_GetTicks();

    _frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    _frame_count++;
    _frame_duration = _frame_end - _frame_start;

    // After every second, update the window title.
    if ((_frame_end - _title_timestamp) >= 1000) 
    {
        UpdateWindowTitle(score, _frame_count, level);
        _frame_count = 0;
        _title_timestamp = _frame_end;
    }

    // If the time for this frame is too small (i.e. _frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (_frame_duration < target_frame_duration) 
    {
        SDL_Delay(target_frame_duration - _frame_duration);
    }
}

void Renderer::UpdateWindowTitle(int score, int fps, int level) 
{
    std::string title{ "Tetris - Level: " + std::to_string(level) + " Score: " + std::to_string(score) + " FPS: " + std::to_string(fps) };
    SDL_SetWindowTitle(_sdl_window, title.c_str());
}


