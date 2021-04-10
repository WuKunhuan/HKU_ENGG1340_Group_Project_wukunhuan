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
#include <sstream>

using namespace std;

void PrintCard(int number, int suit);
void PrintHand(vector<int> PlayerPile);
bool ValidChecker(int &card, int firstcard);
bool AI(int &firstcard, vector<int>& aiPile);
int StartGame(int numofai);
void PrintRules();
int unomain(string name, int &playerscore);


#endif
