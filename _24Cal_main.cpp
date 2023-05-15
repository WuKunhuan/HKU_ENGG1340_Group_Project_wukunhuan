//  Author:       Wu Kunhuan  (3035771634)
//  Description:  Implementation of 24 calculation game.
//                All Functions needed for this game is in this c++ code.

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

//  Header files (system equipped)


#include "_24Cal_main.h"
//  Header files (user-writtem)

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

//  Define the suit characters for the poker cards

using namespace std;
using namespace chrono;

void PrintCard_  (int number, int suit) {

    switch (number) {
        case 0: cout << "A"; break;
        case 1: cout << "2"; break;
        case 2: cout << "3"; break;
        case 3: cout << "4"; break;
        case 4: cout << "5"; break;
        case 5: cout << "6"; break;
        case 6: cout << "7"; break;
        case 7: cout << "8"; break;
        case 8: cout << "9"; break;
        case 9: cout << "10"; break;
        case 10: cout << "J"; break;
        case 11: cout << "Q"; break;
        case 12: cout << "K"; break;
}

    switch (suit) {
        case 0: cout << SPADE; break;
        case 1: cout << HEART; break;
        case 2: cout << CLUB; break;
        case 3: cout << DIAMOND; break;
    }
    typewriter_ (" ", 1000000);
}


//  Prints out the cards in a single question, in a card-by-card manner. The switch function will automatically convert the input card id (range from 0 to 51) into the the formant of poker suit + poker rank, for example card with the id 0 will be converted into A\u2660.
//  Prints out the cards in a single question, in a card-by-card manner.
//  Input: Card information
//  Output: Screenoutput of the card icon

void typewriter_ (string line, int speed) {
    for (int i = 0; i < line.length(); i++) {
        cout << line[i];
        cout.flush();
        usleep (speed);
    }
}
//  Print out like a typewriter
//  Takes in string line and output speed
//  Input: a line of word
//  Output: Screenoutput of that line

void Show_result (int modechoice, int achievment[5], string name) {

    system ("clear");

    string _scoreboard_line = "Here is " + name + "'s scoreboard for this round: ";
    typewriter_ (_scoreboard_line, 100000);
    usleep (1000000);

    cout << endl;
    cout << " ========================================================== "                                                      << endl;
    cout << "||"
         << "                    24_Calculation                      "
         << "||" << endl;
    cout << "||"
         << "                                                        "
         << "||" << endl;
    cout << "||" << setw(20) << "  Game Mode: "       << setw(16) << "Calculate " << modechoice << " numbers"   << "           " << "||" << endl;
    cout << "||" << setw(20) << "  Correct #: "       << setw(16) << achievment[1]                           << "                    " << "||" << endl;
    cout << "||" << setw(20) << "  Time: "            << setw(12) << achievment[2] << setw(4) << " ms"       << "                    " << "||" << endl;
    cout << "||" << setw(20) << "  Max.streak: "      << setw(16) << achievment[3]                           << "                    " << "||" << endl;

    if (achievment[4] == 100000000) {
    cout << "||" << setw(20) << "  Min.time: "        << setw(16) << "No attempt"                            << "                    " << "||" << endl;
    }
    else {
    cout << "||" << setw(20) << "  Min.time: "        << setw(12) << achievment[4] << setw(4) << " ms"       << "                    " << "||" << endl;
    }
    cout << "||" << "                                                        "                                                         << "||"    << endl;
    int    score_rank  [12] = { 75,  68,  60,  55,  50,  45,  40,  35,  30,  22,  15,  0  };
    string rank_letter [12] = {"A+",  "A", "A-", "B+",  "B", "B-", "C+",  "C", "C-", "D+",  "D", "F" };

//  Find the correspoinding rank of the player based on its score with a while loop/

    int rank = 0;
    for (rank = 0; rank < 12; rank ++) { if (achievment[0] >= score_rank[rank]) {break; } }
    cout << "||" << setw(20) << "  Overall Score: "   << setw(16) << achievment[0]     << "                    " << "||" << endl;
    cout << "||" << setw(20) << "  Overall Grade: "   << setw(16) << rank_letter[rank] << "                    " << "||" << endl;
    cout << " ========================================================== "                                                      << endl;


    ofstream fout;
    fout.open(" [Game result]  " + name + ".txt", ios::app);
    fout << " ========================================================== "      << endl;
    fout << "||" << "                    24_Calculation                      " << "||" << endl;
    fout << "||" << "                                                        " << "||" << endl;
    fout << "||" << setw(20) << "  Game Mode: "       << setw(16) << "Calculate " << modechoice << " numbers"   << "           " << "||" << endl;
    fout << "||" << setw(20) << "  Correct #: "       << setw(16) << achievment[1]                           << "                    " << "||" << endl;
    fout << "||" << setw(20) << "  Time: "            << setw(12) << achievment[2] << setw(4) << " ms"       << "                    " << "||" << endl;
    fout << "||" << setw(20) << "  Max.streak: "      << setw(16) << achievment[3]                           << "                    " << "||" << endl;

    if (achievment[4] == 100000000) {
    fout << "||" << setw(20) << "  Min.time: "        << setw(16) << "No attempt"                            << "                    " << "||" << endl;
    }
    else {
    fout << "||" << setw(20) << "  Min.time: "        << setw(12) << achievment[4] << setw(4) << " ms"       << "                    " << "||" << endl;
    }
    fout << "||" << "                                                        "                                                         << "||"    << endl;
    fout << "||" << setw(20) << "  Overall Score: "   << setw(16) << achievment[0]     << "                    " << "||" << endl;
    fout << "||" << setw(20) << "  Overall Grade: "   << setw(16) << rank_letter[rank] << "                    " << "||" << endl;
    fout << " ========================================================== "      << endl;
    fout << endl << endl;
    fout.close();


    cout << "Enter anything to end this round...   ";
    string _enter; getline (cin, _enter);
    cout << endl << endl;





}

//  After each round of the game, printing out the game scoreboard for the reference of users.
//  At the same time, have the file output for this round ready.
//  Input: Game statistics
//  Output: Screenoutput of the scoreboard

int  Find_order  (char c, string &valid_information, bool &valid_not, bool &finish_not) {
    int  order;
    switch (c) {
        case ';':         order = 0;  break;
        case '(':         order = 8;  break;
        case '*':         order = 4;  break;
        case '/':         order = 4;  break;
        case '+':         order = 2;  break;
        case '-':         order = 2;  break;
        case ')':         order = 1;  break;
        default:
            stringstream _char_string;
            string _c;
            _char_string << c;
            _char_string >> _c;
            valid_information = "Oh no, there are invalid characters in the expression! Error: " + _c;
            valid_not = false;
            finish_not = true;
            order = -1;
        }
    return  order;
}

int  Find_order2  (char c, string &valid_information, bool &valid_not, bool &finish_not) {
    int  order;
    switch (c) {
        case ';':         order = 0;  break;
        case '(':         order = 1;  break;
        case '*':         order = 5;  break;
        case '/':         order = 5;  break;
        case '+':         order = 3;  break;
        case '-':         order = 3;  break;
        case ')':         order = 8;  break;
        default:
            stringstream _char_string;
            string _c;
            _char_string << c;
            _char_string >> _c;
            valid_information = "Oh no, there are invalid characters in the expression! Error: " + _c;
            valid_not = false;
            finish_not = true;
            order = -1;
        }
    return  order;
}

//  These 2 "find order" functions are used to compare different operators so as to correctly calculate the expression.
//  Input: An operator, valid information
//  Output: The order of that operator, possible changes in the valid information (pass by reference)

void Do_Calculation (vector<char> &calculation_operator, int &calculation_operator_length, 
    vector<float> &calculation_number, int &calculation_number_length, char next_operator, string &valid_information, bool &valid_not, bool &finish_not) {

    if (valid_not && calculation_number_length == 1 && !(calculation_operator.size() == 1 && calculation_operator[0] == ';')) {
        // cout << endl; 
        // for (int i = 0; i < calculation_operator.size(); i++) {
        //     cout << calculation_operator[i]; 
        // } cout << endl; 
        valid_information = "There are too many operators in the expression! "; valid_not = false; finish_not = true; return; 
    }

    char top_operator = calculation_operator.back();

    if (top_operator == '+') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum + firstnum;
        cout << "Addition: " << secondnum << " + " << firstnum << " = " << result  << endl; usleep(1000000);
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

//  Pop back the last 2 stored float numbers, and the last 1 stored operator from the vector, to do the addition, then push the result float back to the vector.
//  Screen outputing the calculation process.

    if (top_operator == '-') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum - firstnum;
        cout << "Subtraction: " << secondnum << " - " << firstnum << " = " << result  << endl; usleep(1000000);
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

//  Pop back the last 2 stored float numbers, and the last 1 stored operator from the vector, to do the subtraction, then push the result float back to the vector.
//  Screen outputing the calculation process.

    if (top_operator == '*') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum * firstnum;
        cout << "Multiplicaton: " << secondnum << " * " << firstnum << " = " << result  << endl; usleep(1000000);
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

//  Pop back the last 2 stored float numbers, and the last 1 stored operator from the vector, to do the multiplication, then push the result float back to the vector.
//  Screen outputing the calculation process.

    if (top_operator == '/') {
        float firstnum = calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        if (firstnum == 0)  {
            valid_information = "0 can't be the divisor in the calculation! Wrong :( ";
            valid_not = false;
            finish_not = true;
        }
        else {
            float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
            float result                  =      secondnum / firstnum;
            cout << "Division: " << secondnum << " / " << firstnum << " = " << result  << endl; usleep(1000000);
            calculation_number.push_back (result);  calculation_number_length += 1;
            calculation_operator.pop_back();  calculation_operator_length -= 1;
        }
    }

    //  Pop back the last 2 stored float numbers, and the last 1 stored operator from the vector, to do the division, then push the result float back to the vector.
    //  0 can't be the divisor in the calculation
    //  Screen outputing the calculation process.

    if (calculation_number.back() < 0 && valid_not) {valid_information = "Sorry, please get rid of negative numbers in the calculation! "; valid_not = false; finish_not = true; cout << "Negative numbers detected! " << endl; }

    //  Get rid of negative numbers in the calculation, otherwise the operators stored in the later stage will be in a mess.

    if (next_operator != ';' ) {calculation_operator.push_back (next_operator);   calculation_operator_length += 1; }

}

//  This function is used to carry the calculation with provided operators and numbers previously stored in the vectors.
//  Input: Stored operator and number vectors, valid information
//  Output: Do the calculation and change the operators and numbers stored, possible changes in the valid information (pass by reference)

string Valid_Checker2 (string calculation_player, bool &valid_not, string &valid_information, int branket_level) {

    if (valid_not) {

        float result = 0; bool finish_not = false;
        int pointer_i = 0, pointer_j = 0;                //  Used for expression substring substitution
        vector<char> calculation_operator; vector<float> calculation_number;       //  Vectors to store the numbers and operators.
        int calculation_operator_length = 0; int calculation_number_length = 0;    //  Those 2 variables can be replaced by vector.size(), just for security concern of vector size overloading, which will mess the size up.
        float current_number = 0;    //  Temporaily store the number detected in the input expression from the user
        string _current_number = ""; string calculation_player_new = "";

        int i = 0;
        calculation_player += ";" ;    //  Indicates the end of the expression
        calculation_operator.push_back (';'); calculation_operator_length += 1;

//  Initialize the variables that are required for the checking of the equation.

        while (i < calculation_player.length() && valid_not && !finish_not) {

            current_number = 0; _current_number =  "";

            while (calculation_player [i] >= 48 && calculation_player [i] <= 57 || calculation_player [i] == 46)  {
                _current_number += calculation_player [i];
                current_number = 1; i++; pointer_j++;
            }
//  Find the input numbers and substitute it into the 4-digit float number form.

            if  (current_number != 0)  {
                stringstream _string_float;
                _string_float << _current_number; _string_float >> current_number;
                calculation_number.push_back (current_number); calculation_number_length += 1;
                stringstream _float_string; string _string = "";
                _float_string << fixed <<  setprecision(4) << calculation_number.back();
                _float_string >> _string; calculation_player_new += _string;
                pointer_j += _string.length() - _current_number.length();
            }

            else {
                int a = Find_order   (calculation_player [i] , valid_information, valid_not, finish_not);
                int b = Find_order2  (calculation_operator.back(), valid_information, valid_not, finish_not);

//  When it comes to the operators in the expression, determine whether to carry on the previous operator stored.
//  For example, 3 + 2 * 5 - 6, when detecting the "*" operator in the expression, comparing the order of * and the previous operator stored (i.e. +) to figure out whether to calculate "3 + 2" and replace the substring with the result 5.
//  In this case, the conclusion should be no since the order of * is higher. And then, we push * back to the operation vector's end.
//  However, when detecting the "-" operator in the expression, since the order of - is lower than previous operator *, we can replace the substring 2 * 5 into 10 directly and it will not change the result of the expression.
//  pointer_i, pointer_j indicates the start and the digits of the proposed replacing substring. For example, when replacing 2*5 in the 3+2*5-6, pointer_i should be 2 (start index is 2) and pointer_j should be 3 (length of the substring to be replaced is 3).


                if (a == 8) {

                    string _sub_calculation = "";
                    int sub_i = i;
                    int sub_j = sub_i + 1;
                    int _branket_level = 1;

                    while (_branket_level > 0) {
                        _sub_calculation += calculation_player [sub_j];
                        if (calculation_player [sub_j] == '(') {_branket_level += 1; }
                        sub_j++;
                        if (calculation_player [sub_j] == ')') {_branket_level -= 1; }
                    }

                    string _substitution = "";
                    _substitution = Valid_Checker2 (_sub_calculation, valid_not, valid_information, branket_level + 1);  // Recursion
                    calculation_player.replace (sub_i, sub_j - sub_i + 1, _substitution);

//  When the operator detected is "(", using the recursion to replace the whole branket to a single float number. Note that the more layers the brankets are, the more recursion times under the previous recursion call will be incurred.
//  For example, when dealing with 3 + (2 * (5 + 4)) - 6, we will replace (2 * (5 + 4)) into a single float number. Then under this recursion (input expression is "2 * (5 + 4)"), we will replace (5 + 4) into a single float number 9, then we can replace (2 * 9) into 18 and return back one layer by one layer.
//  Finally calculate 3 + 18 - 6, which will give us 15.
                }

                else {
                    if (a > b && valid_not)  {
                        char _top = calculation_player [i]; calculation_operator.push_back(_top); calculation_operator_length += 1;
                        i++; pointer_j++; calculation_player_new += _top;

                        if (calculation_operator_length != 2) {
                            stringstream _float_string; string _string = "";
                            _float_string << fixed <<  setprecision(4) << calculation_number [calculation_number_length - 2];
                            _float_string >> _string;
                            pointer_i += (_string.length() + 1);
                            pointer_j -= (_string.length() + 1);
                        }
                    }

//  If the order of the detected operator is higher than the last operator in the string vector, push back the detected operator (except for brankets, which will goes into the recursion)

                    else {
                        Do_Calculation (calculation_operator, calculation_operator_length, calculation_number, calculation_number_length, calculation_player[i], valid_information, valid_not, finish_not);

                        if (valid_not) {
                            calculation_player_new += calculation_player[i]; i++;
                            stringstream _floatprecision2_string; string _string = "";
                            _floatprecision2_string << fixed <<  setprecision(4) << calculation_number.back(); _floatprecision2_string >> _string;
                            calculation_player_new.replace (pointer_i, pointer_j, _string);
                            pointer_j = _string.length() + 1;
                        }
                    }
//  Reversely, if the order of the detected operator is lower than the last operator in the operator vector,
//  do the calculation with the last operator stored in the operator vector and last 2 numbers stored in the number vector. (except for brankets, which will goes into the recursion)

                }
            }

            if (i == calculation_player.length() && calculation_number_length != 1 && valid_not) {
                i--;
                stringstream _float_string; string _string = "";
                _float_string << fixed <<  setprecision(4) << calculation_number [calculation_number_length - 2];
                _float_string >> _string;
                pointer_i -= (_string.length() + 1);
                pointer_j += (_string.length() + 1);
            }
        }

        if (calculation_number_length <= 1 && branket_level == 0 && valid_not) {
            //  Find out whether the result is 24 provided the expression has no problems when there is only 1 remaining number in the number vector.
            if (23.99 < calculation_number.back() && calculation_number.back() < 24.01 ) {
                //  Give a 0.01 tolarance for the calculation result considering the floating effect
                if (calculation_number_length <= 1 && calculation_operator.back() == ';') {
                    if (valid_not) {
                        valid_information = "You got it! Well done! "; valid_not = true; finish_not = true; }}
                else {
                    if (valid_not) {
                        valid_information = "There are too many operators in the expression! "; valid_not = false; finish_not = true; }}
            }

            else {
                if (valid_not == true) {
                    stringstream result;
                    result << calculation_number.back();
                    string _result;
                    result >> _result;
                    valid_information = "Emm... The result is " + _result + " but not 24  :( "; valid_not = false; finish_not = true; }
            }
        }


        if (valid_not) {calculation_player = calculation_player_new.erase (calculation_player_new.length() - 1, 1); }
//  Erase the ";" added to the expression in the beginning after a single recursion loop
    }

    if (valid_not) {return calculation_player; }
    else {return "error"; }
}
//  This part is used to further check the calculation expression.
//  Input: The modified calculation string of the player, valid information
//  Output: The resulted calculation string of the player (result in 1 single float numbers if all right), possible changes in the valid information (pass by reference)

void Valid_Checker1 (string &calculation_player, bool &valid_not, string &valid_information, int frequency[13]) {


    valid_not = true;
    bool finish_not = false;
    string calculation_player_2 = "";
    int i = 0;

    if (calculation_player.length() == 0) {
        if (valid_not) {valid_information = "You haven't enter anything! ";  valid_not = false; return; }
    }
    if (calculation_player.length() > 30) {
        if (valid_not) {valid_information = "Sorry, the expression you have entered is too long! (max. 30 characters) "; valid_not = false; return; }
    }

    int brankets = 0;
    i = 0;

    while (i < calculation_player.length() && valid_not) {

        while (calculation_player[i] == ' ')  {calculation_player.erase(i, 1);}

        if (brankets < 0) {
            if (valid_not) {valid_information = "Your expression has grammar mistakes! Error: Branket_level < 0";  valid_not = false; return; }
        }

        else if (     (calculation_player [i] == '+' || calculation_player [i] == '-' || calculation_player [i] == '*' || calculation_player [i] == '/' || calculation_player [i] == '(' || calculation_player [i] == ')' || calculation_player [i] == 46 || (calculation_player [i] >= 48 && calculation_player [i] <= 57)) == false)    {
            if (valid_not) {valid_information = "You have entered invalid operators! "; valid_not = false; return; }
        }

        else if (   ( (calculation_player [i]   == '+' || calculation_player [i]   == '-' || calculation_player [i]   == '*' || calculation_player [i]   == '/')  == true   &&
                      (calculation_player [i+1] == '+' || calculation_player [i+1] == '-' || calculation_player [i+1] == '*' || calculation_player [i+1] == '/')  == true ) ||
                    ( (calculation_player [i]   == ')' && calculation_player [i]   == '(') ||
                      (calculation_player [i]   == '(' && calculation_player [i]   == ')')        )  )  {
            if (valid_not) {valid_information = "Sorry, your expression has grammar mistakes! Error: Operators connect together"; valid_not = false; return; }
        }

        else {
            string _current_number = "";
            float current_number = 0;
            while (calculation_player [i] >= 48 && calculation_player [i] <= 57 || calculation_player [i] == 46)  {
                _current_number += calculation_player [i];
                current_number = 1; i++;
            }

            if  (current_number != 0)  {
                stringstream _string_floatprecision2;
                _string_floatprecision2 << fixed <<  setprecision(4) << _current_number;
                _string_floatprecision2 >> current_number;
                vector<float> calculation_number;
                calculation_number.push_back (current_number);

                frequency [(int)current_number - 1] -= 1;

                stringstream _floatprecision4_string;
                string _string = "";
                _floatprecision4_string << fixed <<  setprecision(4) << calculation_number.back();
                _floatprecision4_string >> _string;
                calculation_player_2 += _string;
            }
            else {
                if (calculation_player [i] == '(') {brankets += 1; }
                if (calculation_player [i] == ')') {brankets -= 1; }
                calculation_player_2 += calculation_player [i]; i++; }
        }
    }


    if (brankets != 0) {
        if (valid_not) {valid_information = "Amount of '(' and ')' is not equal! "; valid_not = false; return; }
    }

    for (i = 0; i < 13; i++) {
        if (frequency [i] != 0) {
            if (valid_not) {valid_information = "You haven't use the given numbers! Please use all of them exactly once"; valid_not = false; return; }
        }
    }

    if (valid_not) {calculation_player = calculation_player_2; }
}

//  This part is used to pre-detect any obvious problems in the expression (filter them out) while adapting the integer numbers into float numbers,
//  for the use in the later Valid_Checker 2 function (pay more attention with the calculation judgement).
//  Input: The calculation string of the player, valid information
//  Output: The modified calculation string of the player (result in 1 single float numbers if all right), possible changes in the valid information (pass by reference)

void PrintNumbers (vector<int> Givennumbers){

    if      (Givennumbers.size() == 4)    {cout << "||"; typewriter_  ("     Given numbers:             ", 100000); }
    else if (Givennumbers.size() == 5)    {cout << "||"; typewriter_  ("     Given numbers:         ",     100000); }
    else if (Givennumbers.size() == 6)    {cout << "||"; typewriter_  ("     Given numbers:     ",         100000); }
    int count = 0;

    for (int i = 0; i < Givennumbers.size(); i++) {
        cout << setw (3);
        PrintCard_ (Givennumbers[i] % 13, Givennumbers[i] / 13);
    }
    if      (Givennumbers.size() == 4)    {cout << "    " << "||" << endl; }
    else if (Givennumbers.size() == 5)    {cout << "   "  << "||" << endl; }
    else if (Givennumbers.size() == 6)    {cout << "  "   << "||" << endl; }
}

//  Print the numbers given in the question.
//  Input: Given number questions
//  Output: Screenoutput of the question

void StartQuestion(int num_numbers, int achievment[4], int rounds, int &current_streak, int question_bank[18556])
{

    vector<int>  Givennumbers;
    int frequency[13] = {};

    ifstream fin;

    if (num_numbers == 4) {
        fin.open ("question_bank_4.txt");

//  The question bank is previously generated with another c++ program algorithm design, using file I/O to store the questions in the question bank file for the later use.
//  This makes every random questions picked from the question bank solvable (be able to be calculated into 24 with given rules).

        string num_0 = "", num_1 = "", num_2 = "", num_3 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0;
        srand (time(NULL));
        int question_id = rand() % 1360; int randomsuit[4] = {};
        while (question_bank [question_id] == -1) {int question_id = rand() % 1360; } //  Pick a new question from the given 1360 questions for each time.
        question_bank [question_id] = -1;
        for (int i = 0; i < question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3); }

        stringstream string_int0; string_int0 << num_0; string_int0 >> _num_0;
        stringstream string_int1; string_int1 << num_1; string_int1 >> _num_1;
        stringstream string_int2; string_int2 << num_2; string_int2 >> _num_2;
        stringstream string_int3; string_int3 << num_3; string_int3 >> _num_3;

//  Load the data from the question bank.

        srand (time(NULL));
        for (int i = 0; i < 4; i++) {randomsuit[i] = rand() % 4; }

        _num_0 += 13 * randomsuit[0] - 1; Givennumbers.push_back (_num_0); frequency [_num_0 % 13] += 1;
        _num_1 += 13 * randomsuit[1] - 1; Givennumbers.push_back (_num_1); frequency [_num_1 % 13] += 1;
        _num_2 += 13 * randomsuit[2] - 1; Givennumbers.push_back (_num_2); frequency [_num_2 % 13] += 1;
        _num_3 += 13 * randomsuit[3] - 1; Givennumbers.push_back (_num_3); frequency [_num_3 % 13] += 1;
        fin.close ();

    //  Alternating the suit of the card with the given card.

    }

    if (num_numbers == 5) {
        fin.open ("question_bank_5.txt");      //  Similar principle with question_bank_4.txt, just for these questions there are 5 numbers given.
        string num_0 = "", num_1 = "", num_2 = "", num_3 = "", num_4 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0, _num_4 = 0;
        srand (time(NULL));
        int question_id = rand() % 6100; int randomsuit[5] = {};
        while (question_bank [question_id] == -1) {int question_id = rand() % 6100; }
        question_bank [question_id] = -1;
        for (int i = 0; i < question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3, ' '); getline (fin, num_4); }

        stringstream string_int0; string_int0 << num_0; string_int0 >> _num_0;
        stringstream string_int1; string_int1 << num_1; string_int1 >> _num_1;
        stringstream string_int2; string_int2 << num_2; string_int2 >> _num_2;
        stringstream string_int3; string_int3 << num_3; string_int3 >> _num_3;
        stringstream string_int4; string_int4 << num_4; string_int4 >> _num_4;

        srand (time(NULL));
        for (int i = 0; i < 5; i++) {randomsuit[i] = rand() % 4; }

        _num_0 += 13 * randomsuit[0] - 1; Givennumbers.push_back (_num_0); frequency [_num_0 % 13] += 1;
        _num_1 += 13 * randomsuit[1] - 1; Givennumbers.push_back (_num_1); frequency [_num_1 % 13] += 1;
        _num_2 += 13 * randomsuit[2] - 1; Givennumbers.push_back (_num_2); frequency [_num_2 % 13] += 1;
        _num_3 += 13 * randomsuit[3] - 1; Givennumbers.push_back (_num_3); frequency [_num_3 % 13] += 1;
        _num_4 += 13 * randomsuit[4] - 1; Givennumbers.push_back (_num_4); frequency [_num_4 % 13] += 1;

        fin.close ();
    }


    if (num_numbers == 6) {      //  Similar principle with question_bank_4.txt, just for these questions there are 6 numbers given.
        fin.open ("question_bank_6.txt");
        string num_0 = "", num_1 = "", num_2 = "", num_3 = "", num_4 = "", num_5 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0, _num_4 = 0, _num_5 = 0;
        srand (time(NULL));
        int question_id = rand() % 18556; int randomsuit[6] = {};
        while (question_bank [question_id] == -1) {int question_id = rand() % 18556; }
        question_bank [question_id] = -1;
        for (int i = 0; i < question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3, ' '); getline (fin, num_4, ' '); getline (fin, num_5); }

        stringstream string_int0; string_int0 << num_0; string_int0 >> _num_0;
        stringstream string_int1; string_int1 << num_1; string_int1 >> _num_1;
        stringstream string_int2; string_int2 << num_2; string_int2 >> _num_2;
        stringstream string_int3; string_int3 << num_3; string_int3 >> _num_3;
        stringstream string_int4; string_int4 << num_4; string_int4 >> _num_4;
        stringstream string_int5; string_int5 << num_5; string_int5 >> _num_5;

        srand (time(NULL));
        for (int i = 0; i < 6; i++) {randomsuit[i] = rand() % 4; }

        _num_0 += 13 * randomsuit[0] - 1; Givennumbers.push_back (_num_0); frequency [_num_0 % 13] += 1;
        _num_1 += 13 * randomsuit[1] - 1; Givennumbers.push_back (_num_1); frequency [_num_1 % 13] += 1;
        _num_2 += 13 * randomsuit[2] - 1; Givennumbers.push_back (_num_2); frequency [_num_2 % 13] += 1;
        _num_3 += 13 * randomsuit[3] - 1; Givennumbers.push_back (_num_3); frequency [_num_3 % 13] += 1;
        _num_4 += 13 * randomsuit[4] - 1; Givennumbers.push_back (_num_4); frequency [_num_4 % 13] += 1;
        _num_5 += 13 * randomsuit[5] - 1; Givennumbers.push_back (_num_5); frequency [_num_5 % 13] += 1;

        fin.close ();
    }

    cout << endl;


    system ("clear");
    cout << " ========================================================== "      << endl;
    cout << "||" << " ?   Question " << setw(2) << rounds << "                                        " << "||" << endl;
    PrintNumbers (Givennumbers);
    cout << " ========================================================== "      << endl;
    string calculation_player = "";
    cout << "       Enter your calculation:       ";


    std::chrono::high_resolution_clock::time_point  start_time, finish_time;
    duration <float> time_used;

    start_time = std::chrono::high_resolution_clock::now();   //  Initialize the timer, starting letting the player to answer the question.

    getline (cin, calculation_player);


    bool valid_not = true;
    string valid_information = "";
    int time_bonus[10] = {15, 12, 10, 8, 6, 5, 4, 3, 2, 1};
    int time_achievment[10] = {};


    if (num_numbers == 4) {
        time_achievment[0] = 5000;    time_achievment[1] = 7500;
        time_achievment[2] = 10000;   time_achievment[3] = 15000;
        time_achievment[4] = 20000;   time_achievment[5] = 25000;
        time_achievment[6] = 30000;   time_achievment[7] = 40000;
        time_achievment[8] = 50000;   time_achievment[9] = 60000;
    }
    if (num_numbers == 5) {
        time_achievment[0] = 10000;   time_achievment[1] = 15000;
        time_achievment[2] = 20000;   time_achievment[3] = 30000;
        time_achievment[4] = 40000;   time_achievment[5] = 50000;
        time_achievment[6] = 60000;   time_achievment[7] = 80000;
        time_achievment[8] = 100000;  time_achievment[9] = 120000;
    }

    if (num_numbers == 6) {
        time_achievment[0] = 20000;   time_achievment[1] = 30000;
        time_achievment[2] = 40000;   time_achievment[3] = 40000;
        time_achievment[4] = 80000;   time_achievment[5] = 100000;
        time_achievment[6] = 120000;  time_achievment[7] = 160000;
        time_achievment[8] = 200000;  time_achievment[9] = 240000;
    }

//  Time bonus achievment table, in ms. When answering questions under these given time, time bonus points will be awarded.
//  The more the numbers are in the question, the more time given for the same bonus points.

    Valid_Checker1 (calculation_player, valid_not, valid_information, frequency);
    if (valid_not) {
        string _result_expression;
        _result_expression = Valid_Checker2 (calculation_player, valid_not, valid_information, 0); }

    finish_time = std::chrono::high_resolution_clock::now();   //  Stop the timer, get the time the player answered the question.
    time_used = finish_time - start_time;
    int _time_used = time_used.count() * 1000;

    cout << endl;


    if (valid_not) {
        cout << "\u2714\ufe0f  " << valid_information;   //  Show the correct information if the expression is right
        stringstream Time;
        string _Time_used;
        Time << _time_used;
        Time >> _Time_used;

        cout << "             Time used: " << _Time_used << " ms" << endl;   //  Show the time used if the expression is right
        current_streak += 1;

        int _scored = 0;
        achievment[0] += 5; _scored += 5;
        for (int i = 0; i < 10; i++) {
            if (_time_used < time_achievment[i]) {achievment[0] += time_bonus[i]; _scored += time_bonus[i]; break; } }
        usleep(2000000);
        cout << "   Points for this question: " << _scored << "        Points accumulated: " << achievment[0] << endl;
        usleep(2000000);

        achievment[1] += 1;
        achievment[2] += _time_used;
        if (current_streak > achievment[3]) {achievment[3] = current_streak; }
        if (_time_used < achievment[4]) {achievment[4] = _time_used; }

//  Add scores, accumulate time used, update the min.time and max.streak if applicable

    }

    else           {
        cout << "\u2716\ufe0f  " << valid_information << endl;   //  Show the wrong information if the expression is wrong
        current_streak = 0;
        achievment[0] += 0;
        usleep(2000000);
        cout << "   Points for this question: " << "0" << "        Points accumulated: " << achievment[0] << endl;
        usleep(2000000);

        achievment[1] += 0;
        achievment[2] += _time_used;
    }
    cout << "Enter anything to continue...   ";
    string _enter; getline (cin, _enter);
    cout << endl << endl;
}
//  This function is for a single question's workflow
//  Input: Question mode, current rounds, current streak, question bank used
//  Output: Screenoutput of the question

int Startgame (string playername) {

    cout << endl;
    string name = playername;
    system ("clear");
    int achievment[5] = {0, 0, 0, 0, 100000000};  // score, correct questions, time, max.streak, min.time

    string modechoice = "0";
    int rounds = 1;
    int current_streak = 0;


    cout << "Hi " << name << ", " << "Please select your game mode:  " << endl;
    cout << " ========================================================== "      << endl;
    cout << "||" << "     Enter 1:  Calculate  4  numbers                    " << "||" << endl;
    cout << "||" << "     Enter 2:  Calculate  5  numbers                    " << "||" << endl;
    cout << "||" << "     Enter 3:  Calculate  6  numbers                    " << "||" << endl;
    cout << " ========================================================== "      << endl;

//  Choose the game mode: how many numbers to calculate

    while (modechoice != "1" && modechoice != "2" && modechoice != "3") {

        cout << "Your option: " ;
        getline(cin, modechoice);

        system("clear");

        if (modechoice == "1" || modechoice == "2" || modechoice == "3") {
            stringstream string_int;
            int int_modechoice;
            string_int << modechoice;
            string_int >> int_modechoice;
            cout << " ========================================================== "                                << endl;
            cout << "||" << "                     24_Calculation                     "                            << "||"    << endl;
            cout << "||" << "                 Calculate  " << int_modechoice + 3 << "  numbers                  " << "||"    << endl;
            cout << "||" << "                                                        "                            << "||"    << endl;
        }

        if (modechoice == "1") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:                   3\u2660   4\u2665   9\u2663   Q\u2666     "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:          3 * 9 - 12 / 4        "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

//  Give the example interface of the game

            int question_bank[18556];
            for (rounds = 1; rounds <= 5; rounds++) {
                StartQuestion(4, achievment, rounds, current_streak, question_bank);
            }

//  Do 5 questions in the 4-number mode

            system ("clear");

            Show_result (4, achievment, name); break;

//  Show the scoreboard

        }

        else if (modechoice == "2") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:            A\u2660   2\u2665   8\u2663   10\u2666   11\u2660     "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:   1 * (11 + 8 + 10 / 2)        "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

//  Give the example interface of the game

            int question_bank[18556];
            for (rounds = 1; rounds <= 5; rounds++) {
                StartQuestion(5, achievment, rounds, current_streak, question_bank);
            }

//  Do 5 questions in the 5-number mode

            system ("clear");
            Show_result (5, achievment, name); break;

//  Show the scoreboard
        }

        else if (modechoice == "3") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:            5\u2660   6\u2665   7\u2663   J\u2666   Q\u2660   K\u2665  "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:   (5 + 6 - 7) * 12 - 11 - 13   "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

//  Give the example interface of the game

            int question_bank[18556];
            for (rounds = 1; rounds <= 5; rounds++) {
                StartQuestion(6, achievment, rounds, current_streak, question_bank);
            }

//  Do 5 questions in the 6-number mode

            system ("clear");

            Show_result (6, achievment, name); break;

//  Show the scoreboard

        }

        else {
            cout << "Sorry, " << modechoice << " is an invalid option. Please enter 1, 2 or 3" << endl;
        }
//  Choose the game option again in case it is invalid

    }

    int playerscore = achievment [0];
    return playerscore;
}

//  Input: Player's name
//  Output: Manage the overall workflow of the 5 questions

void Printrules ( ) {

    system("clear");
    cout << " ========================================================== "                << endl;
    cout << "||" << "                Rules of 24_Calculation                 " << "||"    << endl;
    cout << "||" << "                                                        " << "||"    << endl;
    cout << "||" << "          A few numbers will be given to you!           " << "||"    << endl;
    cout << "||" << "      Your task: Form an expression to make it 24,      " << "||"    << endl;
    cout << "||" << "          with each number used exactly once,           " << "||"    << endl;
    cout << "||" << "       basic operators (+, -, *, /) and brankets.       " << "||"    << endl;
    cout << "||" << "                                                        " << "||"    << endl;
    cout << "||" << "      Decimals can be involved in the calculation!      " << "||"    << endl;
    cout << "||" << "       Avoid negative numbers in the calculation!       " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    cout << "Enter anything to continue...   "; string _enter;
    getline (cin, _enter); cout << endl;
}

//  Print the rules of the game
//  Input: None
//  Output: Screenoutput of the game rules

int _24Cal_main (string &playername, int &playerscore) {

    system ("clear");

    cout << " ========================================================== "                << endl;
    cout << "||" << "  Hi there! Welcome to the 24_Calculation!              " << "||"    << endl;
    cout << "||" << "  Enter 1:  Play                                        " << "||"    << endl;
    cout << "||" << "  Enter 2:  Read rules and Play                         " << "||"    << endl;
    cout << " ========================================================== "                << endl;

    string _enter;

    string startchoice = "1";
    cout << "Your option: " ;
    getline (cin, startchoice);

    while (startchoice != "1" && startchoice != "2")
    {
        cout << endl
             << "Sorry, " << startchoice << " is an invalid option. Please enter 1 or 2" << endl;
        cout << "Your option: ";
        getline(cin, startchoice);
    }

    if (startchoice == "2")
    {
        Printrules();
    }

    if (startchoice == "1" || startchoice == "2")
    {

        system("clear");

        cout << " ========================================================== " << endl;
        cout << "||";
        typewriter_("  Before this round the score is:    ", 100000);
        cout << setw(5) << playerscore << "              "
             << "||" << endl;
        cout << " ========================================================== " << endl;
        string _enter;
        usleep(1000000);
        cout << "Enter anything to continue...   ";
        getline(cin, _enter);
        cout << endl
             << endl;

        playerscore += Startgame(playername);

        system("clear");

        cout << " ========================================================== " << endl;
        cout << "||";
        typewriter_("  After this round the score is:    ", 100000);
        cout << setw(5) << playerscore << "               "
             << "||" << endl;
        cout << " ========================================================== " << endl;
        usleep(1000000);
        cout << "Enter anything to continue...   ";
        getline(cin, _enter);
        cout << endl
             << endl;
    }

//  Display the total accumulated score for the main menu before and after this game.

    cout << endl
         << endl;

    cout << " ========================================================== "                << endl;
    cout << "||" << "     Round over, thanks for playing 24_Calculation!     " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    cout << "Enter anything to go back to the main menu...   ";
    getline (cin, _enter);

//  Display the end information when this round is finished.

    return 0;
}

//  Main function of the 24 calculation game
//  Input: Player's name and score from the main menu
//  Output: Change the player's score; screenoutput

//  End of the 24 Calculation Program! 

