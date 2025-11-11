//co dela automat
#include "animace.cpp"
#include "backend_automatu.cpp"

//jednotlive hry 
#include "hadej_cislo.cpp"
#include "magic8.cpp"
#include "snake.cpp"
#include "sortinghat.cpp"
//#include "tic-tac-toe.cpp"

using namespace std;

// ───────────────────────────────────────────────────────────
// MAIN - sem pisu pouze ja (PAVEL)
// ───────────────────────────────────────────────────────────

int main() {
    CelaAnimace();
    backend_automatu();
    return 0;
}
