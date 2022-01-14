#include "board.h"
#include <iostream>

Board::Board():	_data{ '0' }
{
    score = 0;
}

void Board::PlaceGrid(SDL_Renderer* renderer, Tetromino t) 
{
    for (auto x = 0; x < Width; x++)
    {
        for (auto y = 0; y < Height; y++)
        {
            switch (_data[x][y])
            {
            case '1':
                SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
                break;
            case '2':
                SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0x00, 0xff);
                break;
            case '3':
                SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0xff, 0xff);
                break;
            case '4':
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, 0xff);
                break;
            case '5':
                SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
                break;
            case '6':
                SDL_SetRenderDrawColor(renderer, 0xbf, 0xff, 0x00, 0xff);
                break;
            case '7':
                SDL_SetRenderDrawColor(renderer, 0xff, 0xa5, 0x00, 0xff);
                break;
            default:
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
                _data[x][y] = '0';
                break;
            };

            SDL_Rect rect{ x * 720 / 2 / 10, y * 720 / 2 / 10 , 720 / 2 / 10, 720 / 2 / 10  };
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}

bool Board::isCollision(const Tetromino& t) const
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (t.isBlock(x, y) != '0')
            {
                auto wx = t.x() + x;
                auto wy = t.y() + y;
                if (wx < 0 || wx >= Width || wy < 0 || wy >= Height)
                    return true;
                if (_data[wx][wy] != '0')
                    return true;
            }
    return false;
}

void Board::unite(const Tetromino &t)
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (t.isBlock(x, y) != '0')
            {
                _data[t.x() + x][t.y() + y] = t.isBlock(x, y);
            }
}

void Board::SolidLine()
{
    for (int y = Height - 1; y >= 0; --y)
    {
        _solid = true;
        for (int x = 0; x < Width; ++x)
            if (_data[x][y] == '0')
            {
                _solid = false;
                break;
            }
        if (_solid)
        {
            for (int yy = y - 1; yy >= 0; --yy)
                for (int x = 0; x < Width; ++x) {
                    _data[x][yy + 1] = _data[x][yy];
                }
            for (int x = 0; x < Width; ++x)
                _data[x][0] = '0';

            score += 100;
        }
    }
}
