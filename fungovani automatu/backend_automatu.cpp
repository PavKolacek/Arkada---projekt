#include "backend_automatu.h"
#include "hadej_cislo.cpp"
#include "magic8.cpp"
#include "snake.cpp"
#include "sortinghat.cpp"
//#include "tic-tac-toe.cpp"
int backend_automatu(){
    int vyberHry;
    cin >> vyberHry;

    switch (vyberHry)
    {
    case 1:
        hadej_cislo();
        break;
    case 2:
        magicka8();
        break;
    case 3:
        sorting_hat();
        break;
    case 4:
        snake();
    default:
        break;
    }
}