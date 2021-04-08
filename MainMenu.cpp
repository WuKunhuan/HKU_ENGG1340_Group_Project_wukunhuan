//Author: Senthil Kumar Sapnesh
//Student ID: 3035790850
//Description: Main menu for navigating the 2 games. This also extracts player data from Output.txt and either
//starts new game or continues from existing save based on user preference

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include "Unomain.h"
#include "_24Cal_main.h"

using namespace std;
//Global variables
string name;
int rounds, score;

struct Savefile {
    string name;
    int round, score;
};

Savefile data;
//Extracts data from Output.txt and stores them in data.
//No input, no output
void extractData() {
    ifstream fin;
    fin.open("Output.txt");

    fin >> data.name >> data.round >> data.score;

    fin.close();
}


//Print out like a typewriter
//Takes in string line and output speed
void typewriter2(string line, int speed) {
    for (int i = 0; i < line.length(); i++) {
        cout << line[i];
        cout.flush();
        usleep(speed);
    }
}

//Slotmachine takes in your score and modifies it. This is a fun chance to increase the player's score
void slotmachine(int& score) {
    system("clear");
    cout << "Welcome to Slot Machine" << endl;
    cout << "You have a chance to double your bet and lose your bet." << endl;
    cout << "Enter amount of score to bet" << " (Between 1  and " << score << "): ";
    int slotbet;
    cin >> slotbet;
    while (slotbet<1 || slotbet>score) {
        cout << "Invalid amount of bet. Please enter a bet Between 1  and " << score << ": ";
        cin >> slotbet;
    }

    srand(time(NULL));                //Generating random numbers
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


    typewriter2("Your numbers are: ", 100000);  //Printing out numbers like a real slotmachine
    cout.flush();
    usleep(100000);
    cout << slot1 << " ";
    cout.flush();
    usleep(100000);
    cout << slot2 << " ";
    cout.flush();
    usleep(100000);
    cout << slot3 << " ";
    cout.flush();
    usleep(100000);

    if (slot1 == slot2 && slot2 == slot3) {                      //Check if win or not
        cout << "CONGRAGULATIONS YOU DOUBLED YOUR BET!!!" << endl;
        score = score + slotbet * 2;
        cout<<"Current score: "<<score<<endl;
    }
    else {
        cout << "Sorry you lost." << slotbet << " has been deducted from your score" << endl;
        score = score - slotbet;
        cout<<"Current score: "<<score<<endl;
    }
    cout.flush();
    usleep(100000);
}


//The menu for navigating games. Also has call to slotmachine
//Once 5 rounds are over, it will create an output file to store stats.
void Menu() {
    bool slot = true;
    int gamechoice;
    while (rounds < 6) {
        system("clear");
        cout << endl;
        cout << "=========================================" << endl;
        cout << "Which game would you like to play?" << endl;
        cout << "To play Crazy Eights press 1" << endl;
        cout << "To play 24 Calculation press 2" << endl;
        cout << "To quit and save progress press 3" << endl;

        cin >> gamechoice;

        if (gamechoice == 1) {
            unomain(name, score);
            rounds += 1;
        }
        else if (gamechoice == 2) {

            _24Cal_main(name, score);
            rounds += 1;
        }

        else if (gamechoice == 3) {
            cout << "Name: " << name << " Round: " << rounds << " Score: " << score << endl;
            ofstream fout;
            fout.open("Output.txt");
            fout << name << endl;
            fout << rounds << endl;
            fout << score << endl;
            fout.close();
            break;
        }
        if (slot){
          if ( rounds >= 4 && score > 0) {
              slotmachine(score);
              slot = false;
          }
        }
    }                                                             //End of while loop

    if (rounds == 6) {                                               //If game over
        string filename = name + "stats.txt";
        typewriter2("GAME OVER", 5000);
        cout<<endl;
        typewriter2("Name: ", 5000);
        cout << name;
        typewriter2(" Score: ", 5000);
        cout << score << endl;
        ofstream fout;
        fout.open(filename.c_str());
        fout << "Name: "<< name << endl;
        fout << "Score: "<< score << endl;
        fout.close();

        fout.open("Output.txt");
        fout<<"none"<<endl;
        fout<<1<<endl;
        fout<<0<<endl;
        fout.close();
    }
    cout << "Thank you for playing!" << endl;
}


//This function checks if there is existing save file of player.
//Gives player option to continue or start new game if savefile is found
int main() {
    extractData();

    cout << "WELCOME TO THE 2-IN-1 GAME" << endl;
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;

    if (name == data.name) {
        cout << "Old save game found, would you like to continue from last save? Yes or No: ";
        string choice;
        cin >> choice;

        if (choice == "Yes") {
            name = data.name;
            rounds = data.round;
            score = data.score;
            cout << "Welcome back " << name << "! Current round: " << rounds << " Current score: " << score << endl;
            cout.flush();
            usleep(1000000);
            Menu();
        }

        else if (choice == "No") {
            cout << "Starting new game" << endl;

            rounds = 1;
            score = 0;
            cout.flush();
            usleep(1000000);
            Menu();
        }
    }

    else {
        cout << "No old save game found. Starting new game" << endl;
        cout.flush();
        usleep(1000000);

        rounds = 1;
        score = 0;
        Menu();
    }

    return 0;
}
