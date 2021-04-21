#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include <limits>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <fstream>

using namespace std;

void typewriter(string line, int speed);
void PrintCard(int number, int suit);
void PrintHand(vector<int> PlayerPile);
bool ValidChecker(int &card, int firstcard);
bool AI (int& firstcard, vector<int>& aiPile, string AI_id);
int StartGame(int numofai, string name, int achievment[3]);
void show_result (int numofai, int achievment[3], string name);
void PrintRules();
int unomain (string name, int &playerscore);


#endif
