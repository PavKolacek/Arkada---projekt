#include <iostream>
#include <cstdlib>
#include "hadej_cislo.h"
#include "../fungovani_automatu/backend_automatu.h"
#include "../fungovani_automatu/animace.h"

int konec_hry1(){
    int rozhodnuti;
    std::cout << "Hra je u konce" << std::endl << "1 -> Hrát znovu\n2-> Chci hrát něco jiného\n 3-> Ukončit a vypnout automat";
    std::cin >> rozhodnuti;
    switch (rozhodnuti)
    {
    case 1:
        hadej_cislo();
        break;
    case 2:
        vyber_hry_animace();
        vyber_hry1();
        break;
    case 3:
        vypnuti();
    default:
        break;
    }
    return 0;
}

int hadej_cislo(){
    // Hádej číslo
    
    //int number;
    int guess;
    
    std::cout << "Vítej ve hře Hádej číslo!\n";
    std::cout << "Myslím si číslo mezi 1 a 10. Zkus to uhodnout: ";
    std::cin >> guess;

    srand(time(NULL));
    int number = std::rand() % 10;
  
  //std::cout << answer;

  if (number == 0) {

    number = 1;

  }
  else if (number == 1) {

    number = 2;

  }
  else if (number == 2) {

    number = 3;

  }
  else if (number == 3) {

    number = 4;

  }
  else if (number == 4) {

    number = 5;

  }
  else if (number == 5) {

    number = 6;

  }
  else if (number == 6) {

    number = 7;

  }
  else if (number == 7) {

    number = 8;

  }
  else if (number == 8) {

    number = 9;

  }
  else {
  
  number = 10;
  
  }

    if(guess == number){
        std::cout << "Gratuluji! Uhodl jsi mé číslo.\n";
    } else {
        std::cout << "Špatně! Moje číslo bylo " << number << ".\n";
    }
    konec_hry1();
    return 0;
}