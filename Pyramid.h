// File name: pyramid
// Purpose: For game 1
// Author(s):    osama mohamed
// ID(s):20220056
// Section:s5
// Date:17/12/2023
// Version: 1

#ifndef UNTITLED26_PYRAMID_H
#define UNTITLED26_PYRAMID_H
#include "BoardGame_Classes.h"
class pyramid :public Board {
public:
    pyramid();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};

#endif //UNTITLED26_PYRAMID_H
