#ifndef TETROMINO_H
#define TETROMINO_H

#include <SDL.h>

enum Shape
{
	SHAPE_I,
	SHAPE_J,
	SHAPE_L,
	SHAPE_8,
	SHAPE_S,
	SHAPE_T,
	SHAPE_Z
};

class Tetromino
{
public:
	Tetromino(Shape);
	void render(SDL_Renderer*);
	void move(int dx, int dy);
	void rotate();
	char isBlock(int x, int y) const;
	int x() const;
	int y() const;
	Shape getShape();

private:
	Shape _shape;
	int _x;
	int _y;
	int _angle; // 0 - 0deg, 1 - 90deg, 2 - 180deg, 3 - 270deg
};

#endif