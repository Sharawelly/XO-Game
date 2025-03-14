// File name: Pyramid
// Purpose: For game 1
// Author(s):  osama mohamed
// ID(s):20220056
// Section:s5
// Date:17/12/2023
// Version: 1

#include "Pyramid.h"
#include<bits/stdc++.h>
pyramid::pyramid():Board()
{
    n_cols = 5;
    n_rows = 3;
    n_moves = 0;

    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool pyramid::update_board(int x, int y, char mark)
{

    if(x==0 && y!=2)
        return false;
    if(x==1 && (y==0 || y==4))
        return false;
    if (board[x][y] == ' ' && x<n_rows && y<n_cols && ~y&&~x)
    {
        board[x][y] = mark;
        n_moves++;
        return true;
    }
    return false;
}

void pyramid::display_board()
{

      system("cls");
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            if ((i==0 && j==2) || (i==1 && !(j==0 || j==4)) || (i==2)) {
                cout << "(" << i << "," << j << ")";;
                cout<<board[i][j];
            } else {
                cout << "     ";
            }
        }
        cout << "\n-----------------------------\n";
    }
}

bool pyramid::is_winner()
{
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != ' ')
    {
        return true;
    }
    else if (board[1][1] == board[1][2] && board[1][1] == board[1][3] && board[1][1] != ' ')
    {
        return true;
    }
    else if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[1][3] != ' ')
    {
        return true;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ')
    {
        return true;
    }
    else if (board[2][1] == board[2][2] && board[2][1] == board[2][3] && board[2][1] != ' ')
    {
        return true;
    }
    else if (board[2][2] == board[2][3] && board[2][2] == board[2][3] && board[2][3] != ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pyramid::is_draw()
{

    return n_moves == 9 && !is_winner();
}

bool pyramid::game_is_over()
{
    return n_moves >= 9;
}


