// kamen,nuzky,papir.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "../fungovani_automatu/backend_automatu.h"
#include "../fungovani_automatu/animace.h"
#include "knp.h"

using namespace std;

int konec_hry2(){
    int rozhodnuti;
    std::cout << "Hra je u konce" << endl << "1 -> Hrát znovu\n2-> Chci hrát něco jiného\n 3-> Ukončit a vypnout automat";
    std::cin >> rozhodnuti;
    switch (rozhodnuti)
    {
    case 1:
        knp();
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

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}


void Proti_hraci() {
	int user1, user2;

		cout << "Zadej volbu:" << endl << "1. Kámen" << endl << "2. Nůžky" << endl << "3. Papír" << endl;
		cin >> user1;

		clearScreen();

		cout << "Zadej volbu:" << endl << "1. Kámen" << endl << "2. Nůžky" << endl << "3. Papír" << endl;
		cin >> user2;

		if (user1 == 1) {
			cout << "User1 volba: Kamen" << endl;
		}
		if (user1 == 2) {
			cout << "User1 volba: Nuzky" << endl;
		}
		if (user1 == 3) {
			cout << "User1 volba: Papir" << endl;
		}

		if (user2 == 1) {
			cout << "User2 volba: Kamen" << endl;
		}
		if (user2 == 2) {
			cout << "User2 volba: Nuzky" << endl;
		}
		if (user2 == 3) {
			cout << "User2 volba: Papir" << endl;
		}


		if (user1 == 1) {
			if (user2 == 2) {
				cout << "Vyhral User1!" << endl << endl;
			}
			if (user2 == 3) {
				cout << "Vyhral User2!" << endl << endl;
			}
			if (user2 == 1) {
				cout << "Remiza!" << endl << endl;
			}
			konec_hry2();
		}
		if (user1 == 2) {
			if (user2 == 3) {
				cout << "Vyhral User1!" << endl << endl;
			}
			if (user2 == 1) {
				cout << "Vyhral User2!" << endl << endl;
			}
			if (user2 == 2) {
				cout << "Remiza!" << endl << endl;
			}
			konec_hry2();
		}
		if (user1 == 3) {
			if (user2 == 2) {
				cout << "Vyhral User2!" << endl << endl;
			}
			if (user2 == 1) {
				cout << "Vyhral User1!" << endl << endl;
			}
			if (user2 == 3) {
				cout << "Remiza!" << endl << endl;
			}
			konec_hry2();
		}

	


}
void Proti_pocitaci() {
	int volba, random;

	do {
		srand(time(0));

		cout << "Zadej volbu:" << endl << "1. Kámen" << endl << "2. Nůžky" << endl << "3. Papír" << endl;
		cin >> volba;

		random = rand() % 3 + 1;


		if (volba == 1) {
			cout << "Tvoje volba: Kamen"<< endl;
		}
		if (volba == 2) {
			cout << "Tvoje volba: Nuzky" << endl;
		}
		if (volba == 3) {
			cout << "Tvoje volba: Papir" << endl;
		}

		

		if (volba == 1) {
			if (random == 2) {
				cout << "Volba pocitace: Nuzky" << endl;
				cout << "Vyhral jsi!" << endl << endl;
			}
			if (random == 3) {
				cout << "Volba pocitace: Papir"<< endl;
				cout << "Prohral jsi!" << endl << endl;
			}
			if (random == 1) {
				cout << "Volba pocitace: Kamen" << endl;
				cout << "Remiza!"<<endl << endl;
			}
			konec_hry2();
		}
		if (volba == 2) {
			if (random == 3) {
				cout << "Volba pocitace: Papir" << endl;
				cout << "Vyhral jsi!" << endl << endl;
			}
			if (random == 1) {
				cout << "Volba počítače: Kamen" << endl;
				cout << "Prohral jsi!" << endl << endl;
			}
			if (random == 2) {
				cout << "Volba pocitace: Nuzky" << endl;
				cout << "Remiza!"<<endl << endl;
			}
			konec_hry2();
		}
		if (volba == 3) {
			if (random == 2) {
				cout << "Volba pocitace: Nuzky" << endl;
				cout << "Prohral jsi!" << endl << endl;
			}
			if (random == 1) {
				cout << "Volba počítače: Kamen" << endl;
				cout << "Vyhral jsi!" << endl << endl;
			}
			if (random == 3) {
				cout << "Volba pocitace: Papir" << endl;
				cout << "Remiza!" << endl << endl;
			}
			konec_hry2();
		}

	} while (volba == random);

}

int knp()
{
	string user, computer, user2;
	int volba;

	

	do {
	cout << "Hra Kamen, Nuzky, Papir" << endl<<endl;

	cout << "Vyber si proti komu chces hrat:" << endl;
	cout << "1 - proti pocitaci" << endl;
	cout << "2 - proti druhemu hraci" << endl;
	cout << "0 - Konec"	<< endl;
	cin >> volba;

	
		switch (volba) {
	
		case 1:
			cout << "Hrajete proti pocitaci." << endl;
			Proti_pocitaci();
			break;
		case 2:
			cout << "Hrajete proti druhemu hraci." << endl;
			Proti_hraci();
			break;
		}
	} while (volba != 0);

	return 0;
}

