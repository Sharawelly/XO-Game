// File name: Four_in_a_row
// Purpose: For game 2
// Author(s):    Marawan Shirif
// ID(s):20220325
// Section:s5
// Date:17/12/2023
// Version: 1

#include "Four_in_a_row.h"
#include <bits/stdc++.h>
Four_in_a_row::Four_in_a_row(){
    n_rows = 6, n_cols = 7, n_moves = 0;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}
bool Four_in_a_row::update_board(int x, int y, char mark) {
    if (x >= 0 && x < n_rows && y >= 0 && y < n_cols && board[x][y] == 0) {
        n_moves++;
        for (int i = n_rows - 1; i >= 0; --i) {
            if (board[i][y] == 0) {
                board[i][y] = toupper(mark);
                return true;
            }
        }
    }
    return false;
}


void Four_in_a_row::display_board() {
    system("cls");
    for (int i = 0; i < n_rows; ++i) {
        cout << "\n|";
        for (int j = 0; j < n_cols; ++j) {
            char cell = (board[i][j] == 0) ? ' ' : board[i][j];
            cout << "(" << i << "," << j << ")" << setw(2) << cell << " |";
        }
        cout << "\n---------------------------------------------------------";
    }
    cout << '\n';
}

bool Four_in_a_row::is_winner() {
    char x;
    // Check Horizontal
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            x = board[i][j] & board[i][j+1] & board[i][j+2] & board[i][j+3];
            if (x && x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Vertical
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j];
            if (x && x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Diagonal (Right)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            x = board[i][j] & board[i+1][j+1] & board[i+2][j+2] & board[i+3][j+3];
            if (x && x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Diagonal (Left)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 3; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j-1] & board[i+2][j-2] & board[i+3][j-3];
            if (x&& x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    return false;
}

bool Four_in_a_row::is_draw() {
    return (n_moves == n_rows * n_cols && !is_winner());
}

bool Four_in_a_row::game_is_over() {
    return n_moves >= n_rows * n_cols;
}



