#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>

#include <cstdlib>
#include <iomanip>

// #include <chrono>

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
    cout << " ";
}






void Show_result (int modechoice, int achievment[5], string name) {

    cout << "Here is " << name << "'s scoreboard: " << endl;
    cout << " ========================================================== "                                                      << endl;
    cout << "||" << setw(20) << "  Game Mode: "       << setw(16) << modechoice                              << "                    " << "||" << endl;
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
    int    score_rank  [12] = { 75,  68,  60,  55,  50,  45,  41,  38,  34,  30,  25,  0  };
    string rank_letter [12] = {"A+",  "A", "A-", "B+",  "B", "B-", "C+",  "C", "C-", "D+",  "D", "F" };

    int rank = 0;
    for (rank = 0; rank < 12; rank ++) { if (achievment[0] >= score_rank[rank]) {break; } }
    cout << "||" << setw(20) << "  Overall Score: "   << setw(16) << achievment[0]     << "                    " << "||" << endl;
    cout << "||" << setw(20) << "  Overall Grade: "   << setw(16) << rank_letter[rank] << "                    " << "||" << endl;
    cout << " ========================================================== "                                                      << endl;

    cout << "Enter anything to continue...   ";
    string _enter; getline (cin, _enter);
    cout << endl << endl;
}











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









void Do_Calculation (vector<char> &calculation_operator, int &calculation_operator_length, vector<float> &calculation_number, int &calculation_number_length, char next_operator, string &valid_information, bool &valid_not, bool &finish_not) {

    char top_operator = calculation_operator.back();

    if (top_operator == '+') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum + firstnum;
        cout << "Addition: " << secondnum << " + " << firstnum << " = " << result  << endl;
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

    if (top_operator == '-') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum - firstnum;
        cout << "Subtraction: " << secondnum << " - " << firstnum << " = " << result  << endl;
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

    if (top_operator == '*') {
        float firstnum                =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float secondnum               =      calculation_number.back(); calculation_number.pop_back(); calculation_number_length -= 1;
        float result                  =      secondnum * firstnum;
        cout << "Multiplicaton: " << secondnum << " * " << firstnum << " = " << result  << endl;
        calculation_number.push_back (result);  calculation_number_length += 1;
        calculation_operator.pop_back();  calculation_operator_length -= 1;
    }

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
            cout << "Division: " << secondnum << " / " << firstnum << " = " << result  << endl;
            calculation_number.push_back (result);  calculation_number_length += 1;
            calculation_operator.pop_back();  calculation_operator_length -= 1;
        }
    }

    if (calculation_number.back() < 0 && valid_not) {valid_information = "Sorry, please get rid of negative numbers in the calculation! "; valid_not = false; finish_not = true; cout << "Negative numbers detected! " << endl; }

    if (next_operator != ';' ) {calculation_operator.push_back (next_operator);   calculation_operator_length += 1; }

}







string Valid_Checker2 (string calculation_player, bool &valid_not, string &valid_information, int branket_level) {

    if (valid_not) {

        float result = 0; bool finish_not = false;
        int pointer_i = 0, pointer_j = 0;
        vector<char> calculation_operator; vector<float> calculation_number;
        int calculation_operator_length = 0; int calculation_number_length = 0;
        float current_number = 0;
        string _current_number = ""; string calculation_player_new = "";

        int i = 0;
        calculation_player += ";" ;
        calculation_operator.push_back (';'); calculation_operator_length += 1;

        while (i < calculation_player.length() && valid_not && !finish_not) {

            current_number = 0; _current_number =  "";

            while (calculation_player [i] >= 48 && calculation_player [i] <= 57 || calculation_player [i] == 46)  {
                _current_number += calculation_player [i];
                current_number = 1; i++; pointer_j++;
            }

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
            if (23.9 < calculation_number.back() && calculation_number.back() < 24.1 ) {
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
    }

    if (valid_not) {return calculation_player; }
    else {return "error"; }

}




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
            if (valid_not) {valid_information = "Sorry, expression has grammar mistakes! Error: Operators connect together"; valid_not = false; return; }
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









void PrintNumbers (vector<int> Givennumbers){

    if      (Givennumbers.size() == 4)    {cout << "||" << "     Given numbers:             "; }
    else if (Givennumbers.size() == 5)    {cout << "||" << "     Given numbers:         ";   }
    else if (Givennumbers.size() == 6)    {cout << "||" << "     Given numbers:     ";     }
    int count = 0;



    for (int i = 0; i < Givennumbers.size(); i++) {
        cout << setw (3);
        PrintCard_ (Givennumbers[i] % 13, Givennumbers[i] / 13);
    }
    if      (Givennumbers.size() == 4)    {cout << "    " << "||" << endl; }
    else if (Givennumbers.size() == 5)    {cout << "   "  << "||" << endl; }
    else if (Givennumbers.size() == 6)    {cout << "  "   << "||" << endl; }
}






void Startgame_ (int num_numbers, int achievment[4], int rounds, int &current_streak, int question_bank[18556]) {

    vector<int>  Givennumbers;
    int frequency[13] = {};

    ifstream fin;

    if (num_numbers == 4) {
        fin.open ("question_bank_4.txt");
        string num_0 = "", num_1 = "", num_2 = "", num_3 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0;
        srand (time(NULL));
        int question_id = rand() % 1364; int randomsuit[4] = {};
        while (question_bank [question_id] == -1) {int question_id = rand() % 1364; }
        question_bank [question_id] = -1;
        for (int i = 0; i <= question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3); }

        stringstream string_int0; string_int0 << num_0; string_int0 >> _num_0;
        stringstream string_int1; string_int1 << num_1; string_int1 >> _num_1;
        stringstream string_int2; string_int2 << num_2; string_int2 >> _num_2;
        stringstream string_int3; string_int3 << num_3; string_int3 >> _num_3;

        srand (time(NULL));
        for (int i = 0; i < 4; i++) {randomsuit[i] = rand() % 4; }

        _num_0 += 13 * randomsuit[0] - 1; Givennumbers.push_back (_num_0); frequency [_num_0 % 13] += 1;
        _num_1 += 13 * randomsuit[1] - 1; Givennumbers.push_back (_num_1); frequency [_num_1 % 13] += 1;
        _num_2 += 13 * randomsuit[2] - 1; Givennumbers.push_back (_num_2); frequency [_num_2 % 13] += 1;
        _num_3 += 13 * randomsuit[3] - 1; Givennumbers.push_back (_num_3); frequency [_num_3 % 13] += 1;
    }

    if (num_numbers == 5) {
        fin.open ("question_bank_5.txt");
        string num_0 = "", num_1 = "", num_2 = "", num_3 = "", num_4 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0, _num_4 = 0;
        srand (time(NULL));
        int question_id = rand() % 6114; int randomsuit[5] = {}; 
        while (question_bank [question_id] == -1) {int question_id = rand() % 6114; }
        question_bank [question_id] = -1;
        for (int i = 0; i <= question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3, ' '); getline (fin, num_4); }

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
    }


    if (num_numbers == 6) {
        fin.open ("question_bank_6.txt");
        string num_0 = "", num_1 = "", num_2 = "", num_3 = "", num_4 = "", num_5 = "";
        int _num_0 = 0, _num_1 = 0, _num_2 = 0, _num_3 = 0, _num_4 = 0, _num_5 = 0;
        srand (time(NULL));
        int question_id = rand() % 18556; int randomsuit[6] = {};
        while (question_bank [question_id] == -1) {int question_id = rand() % 18556; }
        question_bank [question_id] = -1;
        for (int i = 0; i <= question_id; i++) {getline (fin, num_0, ' '); getline (fin, num_1, ' '); getline (fin, num_2, ' '); getline (fin, num_3, ' '); getline (fin, num_4, ' '); getline (fin, num_5); }

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
    }

    cout << endl;



    cout << " ========================================================== "      << endl;
    cout << "||" << " ?   Question " << setw(2) << rounds << "                                        " << "||" << endl;
    PrintNumbers (Givennumbers);
    cout << " ========================================================== "      << endl;
    string calculation_player = "";
    cout << "       Enter your calculation:       ";


    std::chrono::high_resolution_clock::time_point  start_time, finish_time;
    duration <float> time_used;

    start_time = std::chrono::high_resolution_clock::now();

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


    Valid_Checker1 (calculation_player, valid_not, valid_information, frequency);
    if (valid_not) {
        string _result_expression;
        _result_expression = Valid_Checker2 (calculation_player, valid_not, valid_information, 0); }

    finish_time = std::chrono::high_resolution_clock::now();
    time_used = finish_time - start_time;
    int _time_used = time_used.count() * 1000;


    if (valid_not) {
        cout << "✔️  " << valid_information;
        stringstream Time;
        string _Time_used;
        Time << _time_used;
        Time >> _Time_used;

        cout << "             Time used: " << _Time_used << " ms" << endl;
        current_streak += 1;

        int _scored = 0;
        achievment[0] += 5; _scored += 5;
        for (int i = 0; i < 10; i++) {
            if (_time_used < time_achievment[i]) {achievment[0] += time_bonus[i]; _scored += time_bonus[i]; break; } }
        cout << "   Points for this question: " << _scored << "        Points accumulated: " << achievment[0] << endl;

        achievment[1] += 1;
        achievment[2] += _time_used;
        if (current_streak > achievment[3]) {achievment[3] = current_streak; }
        if (_time_used < achievment[4]) {achievment[4] = _time_used; }

    }

    else           {
        cout << "✖️  " << valid_information << endl;
        current_streak = 0;
        achievment[0] += 0;
        cout << "   Points for this question: " << "0" << "        Points accumulated: " << achievment[0] << endl;

        achievment[1] += 0;
        achievment[2] += _time_used;
    }
    cout << "Enter anything to continue...   ";
    string _enter; getline (cin, _enter); 
    cout << endl << endl;
}











int Startgame (string playername) {

    string name = playername;
    cout << endl;


    string modechoice = "0";
    int rounds = 1;
    int current_streak = 0;
    int achievment[5] = {0, 0, 0, 0, 100000000};  // score, correct questions, time, max.streak, min.time

    cout << "Hi " << name << ", " << "Please select your game mode:  " << endl;
    cout << " ========================================================== "      << endl;
    cout << "||" << "     Enter 1:  Calculate  4  numbers                    " << "||" << endl;
    cout << "||" << "     Enter 2:  Calculate  5  numbers                    " << "||" << endl;
    cout << "||" << "     Enter 3:  Calculate  6  numbers                    " << "||" << endl;
    cout << " ========================================================== "      << endl;

    while (modechoice != "1" && modechoice != "2" && modechoice != "3") {
        cout << "Your option: " ;
        getline (cin, modechoice);
        cout << endl;
        

        if (modechoice == "1" || modechoice == "2" || modechoice == "3") {
            stringstream string_int;
            int int_modechoice;
            string_int << modechoice;
            string_int >> int_modechoice;
            cout << endl;
            cout << " ========================================================== "                                << endl;
            cout << "||" << "                     24_Calculation                     "                            << "||"    << endl;
            cout << "||" << "                 Calculate  " << int_modechoice + 3 << "  numbers                  " << "||"    << endl;
            cout << "||" << "                                                        "                            << "||"    << endl;
        }

        if (modechoice == "1") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:                   3♠   4♥   9♣   Q♦     "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:          3 * 9 - 12 / 4        "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

            int question_bank[18556]; 
            for (rounds = 1; rounds <= 5; rounds++) {
                Startgame_(4, achievment, rounds, current_streak, question_bank);
            }
            Show_result (4, achievment, name); break;
        }

        else if (modechoice == "2") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:            A♠   2♥   8♣   10♦   11♠     "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:   1 * (11 + 8 + 10 / 2)        "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

            int question_bank[18556];
            for (rounds = 1; rounds <= 5; rounds++) {
                Startgame_(5, achievment, rounds, current_streak, question_bank);
            }
            Show_result (5, achievment, name); break;
        }

        else if (modechoice == "3") {
            cout << "||" << " ?   Example:                                           "                        << "||"    << endl;
            cout << "||" << " Given numbers:            5♠   6♥   7♣   J♦   Q♠   K♥  "                        << "||"    << endl;
            cout << "||" << " Enter your calculation:   (5 + 6 - 7) * 12 - 11 - 13   "                        << "||"    << endl;
            cout << "||" << "                                                        "                        << "||"    << endl;
            cout << "||" << " Note: A, J, Q, K  value  1, 11, 12, 13 individually.   "                        << "||"    << endl;
            cout << "||" << " There are 5 questions! Solve as fast as you can!       "                        << "||"    << endl;
            cout << " ========================================================== "                                << endl;
            cout << "Enter anything to start...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

            int question_bank[18556];
            for (rounds = 1; rounds <= 5; rounds++) {
                Startgame_(6, achievment, rounds, current_streak, question_bank);
            }
            Show_result (6, achievment, name); break;
        }

        else {cout << "⚠️  Sorry, " << modechoice << " is an invalid option. Please enter 1, 2 or 3" << endl; }
    }

    int playerscore = achievment [0];
    return playerscore;
}








void Printrules ( ) {
    cout << endl;
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
    cout << " ========================================================== "                << endl << endl;
}






int _24Cal_main (string &playername, int &playerscore) {

    cout << " ========================================================== "                << endl;
    cout << "||" << "  Hi there! Welcome to the 24_Calculation!              " << "||"    << endl;
    cout << "||" << "  Enter 1:  Play                                        " << "||"    << endl;
    cout << "||" << "  Enter 2:  Read rules and Play                         " << "||"    << endl;
    cout << " ========================================================== "                << endl;

    string _enter; getline (cin, _enter);

    string startchoice = "1";
    cout << "Your option: " ;
    getline (cin, startchoice);

        while (startchoice != "1" && startchoice != "2") {
            cout << endl << "⚠️  Sorry, " << startchoice << " is an invalid option. Please enter 1 or 2" << endl; 
            cout << "Your option: " ;
            getline (cin, startchoice);
                cout << "Startchoice: " << startchoice << endl; 
        }

           if (startchoice == "1")      {playerscore += Startgame(playername); }
           else if (startchoice == "2") {Printrules( ); playerscore += Startgame(playername); }

        cout << endl << endl;

    cout << " ========================================================== "                << endl;
    cout << "||" << "     Round over, thanks for playing 24_Calculation!     " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    cout << "Enter anything to go back to the main menu...   ";
    getline (cin, _enter);


    return 0;
}
