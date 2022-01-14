#include "game.h"
#include <iostream>
#include <string>

Game::Game() : _tetromino{ static_cast<Shape>(rand() % 7) }, _moveTime(SDL_GetTicks())
{   
    _level = 1;
    _dropSpeed = 800;
}

void Game::setRenderer(std::unique_ptr<Renderer> &&renderer)
{
    _renderer = std::move(renderer);
}


bool Game::Run(int target_frame_duration)
{
    SDL_Event e;
    Tetromino t = _tetromino;

    SDL_Renderer * SDLr = _renderer->getRenderer();

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_KEYDOWN:
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        while (!_board.isCollision(t)) 
                        {
                            _tetromino = t;
                            t.move(0, 1);
                        }
                        break;

                    case SDLK_DOWN:
                        t.move(0, 1);
                        if(!_board.isCollision(t))
                            _tetromino = t;
                        break;

                    case SDLK_RIGHT:
                        t.move(1, 0);
                        if (!_board.isCollision(t))
                            _tetromino = t;
                        break;

                    case SDLK_LEFT:
                        t.move(-1, 0);
                        if (!_board.isCollision(t))
                            _tetromino = t;
                        break;

                    case SDLK_UP:
                        t.rotate();
                        if (!_board.isCollision(t))
                            _tetromino = t;
                        break;

                    case SDLK_q:
                        return false;
                        break;

                    case SDLK_r:
                        RestGame();
                        break;    
                }
            }
            break;

            case SDL_QUIT:
                return false;
        }
    }

    _renderer->clearRenderer();
    _board.PlaceGrid(SDLr, _tetromino);
    _tetromino.render(SDLr);

    _board.SolidLine();

    Difficulty();
    if (SDL_GetTicks() > _moveTime)
    {
        _moveTime += _dropSpeed;
        t = _tetromino;
        t.move(0, 1);
        CollisionCheck(t);
    }
    _renderer->present();
    _renderer->RunWindowTitle(_board.score, _level, target_frame_duration);
    return true;
}

void Game::CollisionCheck(const Tetromino &t)
{
    if (_board.isCollision(t))
    {
        _board.unite(_tetromino);
        _tetromino = Tetromino{ static_cast<Shape>(rand() % 7) };
        if (_board.isCollision(_tetromino))
        {
            _renderer->ErrorReporting(GAMEOVER, _board.score);
            RestGame();
        }
    }
    else
    {
        _tetromino = t;
    }
}

void Game::Difficulty()
{
    switch (_board.score)
    {
    case  200:
        _level = 2;
        _dropSpeed = 720;
    break;
    case  400:
        _level = 2;
        _dropSpeed = 630;
        break;
    case  600:
        _level = 3;
        _dropSpeed = 550;
        break;
    case  800:
        _level = 3;
        _dropSpeed = 470;
        break;
    case  1000:
        _level = 4;
        _dropSpeed = 380;
        break;
    case  1200:
        _level = 4;
        _dropSpeed = 300;
        break;
    case  1400:
        _level = 5;
        _dropSpeed = 220;
        break;
    case  1600:
        _level = 5;
        _dropSpeed = 130;
        break;
    case  1800:
        _level = 6;
        _dropSpeed = 100;
        break;
    case  2000:
        _level = 6;
        _dropSpeed = 80;
        break;
    case  2200:
        _level = 7;
        _dropSpeed = 70;
        break;
    case  2400:
        _level = 7;
        _dropSpeed = 50;
        break;
    case  2600:
        _level = 8;
        _dropSpeed = 30;
        break;
    case  2800:
        _level = 8;
        _dropSpeed = 20;
        break;
    case  3000:
        _level = 9;
        _dropSpeed = 10;
        break;
    }

}

void Game::RestGame() 
{
    _tetromino = Tetromino{ static_cast<Shape>(rand() % 7) };
    _board = Board();
    _level = 1;
    _dropSpeed = 800;
    _moveTime = SDL_GetTicks();
    SDL_Delay(500);
}


