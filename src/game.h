#ifndef GAME_H
#define GAME_H

#include <memory>
#include "tetromino.h"
#include "board.h"
#include "renderer.h"

class Game {
public:
    Game();
    bool Run(int target_frame_duration);
    void setRenderer(std::unique_ptr<Renderer> &&renderer);
    void CollisionCheck(const Tetromino &t);
    void Difficulty();

private:
    void RestGame();
    std::unique_ptr<Renderer> _renderer;
    Tetromino _tetromino;
    Board _board;
    int _moveTime;
    int _dropSpeed;
    int _level;
};

#endif
