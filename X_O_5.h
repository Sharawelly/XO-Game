// File name: X_O_5
// Purpose: For game 1
// Author(s):    Wajih Samir Hussein Ahmed
// ID(s):20220376
// Section:s5
// Date:17/12/2023
// Version: 1

#ifndef UNTITLED26_X_O_5_H
#define UNTITLED26_X_O_5_H
#include "BoardGame_Classes.h"
class FiveByFiveBoard : public Board {
    int count_X, count_O;
public:
    FiveByFiveBoard();
    bool update_board(int x, int y, char symbol)override;
    void display_board()override;
    bool is_winner()override;
    bool is_draw()override;
    bool game_is_over()override;
};

#endif //UNTITLED26_X_O_5_H
