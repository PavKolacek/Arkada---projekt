#include <iostream>
#include <string>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char hracX = 'X';
    const char hracO = 'O';
    char hracNaTahu = hracX;
    int r = 0;
    int c = 0;
    char winner = ' ';

    for (int i = 0; i < 9; i++) {

        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' '){
            break;
        }

        cout << endl << "Na tahu je: " << hracNaTahu << endl;

        if (hracNaTahu == hracX){

            while (true) {
            cout << "Zadejte radek a sloupec (1 - 3): ";
            cin >> r >> c;

            r -= 1;
            c -= 1;

            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Neplatny tah, zkuste to znova!" << endl;
              
                r = c = 0;
            } 
            else if (board[r][c] != ' ') {
                cout << "Pole je zabrane, zkuste to znova!" << endl;
                r = c = 0;
            } 
            else {
                break;
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    else {
        cout << "Pocitac premysli..." <<endl;
        do {
            r = rand() % 3;
            c = rand() % 3;
        }
        while (board[r][c] != ' ');
    }

      
        board[r][c] = hracNaTahu;
        hracNaTahu = (hracNaTahu == hracX) ? hracO : hracX;

        for (int r = 0; r < 3; r++){
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]){
                winner = board[r][0];
                break;
            }
        }
        for (int c = 0; c < 3; c++){
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]){
                winner = board[0][c];
                break;
            }
         }
         if (board[0][0] != ' ' && board [0][0] == board [1][1] && board [1][1] == board [2][2]){
            winner = board [0][0];
         }
         else if (board[0][2] != ' ' && board [0][2] == board [1][1] && board [1][1] == board [2][0])
         {
             winner = board [0][2];
         }
    }

    if (winner != ' '){
        cout << "Hrac " << winner << " je vitez!" <<endl;
    }
    else {
        cout << "Remiza!" <<endl;
    }
    return 0;
}
