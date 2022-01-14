#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL.h"

enum ErrorType {GAMEOVER, DEBUG };

class Renderer {
public:
    Renderer(const int screen_width, const int screen_height);
    ~Renderer();

    void ErrorReporting(ErrorType e, int score);
    void UpdateWindowTitle(int score, int fps, int level);
    void RunWindowTitle(int score, int level, int target_frame_duration);
    SDL_Renderer *getRenderer();
    void clearRenderer();
    void present();

private:
    SDL_Window* _sdl_window;
    SDL_Renderer* _sdl_renderer;
    int _title_timestamp;
    int _frame_start;
    int _frame_end;
    int _frame_duration;
    int _frame_count;
    const int _screen_width; 
    const int _screen_height;

};

#endif
