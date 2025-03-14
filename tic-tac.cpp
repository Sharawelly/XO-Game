#include <iostream>
#include <string>
#include "BoardGame_Classes.h"
#include "Four_in_a_row.h"
#include "Pyramid.h"
#include "X_O_5.h"
using namespace std;
int main() {
    char choose = 'y';
    cout << "Hello, ya ma3llem!\n";

    while (choose != '0') {
        cout << "Enter your name:\n";
        Player* players[2];
         players[0] = new Player(1, 'O');

        cout << "If you're alone, choose 1.\n";
        char c;
        cin >> c;

        if (c == '1') {
            cout << "Choose a game:\n"
                    "1) Pyramid\n"
                    "2) Four-in-a-row\n"
                    "3) 5 x 5 Tic Tac Toe\n"
                    "4) original X_O\n";
            int gameChoice;
            cin >> gameChoice;

            GameManager* gameManager = nullptr;
            Board* gameBoard = nullptr;



            switch (gameChoice) {
                case 1:
                    gameBoard = new pyramid();
                    players[1] = new RandomPlayer('X', 5);
                    break;
                case 2:
                    gameBoard = new Four_in_a_row();
                    players[1] = new RandomPlayer('X',7 );
                    break;
                case 3:
                    gameBoard = new FiveByFiveBoard();
                    players[1] = new RandomPlayer('X', 5);
                    break;
                case 4:
                    gameBoard=new X_O_Board();
                    players[1] = new RandomPlayer('X', 3);
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }

            if (gameBoard != nullptr) {
                gameManager = new GameManager(gameBoard,players );
                gameManager->run();
            }
        } else {
            cout << "Enter your name:\n";
             players[1] = new Player(2, 'X');

            cout << "Choose a game:\n"
                    "1) Pyramid\n"
                    "2) Four-in-a-row\n"
                    "3) 5 x 5 Tic Tac Toe\n"
                    "4) original X_O\n";;
            int gameChoice;
            cin >> gameChoice;

            GameManager* gameManager = nullptr;
            Board* gameBoard = nullptr;

            switch (gameChoice) {
                case 1:
                    gameBoard = new pyramid();
                    break;
                case 2:
                    gameBoard = new Four_in_a_row();
                    break;
                case 3:
                    gameBoard = new FiveByFiveBoard();
                    break;
                case 4:
                    gameBoard=new X_O_Board();

                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }

            if (gameBoard != nullptr) {
                gameManager = new GameManager(gameBoard,players );
                gameManager->run();
            }
        }
        cout<<"if you want exist press 0\n";cin>>c;
    }

    return 0;
}
