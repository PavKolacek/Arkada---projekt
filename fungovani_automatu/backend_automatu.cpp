#include "../jednotlive_hry/hadej_cislo.h"
#include "../jednotlive_hry/magic8.h"
#include "../jednotlive_hry/snake.h"
#include "../jednotlive_hry/sortinghat.h"
#include "../jednotlive_hry/tic_tac_toe.cpp"
#include "animace.cpp"

int vyber_hry1(){
    int vyberHry;
    std::cin >> vyberHry;

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
        break;
    case 5:
         tic_tac_toe();
    default:
        break;
    }
    return 0;
};



int backend_automatu(){
    vyber_hry1();
    return 0;
}