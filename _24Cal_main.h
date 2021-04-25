#ifndef CAL_H
#define CAL_H

#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>

#include <cstdlib>
#include <iomanip>

#include <chrono>
#include <unistd.h>

#include <string>
#include <vector>

using namespace std;
using namespace chrono;


void PrintCard_ (int number, int suit); 
void typewriter_ (string line, int speed); 
void Show_result (int modechoice, int achievment[5], string name); 
int  Find_order  (char c, string &valid_information, bool &valid_not, bool &finish_not); 
int  Find_order2  (char c, string &valid_information, bool &valid_not, bool &finish_not); 
void Do_Calculation (vector<char> &calculation_operator, int &calculation_operator_length, vector<float> &calculation_number, int &calculation_number_length, char next_operator, string &valid_information, bool &valid_not, bool &finish_not); 

string Valid_Checker2 (string calculation_player, bool &valid_not, string &valid_information, int branket_level); 
void Valid_Checker1 (string &calculation_player, bool &valid_not, string &valid_information, int frequency[13]); 

void PrintNumbers (vector<int> Givennumbers); 
void Startgame_ (int num_numbers, int achievment[4], int rounds, int &current_streak, int question_bank[18556]); 
int Startgame (string playername); 
void Printrules ( ); 
int _24Cal_main (string &playername, int &playerscore); 



#endif

