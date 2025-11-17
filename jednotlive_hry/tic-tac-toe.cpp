#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int lines[8][3][2] = {
    {{0,0}, {0,1}, {0,2}},
    {{1,0}, {1,1}, {1,2}},
    {{2,0}, {2,1}, {2,2}},
    {{0,0}, {1,0}, {2,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,2}, {1,2}, {2,2}},
    {{0,0}, {1,1}, {2,2}},
    {{0,2}, {1,1}, {2,0}}
};

void tahPocitace(char board[3][3], int &r, int &c, char hracX, char hracO) {

    for (int i = 0; i < 8; i++) {
        int xr = -1, xc = -1;
        int countO = 0;

        for (int j = 0; j < 3; j++) {
            int rr = lines[i][j][0];
            int cc = lines[i][j][1];
            if (board[rr][cc] == hracO)
                countO++;
            else if (board[rr][cc] == ' ')
                xr = rr, xc = cc;
        }

        if (countO == 2 && xr != -1) {
            r = xr; c = xc;
            return;
        }
    }

    for (int i = 0; i < 8; i++) {
        int xr = -1, xc = -1;
        int countX = 0;

        for (int j = 0; j < 3; j++) {
            int rr = lines[i][j][0];
            int cc = lines[i][j][1];
            if (board[rr][cc] == hracX)
                countX++;
            else if (board[rr][cc] == ' ')
                xr = rr, xc = cc;
        }

        if (countX == 2 && xr != -1) {
            r = xr; c = xc;
            return;
        }
    }

    do {
        r = rand() % 3;
        c = rand() % 3;
    } while (board[r][c] != ' ');
}

int main() {
    srand((unsigned)time(0));

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char hracX = 'X';
    const char hracO = 'O';
    char hracNaTahu = hracX;
    char winner = ' ';
    int r, c;        
    int moznosti;  

    for (int tah = 0; tah < 9; tah++) {

        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ')
            break;

        cout << endl << "Na tahu je: " << hracNaTahu << endl;

        if (hracNaTahu == hracX) {

            while (true) {
                cout << "Zadejte radek a sloupec (1 - 3): ";
                cin >> r >> c;

                r -= 1;
                c -= 1;

                if (r < 0 || r > 2 || c < 0 || c > 2)
                    cout << "Neplatny tah, zkuste to znova!" << endl;
                else if (board[r][c] != ' ')
                    cout << "Pole je zabrane, zkuste to znova!" << endl;
                else
                    break;

                cin.clear();
                cin.ignore(10000, '\n');
            }

            board[r][c] = hracX;

        } else {

            cout << "Pocitac premysli..." << endl;

            tahPocitace(board, r, c, hracX, hracO);

            board[r][c] = hracO;
        }

        hracNaTahu = (hracNaTahu == hracX ? hracO : hracX);

        for (int i = 0; i < 3; i++)
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                winner = board[i][0];

        for (int i = 0; i < 3; i++)
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                winner = board[0][i];

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            winner = board[0][0];

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            winner = board[0][2];
    }

    if (winner != ' ')
        cout << "Hrac " << winner << " je vitez!" << endl;
    else
        cout << "Remiza!" << endl;

    return 0;
}
