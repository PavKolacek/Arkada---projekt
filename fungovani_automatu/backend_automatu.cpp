#include "../backend_automatu.h"
#include "../jednotlive_hry/hadej_cislo.h"
#include "../jednotlive_hry/magic8.h"
#include "../jednotlive_hry/snake.h"
#include "../jednotlive_hry/sortinghat.h"
//#include "tic-tac-toe.cpp"

#pragma once

int backend_automatu(){
    int vyberHry;
    cin >> vyberHry;

    switch (vyberHry)
    {
    case 1:
        hadej_cislo();
        break;
    case 2:
        magic8();
        break;
    case 3:
        sorting_hat();
        break;
    case 4:
        snake();
    default:
        break;
    }
    return 0;
}