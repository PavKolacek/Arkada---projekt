#include <iostream>
#include <cstdlib>
#include "hadej_cislo.h"
#include "../fungovani_automatu/backend_automatu.h"
#include "../fungovani_automatu/animace.h"

int konec_hry(){
  int co_chce;
  std::cout << "Hra je u konce, co chceš dělat dál:\n";
  std::cout << "1: pro hraní znova \n 2: pro výběr jiné hry \n 3: pro ukončení automatu";
  std::cin >> co_chce;
  switch (co_chce)
  {
  case 1:
    hadej_cislo();
    break;
  case 2:
    vyber_hry1();
    backend_automatu();
    break;

  case 3:
    clearConsole();
    std::cout << "Vrať se zas!";
    break;

  default:
    break;
  }
};


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
        konec_hry();
    } else {
        std::cout << "Špatně! Moje číslo bylo " << number << ".\n";
        konec_hry();
    }

    return 0;
}