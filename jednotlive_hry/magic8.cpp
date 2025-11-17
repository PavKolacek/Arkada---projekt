#include <iostream>
#include <cstdlib>
#include "magic8.h"

using namespace std;

int magic8() {

  // Your future is here

  cout << "MAGIC 8-BALL:\n\n";

  srand(time(NULL));

  int answer = rand() % 10;
  
  //cout << answer;

  if (answer == 0) {

    cout << "Je to jisté.\n";

  }
  else if (answer == 1) {

    cout << "Je to rozhodně tak.\n";

  }
  else if (answer == 2) {

    cout << "Bez pochyby.\n";

  }
  else if (answer == 3) {

    cout << "Ano - určitě.\n";

  }
  else if (answer == 4) {

    cout << "Můžeš se na to spolehnout.\n";

  }
  else if (answer == 5) {

    cout << "Jak to vidím já, ano.\n";

  }
  else if (answer == 6) {

    cout << "Nejspíš.\n";

  }
  else if (answer == 7) {

    cout << "Vypadá to dobře.\n";

  }
  else if (answer == 8) {

    cout << "Ano.\n";

  }
  else {
  
  cout << "Velmi pochybné.\n";
  
  }

  return 0;
}