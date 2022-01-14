#ifndef BOARD_H
#define BOARD_H

#include "SDL.h"
#include "tetromino.h"
#include <iostream>

class Board
{
public:
    Board();
    void PlaceGrid(SDL_Renderer* renderer, Tetromino t) ;
    enum { Width = 10, Height = 20 };
    int score;
    bool isCollision(const Tetromino& t) const;
    void unite(const Tetromino& t);
    void SolidLine();
    
private:
    char _data[Width][Height];
    bool _solid;

};

#endif