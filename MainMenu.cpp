//  Author:        Senthil Kumar Sapnesh (3035790850)
//                 Wu_Kunhuan            (3035771634)
//  Description:   The main menu for navigating the 2 games. This also extracts player data from Output.txt and either
//                     starts new game or continues from existing save based on user preference.

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include "Unomain.h"
#include "_24Cal_main.h"

using namespace std;
//  Global variables
string name;
int rounds, score;

struct Savefile {
    string name;
    int round, score;
};

Savefile data;
//  Extracts data from Output.txt and stores them in data.
//  Input: player name, output: stores data to global variables
bool extractData(string name) {
    ifstream fin;
    fin.open(" [Game saved]  " + name + ".txt");

    if (fin.fail()) {return false; }

    fin >> data.name >> data.round >> data.score;
    fin.close();
    return true;
}


//  Print out like a typewriter
//  Takes in string line and output speed

void typewriter2 (string line, int speed) {
    for (int i = 0; i < line.length(); i++) {
        cout << line[i];
        usleep(speed);
    }
}

//  Slotmachine takes in your score and modifies it. This is a fun chance to double player's score.

void slotmachine (int &score) {
    system ("clear");
    cout << " ========================================================== "      << endl;
    cout << "||" << "                Let us have a rest ...                  " << "||" << endl;
    cout << "||" << "                                                        " << "||" << endl;
    cout << "||" << "               Welcome to Slot Machine!                 " << "||" << endl;
    cout << "||" << " You have a chance to double your bet or lose your bet. " << "||" << endl;
    cout << "||" << "                                                        " << "||" << endl;
    cout << "||" << "    If all 3 numbers are same, then CONGRATULATIONS,    " << "||" << endl;
    cout << "||" << "                 otherwise you LOSE                     " << "||" << endl;
    cout << " ========================================================== "      << endl;
    score += 10;
    cout << "You have got a 10 bonus score  :)  have fun with the slot machine!" << endl;
    cout << "Enter amount of score to bet" << " (Between 1 and " << score << "): ";
    int slotbet;
    cin >> slotbet;
    while (slotbet < 1 || slotbet > score) {
        cout << "Invalid amount of bet. Please enter a bet Between 1 and " << score << ": ";
        cin >> slotbet; cout << endl;

    }

    srand(time(NULL));                //  Generating random numbers
    int slot1, slot2, slot3;
    int chance1, chance2;
    slot1 = rand() % 3 + 1;

    srand(time(NULL));
    chance1 = rand() % 2;
    if (chance1 == 0) {
        slot2 = slot1;
    }
    else {
        slot2 = rand() % 3 + 1;
    }

    srand(time(NULL));
    chance2 = rand() % 2;
    if (chance2 == 0) {
        slot3 = slot2;
    }
    else {
        slot3 = rand() % 3 + 1;
    }


    system ("clear");
    cout << " ================================= "      << endl;
    cout << "||" ;

    typewriter2 ("  Your numbers are: ", 100000);  //  Printing out numbers like a real slotmachine
    cout.flush();
    usleep(1000000);
    cout << slot1 << "  ";
    cout.flush();
    usleep(1000000);
    cout << slot2 << "  ";
    cout.flush();
    usleep(1000000);
    cout << slot3 << "  ";
    cout.flush();
    usleep(1000000);
    cout << "  " << "||" << endl;
    cout << " ================================= "      << endl;

    if (slot1 == slot2 && slot2 == slot3) {                      //  Check if win or not
        cout << " ========================================================== "      << endl;
        cout << "||" << "        CONGRAGULATIONS YOU DOUBLED YOUR BET!!!         " << "||" << endl;
        cout << " ========================================================== "      << endl;
        score = score + slotbet;

        ofstream fout;
        fout.open(" [Game result]  " + name + ".txt", ios::app); fout << endl;
        fout << " ========================================================== "      << endl;
        fout << "||" << "                     Slot Machine                       " << "||" << endl;
        fout << "||" << "        CONGRAGULATIONS YOU DOUBLED YOUR BET!!!         " << "||" << endl;
        fout << " ========================================================== "      << endl;
        fout << "The amount of score you have doubled: " << slotbet << endl;
        fout << endl << endl;
        fout.close();
    }
    else {
        cout << " ========================================================== "      << endl;
        cout << "||" << "                    Sorry you lost.                     " << "||" << endl;
        cout << "||" << "      " << setw(5) << slotbet << " has been deducted from your score           " << "||" << endl;
        cout << " ========================================================== "      << endl;
        score = score - slotbet;

        ofstream fout;
        fout.open(" [Game result]  " + name + ".txt", ios::app); fout << endl;
        fout << " ========================================================== "      << endl;
        fout << "||" << "                     Slot Machine                       " << "||" << endl;
        fout << "||" << "                    Sorry you lost.                     " << "||" << endl;
        fout << " ========================================================== "      << endl;
        fout << "The amount of score you have lost: " << slotbet << endl;
        fout << endl << endl;
        fout.close();
    }

    cout << " ========================================================== "      << endl;
    cout << "||" << "  Current score: " << setw(6) << score  << "                                 " << "||" << endl;
    cout << " ========================================================== "      << endl;

    usleep (2000000);

    cout << "Enter anything to continue the next round ... ";
    string choice; getline (cin, choice);
}


//  The menu for navigating games. Also has call to slotmachine
//  Once 5 rounds are over, it will create an output file to store stats.
// No input/output only changes global variables
void Menu() {
    bool slot = false; 
    string gamechoice;

    while (rounds < 6) {

        system ("clear");

        cout << " ================================ "      << endl;
        cout << "||" << "     This is Round " << rounds << " / 5!     "   << "||" << endl;
        cout << " ================================ "      << endl;

        cout << " ========================================================== "      << endl;
        cout << "||" << "           Which game would you like to play?           " << "||" << endl;
        cout << "||" << "                                                        " << "||" << endl;
        cout << "||" << "          To play Crazy Eights, please enter 1          " << "||" << endl;
        cout << "||" << "         To play 24 Calculation, please enter 2         " << "||" << endl;
        cout << "||" << "        To quit and save progress, please enter 3       " << "||" << endl;
        cout << " ========================================================== "      << endl;
        cout << "Your choice: ";

        cin >> gamechoice;
        cout << endl << endl << endl;

        if (gamechoice == "1") {

            ofstream fout;
            fout.open(" [Game result]  " + name + ".txt", ios::app);
            fout << " ================================ "      << endl;
            fout << "||" << "         Round " << rounds << " / 5          "     << "||" << endl;
            fout << " ================================ "      << endl;
            fout.close();

            unomain (name, score);
            rounds += 1; if (rounds == 3 || rounds == 5) {slot = true; }

        }
        else if (gamechoice == "2") {

            ofstream fout;
            fout.open(" [Game result]  " + name + ".txt", ios::app);
            fout << " ================================ "      << endl;
            fout << "||" << "         Round " << rounds << " / 5          "     << "||" << endl;
            fout << " ================================ "      << endl;
            fout.close();

            _24Cal_main (name, score);
            rounds += 1; if (rounds == 3 || rounds == 5) {slot = true; }

        }





        else if (gamechoice == "3") {
            cout << " Name: " << name << "   Round: " << rounds << "   Score: " << score << endl;
            ofstream fout2;
            fout2.open (" [Game saved]  " + name + ".txt");
            fout2 << name << endl;
            fout2 << rounds << endl;
            fout2 << score << endl;
            fout2.close();
            cout << " ========================================================== "      << endl;
            cout << "||" << "       You have saved your progress successfully!       " << "||" << endl;
            cout << "||" << "                  Thanks for playing!                   " << "||" << endl;
            cout << " ========================================================== "      << endl;
            break;
        }

        else {cout << endl << "Sorry, " << gamechoice << " is an invalid option. Please enter 1, 2 or 3" << endl; }

        if ((rounds == 3 || rounds == 5) && slot) {
            slot = false; 
            slotmachine(score);
        }
    }                                                             //  End of while loop

    if (rounds == 6) {                                               //  If game over

        system ("clear");

        cout << " ========================================================== "      << endl;
        cout << "||" << "                       GAME OVER                        " << "||" << endl;
        cout << "||" << "                  Thanks for playing!                   " << "||" << endl;
        cout << " ========================================================== "      << endl;
        cout.flush();
        typewriter2  ("Name: ", 200000);
        cout << name << endl;
        usleep (1000000);

        typewriter2 ("Score: ", 200000);
        cout << score << endl << endl; ;
        usleep (1000000);


        ofstream fout;
        fout.open(" [Game result]  " + name + ".txt", ios::app);
        fout << " ========================================================== "      << endl;
        fout << "||" << "                        Overall                         " << "||" << endl;
        fout << " ========================================================== "      << endl;
        fout << "Score: "<< score << endl << endl;
        fout.close();

        cout << "Your game statistics can be found in \"[Game result]  " + name + ".txt\" !" << endl; 
        cout << "Have a good day! " << endl << endl;
        usleep (2000000);

    }

    string choice; getline (cin, choice);
    cout << "Enter anything to quit ... ";
    getline (cin, choice);
    system ("clear");
}


//  This function checks if there is existing save file of player.
//  Gives player option to continue or start new game if savefile is found. 
// No input/output, only reads/changes global variables
int main() {


    system ("clear");

    cout << " ========================================================== "      << endl;
    cout << "||" << "              WELCOME TO THE 2-IN-1 GAME                " << "||" << endl;
    cout << " ========================================================== "      << endl;
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;

    if (extractData (name)) {
        cout << " ========================================================== "      << endl;
        cout << "||" << "                    Old save found!                     " << "||" << endl;
        cout << "||" << "       Would you like to continue from last save?       " << "||" << endl;
        cout << "||" << "        Enter 1 for Yes or anything else for No         " << "||" << endl;
        cout << " ========================================================== "      << endl;
        string choice; getline (cin, choice);
        cout << "Your choice: ";
        getline (cin, choice);

        if (choice == "1") {

            system ("clear");

            name = data.name;
            rounds = data.round;
            score = data.score;

            cout << " ========================================================== "      << endl;
            if (name.length() > 20) {cout << "||" << "  Welcome back " << name.substr(0, 20) << "!" << setw(22)                 << "||" << endl; }
            else                    {cout << "||" << "  Welcome back " << name               << "!" << setw(42 - name.length()) << "||" << endl; }
            cout << "||" << "                                                        " << "||" << endl;
            cout << "||" << "  Current round: " << setw(6) << rounds << "                                 " << "||" << endl;
            cout << "||" << "  Current score: " << setw(6) << score  << "                                 " << "||" << endl;
            cout << " ========================================================== "      << endl;
            cout << "Enter anything to continue the game ... ";
            string choice; getline (cin, choice);

            Menu ();
        }

        else {
            cout << " ========================================================== "      << endl;
            cout << "||" << "                   Starting new game!                   " << "||" << endl;
            cout << " ========================================================== "      << endl;

            rounds = 1;
            score = 0;

            ofstream fout;
            fout.open(" [Game result]  " + name + ".txt");
            fout << " ================================ "      << endl;
            fout << "||" << "           New Game!          "     << "||" << endl;
            fout << " ================================ "      << endl;
            fout << endl;
            fout.close();

            ofstream fout2;
            fout2.open (" [Game saved]  " + name + ".txt");
            fout2 << name << endl;
            fout2 << rounds << endl;
            fout2 << score << endl;
            fout2.close();

            cout << "Enter anything to start the new game ... ";
            string choice; getline (cin, choice);

            Menu();
        }
    }

    else {
        cout << " ========================================================== "      << endl;
        cout << "||" << "         No old save found. Starting new game!          " << "||" << endl;
        cout << " ========================================================== "      << endl;


        rounds = 1;
        score = 0;

        ofstream fout;
        fout.open(" [Game result]  " + name + ".txt");
        fout << " ================================ "      << endl;
        fout << "||" << "           New Game!          "     << "||" << endl;
        fout << " ================================ "      << endl;
        fout << endl;
        fout.close();

        ofstream fout2;
        fout2.open (" [Game saved]  " + name + ".txt");
        fout2 << name << endl;
        fout2 << rounds << endl;
        fout2 << score << endl;
        fout2.close();

        cout << "Enter anything to start the new game ... ";
        string choice; getline (cin, choice); getline (cin, choice);


        Menu();
    }

    return 0;
}
