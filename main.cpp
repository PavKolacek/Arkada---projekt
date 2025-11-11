// ───────────────
// co dela automat
// ───────────────
#include "fungovani_automatu/animace.cpp"
#include "fungovani_automatu/backend_automatu.cpp"
// ──────────────
// jednotlive hry
// ────────────── 
#include "jednotlive_hry/hadej_cislo.cpp"
#include "jednotlive_hry/magic8.cpp"
#include "jednotlive_hry/snake.cpp"
#include "jednotlive_hry/sortinghat.cpp"
//#include "tic-tac-toe.cpp"

using namespace std;

// ────────────────────────────────
// MAIN - sem pisu pouze ja (PAVEL)
// ────────────────────────────────
int main() {
    CelaAnimace();
   // backend_automatu();
    return 0;
}
