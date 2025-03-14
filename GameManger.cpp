#include "BoardGame_Classes.h"
#include<iostream>
using namespace std;


GameManager::GameManager(Board* boardPtr, Player* players[2])
{
   this->players[0]=players[0];
    this->players[1]=players[1];
    this->boardPtr = boardPtr;
}

void GameManager::run()
{
    int x,y;
    boardPtr->display_board();
    int turn=0;
    while (!boardPtr->game_is_over()) {
     x=-1, y=-1;
    if(boardPtr->is_draw())
    {
        cout<<"Draw!!!!!\n";
        return;
    }
    if(boardPtr->is_winner())
    {
        cout<< players[turn^1]->to_string()<<" is the winner\n";
        return;
    }
    players[turn]->get_move(x,y);
    while (!boardPtr->update_board(x, y, players[turn]->get_symbol())) {
           players[turn]->get_move(x,y);
        }
        boardPtr->display_board();
    turn^=1;
    }


    if(boardPtr->is_draw())
    {
        cout<<"Draw!!!!!\n";
        return;
    }
    if(boardPtr->is_winner())
    {
        if(players[1]->get_symbol()=='X')
        {
            cout<<players[1]->to_string()<<" is the winner\n";
            return;
        }
        else
        {
            cout<<players[2]->to_string()<<" is the winner\n";
        }
        return;
    }
    else
    {
        if(players[1]->get_symbol()=='O')
        {
            cout<<players[1]->to_string()<<" is the winner\n";
            return;
        }
        else
        {
            cout<<players[2]->to_string()<<" is the winner\n";
        }
        return;
    }
}