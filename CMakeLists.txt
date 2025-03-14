cmake_minimum_required(VERSION 3.25)
project(untitled26)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled26 tic-tac.cpp BoardGame_Classes.h player.cpp GameManger.cpp Pyramid.h Pyramid.cpp Four_in_a_row.h Four_in_a_row.cpp X_O_5.h X_O_5.cpp X_O_Board.cpp RandomPlayer.cpp)
