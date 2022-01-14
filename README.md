# C++ nanodegree: Capstone Project - Tetris Game 
Implementation of Game [Tetris](https://en.wikipedia.org/wiki/Tetris) for the Capstone project as a part of the  
[Udacity C++ Nanodegree program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

## How to play
The target of this game is to place the falling blocks (or tetrominos) in such  
a way that the game board has no empty spaces.  
The player can rotate tetrominos, move them sideways and accelerate their fall.  
The game is over when addition of one more tetromino leads to overflowing  
the border of the game board from the top. When a row in the Board has no empty  
cells, it is deleted and the score is incremented by 100. For every 200 points,  
the falling rate of the tetrominos will increase. 

The following keyboard inputs are accepted:

| Keyboard Input  | Function |
| -------------   |:-------------:|
| left arrow      | move the tetromino left    |
| right arrow     | move the tetromino right     |
| up arrow        | rotate the tetromino clockwise    |
| down arrow      | move the tetromino down     |
| space           | drop down the tetromino until it collides with a block or border |
| r               | restart the game |
| q               | quit game |

## Dependencies for Running Locally
- cmake >= 3.16.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- SDL >= 2.0
  - All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  - Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
- gcc/g++ >= 7.5.0
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repository
2. Make a build directory in the top level directory and navigate to it: 
    `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run: `./Tetris`.

## File Structure

This repository contains:
- `cmake/` : cmake configuration to find SDL2 Library files.

- `src/` : source files and header files. Description below in the next section.

- `build/` : The following dll files must be present to run the `Tetris.exe` file in windows:
    1. libfreetype-6.dll
    1. libjpeg-9.dll
    1. libpng16-16.dll
    1. libtiff-5.dll
    1. libwebp-7.dll
    1. SDL2.dll
    1. SDL2_image.dll
    1. SDL2_ttf.dll
    1. zlib1.dll

- `CMakeLists.txt` : cmake configuration file.

- `README.md` : This file

## Class description
The code is divided into four classes:

- **Game:** the game loop is done here - keyboard input is accepted, processed  
and the game window is rendered.

- **Renderer:** The SDL library operations are encapsulated here.

- **Board:** The tetrominos are placed, the score is calculated and a row is deleted if full.

- **Tetromino:** The blocks or so called Tetrominos are initialized here.  
APIs to move, rotate and knowing whether it is a valid block are also provided.

## Rubric points
The following rubric points are addressed:
1. The project demonstrates an understanding of C++ functions and control structures: src/main.cpp:21
1. The project accepts user input and processes the input: ./src/game.cpp:24-78
1. The project uses Object Oriented Programming techniques: ./src/game.cpp, ./src/board.cpp, ./src/tetromino.cpp
1. Class constructors utilize member initialization lists:  ./src/game.cpp:5-8
1. Classes encapsulate behavior  - Member functions of tetromino class and board class are encapsulated from game class.
1. The project makes use of references in function declarations  ./src/board.h:15, 16
1. The project uses destructors appropriately: src/renderer.cpp:34
1. The project uses smart pointers instead of raw pointers: ./src/game.h:19, ./src/main.cpp:15

