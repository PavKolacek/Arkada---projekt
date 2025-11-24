#include "../jednotlive_hry/hadej_cislo.h"
#include "../jednotlive_hry/magic8.h"
#include "../jednotlive_hry/snake.h"
#include "../jednotlive_hry/sortinghat.h"
#include "../jednotlive_hry/knp.h"
#include "../jednotlive_hry/tic_tac_toe.h"
#include "../jednotlive_hry/sibenice.h"
#include "../jednotlive_hry/sherlock.h"
#include "../jednotlive_hry/bomb.h"
#include "backend_automatu.h"
#include "animace.h"
#include <iostream>

int vyber_hry1(){
    int vyberHry;
    std::cin >> vyberHry;
    switch (vyberHry)
    {
    case 1:
        hadej_cislo();
        break;
    case 2:
        //magic8();
        break;
    case 3:
        sorting_hat();
        break;
    case 4:
        snake();
        break;
    case 5:
         tic_tac_toe();
         break;
    case 6:
        knp();
        break;
    case 7:
        sibenice();
        break;
    case 8:
        sherlock();
        break;
    case 9:
        bomb();
        break;
    default:
        break;
    }
    return 0;
};



int backend_automatu(){
    vyber_hry1();
    return 0;
}