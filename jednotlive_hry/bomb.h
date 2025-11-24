#pragma once

#include <atomic>
#include <mutex>

extern std::atomic<bool> timeUp;
extern int currentDifficulty;
extern std::mutex coutMutex;

void countdown(int seconds);
void clearScreen();

int showMenu();
void showRules();
int  chooseDifficulty();

bool generatePuzzle(int difficulty);
bool saveChance(int correctWire);
bool defuseBomb(int difficulty);

void startGame(int difficulty);

int bomb();
