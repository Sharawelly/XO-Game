// File name: X_O_5
// Purpose: For game 1
// Author(s):   Wajih Samir Hussein Ahmed
// ID(s): 20220376
// Section:s5
// Date:17/12/2023
// Version: 1

// FiveByFiveBoard.cpp
#include "X_O_5.h"
#include <bits/stdc++.h>
using namespace std;
FiveByFiveBoard::FiveByFiveBoard(){
    count_X = count_O = 0;
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool FiveByFiveBoard::update_board(int x, int y, char symbol) {
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols || board[x][y] != ' ') {
        return false;
    }

    board[x][y] = symbol;
    ++n_moves;
    return true;
}

void FiveByFiveBoard::display_board() {
    system("cls");
    for (int i = 0; i < n_rows; ++i) {
        cout << "\n|";
        for (int j = 0; j < n_cols; ++j) {
            char a = board[i][j];
            if (board[i][j] == 0)  a = ' ';
            cout << "(" << i << "," << j << ")" << setw(2) << a << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << '\n';
}

bool FiveByFiveBoard::is_winner() {
    count_X = 0, count_O = 0;
    char x;
    // Check Horizontal
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 2; ++j) {
            x = board[i][j] & board[i][j+1] & board[i][j+2];
            if (x != ' ' && x == board[i][j]){
                count_X += (x == 'X');
                count_O += (x == 'O');
            }
        }
    }
    // Check Vertical
    for (int i = 0; i < n_rows - 2; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j] & board[i+2][j];
            if (x != ' ' && x == board[i][j]){
                count_X += (x == 'X');
                count_O += (x == 'O');
            }
        }
    }
    // Check Diagonal (Right)
    for (int i = 0; i < n_rows - 2; ++i) {
        for (int j = 0; j < n_cols - 2; ++j) {
            x = board[i][j] & board[i+1][j+1] & board[i+2][j+2];
            if (x != ' ' && x == board[i][j]){
                count_X += (x == 'X');
                count_O += (x == 'O');
            }
        }
    }
    // Check Diagonal (Left)
    for (int i = 0; i < n_rows - 2; ++i) {
        for (int j = 2; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j-1] & board[i+2][j-2];
            if (x != ' ' && x == board[i][j]){
                count_X += (x == 'X');
                count_O += (x == 'O');
            }
        }
    }
    return n_moves==24 && count_X>count_O;
}

bool FiveByFiveBoard::is_draw() {
    is_winner();
    return n_moves==24 && count_O==count_X;
}

bool FiveByFiveBoard::game_is_over() {
    return n_moves >= 24;
}




