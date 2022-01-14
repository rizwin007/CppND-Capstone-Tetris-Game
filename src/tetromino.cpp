#include "tetromino.h"

Tetromino::Tetromino(Shape shape): _shape(shape), _x(10 / 2 - 4 / 2), _y(0), _angle(0){}

void Tetromino::render(SDL_Renderer *renderer)
{
	switch (_shape)
	{
	case SHAPE_I:
		SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
		break;
	case SHAPE_J:
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0x00, 0xff);
		break;
	case SHAPE_L:
		SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0xff, 0xff);
		break;
	case SHAPE_8:
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, 0xff);
		break;
	case SHAPE_S:
		SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
		break;
	case SHAPE_T:
		SDL_SetRenderDrawColor(renderer, 0xbf, 0xff, 0x00, 0xff);
		break;
	case SHAPE_Z:
		SDL_SetRenderDrawColor(renderer, 0xff, 0xa5, 0x00, 0xff);
		break;
	};

	for (auto x = 0; x < 4; x++)
		for (auto y = 0; y < 4; y++)
			if (isBlock(x, y) != '0')
			{
				SDL_Rect rect{ (x + _x) * 720 / 2 / 10 + 1, (y + _y) * 720 / 2 / 10 + 1, 720 / 2 / 10 - 2, 720 / 2 / 10 - 2};
				SDL_RenderFillRect(renderer, &rect);

			}
}

void Tetromino::move(int dx, int dy)
{
	_x += dx;
	_y += dy;
}

void Tetromino::rotate()
{
	++_angle;
	_angle %= 4;
}

Shape Tetromino::getShape()
{
	return _shape;
}

char Tetromino::isBlock(int x, int y) const
{
	static const char *Shapes[][4] =
	{
		{
			"0100"
			"0100"
			"0100"
			"0100",

			"0000"
			"1111"
			"0000"
			"0000",

			"0010"
			"0010"
			"0010"
			"0010",

			"0000"
			"0000"
			"1111"
			"0000",
		},
		{
			"0020"
			"0020"
			"0220"
			"0000",

			"2000"
			"2220"
			"0000"
			"0000",

			"0220"
			"0200"
			"0200"
			"0000",
			
			"0000"
			"2220"
			"0020"
			"0000",
		},
		{
			"0300"
			"0300"
			"0330"
			"0000",

			"0000"
			"3330"
			"3000"
			"0000",

			"0330"
			"0030"
			"0030"
			"0000",

			"0000"
			"0003"
			"0333"
			"0000",
		},
		{
			"0000"
			"0440"
			"0440"
			"0000",

			"0000"
			"0440"
			"0440"
			"0000",

			"0000"
			"0440"
			"0440"
			"0000",

			"0000"
			"0440"
			"0440"
			"0000",
		},
		{
			"0050"
			"0550"
			"0500"
			"0000",

			"0000"
			"5500"
			"0550"
			"0000",

			"0050"
			"0550"
			"0500"
			"0000",

			"0000"
			"5500"
			"0550"
			"0000",
		},
		{
			"0600"
			"0660"
			"0600"
			"0000",

			"0000"
			"6660"
			"0600"
			"0000",

			"0600"
			"6600"
			"0600"
			"0000",

			"0600"
			"6660"
			"0000"
			"0000",
		},
		{
			"0700"
			"0770"
			"0070"
			"0000",

			"0000"
			"0770"
			"7700"
			"0000",

			"0700"
			"0770"
			"0070"
			"0000",

			"0000"
			"0770"
			"7700"
			"0000",
		}
	};

	return Shapes[_shape][_angle][x + y * 4];
}

int Tetromino::x() const
{
	return _x;
}

int Tetromino::y() const
{
	return _y;
}
