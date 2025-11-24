#pragma once

#include <atomic>
#include <string>

// ====== Globální proměnné ======
extern std::atomic<bool> timeUp;
extern int currentDifficulty;

// ====== Funkce ======

// časování a UI
void countdown(int seconds);
void clearScreen();

// menu
int showMenu();
void showRules();
int chooseDifficulty();

// logika hry
bool generatePuzzle(int difficulty);
bool saveChance(int correctWire);
bool defuseBomb(int difficulty);
void startGame(int difficulty);

// hlavní vstup do hry
int bomb();

