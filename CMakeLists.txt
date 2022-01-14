cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(SDL2_PATH C:/msys64/mingw64/SDL2)
set(SDL2_DIR C:/msys64/mingw64/SDL2)
set(SDL2 C:/msys64/mingw64/SDL2)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIR}
  inc)

add_executable(
  Tetris 
  src/tetromino.cpp
  src/board.cpp
  src/renderer.cpp
  src/game.cpp
  src/main.cpp 
  )
  
# string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(
  Tetris
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  )
