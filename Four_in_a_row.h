// File name: Four_in_a_row
// Purpose: For game 2
// Author(s):    Marawan Shirif
// ID(s):20220325
// Section:s5
// Date:17/12/2023
// Version: 1

#ifndef UNTITLED26_FOUR_IN_A_ROW_H
#define UNTITLED26_FOUR_IN_A_ROW_H
#include "BoardGame_Classes.h"
class Four_in_a_row: public Board{
    // int Final_i, Finalj, winner;
public:
    Four_in_a_row();
    bool update_board (int x, int y, char mark)override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw()override;
    bool game_is_over()override;


};
#endif //UNTITLED26_FOUR_IN_A_ROW_H
