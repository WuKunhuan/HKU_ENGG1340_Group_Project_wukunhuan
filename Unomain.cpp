//  Author:       Senthil Kumar Sapnesh  (3035790850)
//  Description:  Implementation of Crazy Eights game (Similar to Uno).
//                All Functions needed for this game is in this file.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include <limits>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>

#include "Unomain.h"

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

//Prints the cards given by number and suit (Takes in the rank of a card and its corresponding suit in terms of an integer)
//Also prints them out like a typewriter
void PrintCard(int number, int suit) {
    cout.flush();
    switch (number) {
    case 0:
        usleep(100000);
        cout << " A";
        break;
    case 1:
        usleep(100000);
        cout << " 2";
        break;
    case 2:
        usleep(100000);
        cout << " 3";
        break;
    case 3:
        usleep(100000);
        cout << " 4";
        break;
    case 4:
        usleep(100000);
        cout << " 5";
        break;
    case 5:
        usleep(100000);
        cout << " 6";
        break;
    case 6:
        usleep(100000);
        cout << " 7";
        break;
    case 7:
        usleep(100000);
        cout << " 8";
        break;
    case 8:
        usleep(100000);
        cout << " 9";
        break;
    case 9:
        usleep(100000);
        cout << "10";
        break;
    case 10:
        usleep(100000);
        cout << " J";
        break;
    case 11:
        usleep(100000);
        cout << " Q";
        break;
    case 12:
        usleep(100000);
        cout << " K";
        break;
    }
    switch (suit) {
    case 0:
        usleep(100000);
        cout << SPADE;
        usleep(100000);
        break;
    case 1:
        usleep(100000);
        cout << HEART;
        usleep(100000);
        break;
    case 2:
        usleep(100000);
        cout << CLUB;
        usleep(100000);
        break;
    case 3:
        usleep(100000);
        cout << DIAMOND;
        usleep(100000);
        break;
    }
    cout << " ";
    cout.flush();
}

//Prints out the cards in the player's hand by taking in the player's pile
void PrintHand(vector<int> PlayerPile) {             //print player's cards
    int count = 0;
    for (int i = 0; i < PlayerPile.size(); i++) {
        if (i % 2 == 0) {
            cout << "||";
        }

        cout << setw(8) << setprecision(16);
        cout << i << ") ";
        PrintCard (PlayerPile[i] % 13, PlayerPile[i] / 13);
        cout << setw(8) << setprecision(16);
        count += 1;
        if (count == 2) {
            cout << "                            " << "||";
            if (i != PlayerPile.size() - 1) cout << endl;
            count = 0;
        }
    }

    if (PlayerPile.size() % 2 == 1) {
            cout << "                                          " << "||";
    }
    cout << endl;
}
//Checks if a card played by player and AI is valid or not
//Takes in the card played by player and top card on deck. Outputs true if valid and false otherwise
bool ValidChecker(int& card, int firstcard) {
    int firstcardnum = firstcard % 13;
    int firstcardsuit = firstcard / 13;
    int number = card % 13;
    int suit = card / 13;
    if (number == 7) {
        int wildsuit;

        cout << " ========================================================== "                << endl;
        cout << "||" << "  You have played a WILD CARD                           " << "||"    << endl;
        cout << "||" << "  Please choose the suit that you want                  " << "||"    << endl;
        cout << "||" << "  0 for SPADE          1 for HEARTS                     " << "||"    << endl;
        cout << "||" << "  2 for CLUB           3 for DIAMOND                    " << "||"    << endl;
        cout << " ========================================================== "                << endl;
        cout << "Your choice: ";
        cin >> wildsuit;
        card = wildsuit * 13 + firstcardnum;
        return true;
    }
    if (number == firstcardnum) {
        return true;
    }
    else if (suit == firstcardsuit) {
        return true;
    }
    else {
        return false;
    }
}



//This function deals with the cards played by AIs. Checks if AI has any valid cards to play
//Takes in firstcard and the AI's cards pile. Outputs true if a valid card has been player and false otherwise
bool AI(int& firstcard, vector<int>& aiPile) {
    int firstcardnum = firstcard % 13, firstcardsuit = firstcard / 13;
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 1) {
        reverse(aiPile.begin(), aiPile.end());
    }
    for (int i = 0; i < aiPile.size(); i++) {
        int number, suit;
        number = aiPile[i] % 13;
        suit = aiPile[i] / 13;
        if (number == firstcardnum || number == 7) {
            if (number != 7) {
                PrintCard(number, suit);
                firstcard = aiPile[i];
                aiPile.erase(aiPile.begin() + i);
                cout << endl;
                cout << "AI has " << aiPile.size() << " cards left" << endl;
                return true;
            }
            else {
                PrintCard(number, suit);
                cout << endl;
                cout << "AI has played a WILD CARD. IT has chosen the suit: ";
                int wildsuit = rand() % 4;
                while (wildsuit == firstcardsuit) {
                    wildsuit = rand() % 4;
                }
                switch (wildsuit) {
                case 0:
                    cout << "SPADE" << endl;
                    break;
                case 1:
                    cout << "HEARTS" << endl;
                    break;
                case 2:
                    cout << "CLUB" << endl;
                    break;
                case 3:
                    cout << "DIAMOND" << endl;
                    break;
                }
                firstcard = wildsuit * 13 + firstcardnum;
                aiPile.erase(aiPile.begin() + i);
                cout << "AI has " << aiPile.size() << " cards left" << endl;
                return true;
            }
        }
        else if (suit == firstcardsuit) {
            PrintCard(number, suit);
            firstcard = aiPile[i];
            aiPile.erase(aiPile.begin() + i);
            cout << endl;
            cout << "AI has " << aiPile.size() << " cards left" << endl;
            return true;
        }
    }
    cout.flush();
    usleep(50000);
    cout.flush();
    return false;
}

//Print out like a typewriter
//Takes in a string line and speed of output. Prints string line at speed.
void typewriter(string line, int speed) {
    for (int i = 0; i < line.length(); i++) {
        cout << line[i];
        cout.flush();
        usleep(speed);
    }
}



//Starts a new game of Crazy Eights. Handles each player's turn of playing a card and drawing a card
//Takes in the number of AI player has chosen. Returns the score after game ends.
int StartGame(int numofai) {       //Starts the game
    cout << endl;
    cout << endl;
    system("clear");
    vector<int> PlayerPile, aiPile, aiPile2;
    int DrawPile[52], card;

    for (int i = 0; i < 52; i++) {       //Creating draw pile
        DrawPile[i] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < 7; i++) {         //Create card hand for player
        card = rand() % 52;
        while (DrawPile[card] == -1) {
            card = rand() % 52;
        }
        PlayerPile.push_back(card);
        DrawPile[card] = -1;
    }

    for (int j = 0; j < 7; j++) {      //Create card hand for AI
        card = rand() % 52;
        while (DrawPile[card] == -1) {         //Make sure cards do not overlap with cards that are drawn out from drawpile
            card = rand() % 52;
        }
        aiPile.push_back(card);
        DrawPile[card] = -1;
    }

    if (numofai == 2) {
        for (int j = 0; j < 7; j++) {      //Create card hand for AI2
            card = rand() % 52;
            while (DrawPile[card] == -1) {         //Make sure cards do not overlap with cards that are drawn out from drawpile
                card = rand() % 52;
            }
            aiPile2.push_back(card);
            DrawPile[card] = -1;
        }
    }

    bool win = false;
    int firstcard, drawcount;

    if (numofai == 1){
      drawcount = 15;
    }
    else{
      drawcount = 22;
    }

    firstcard = rand() % 52;          //Make opening card
    while (DrawPile[firstcard] == -1) {
        firstcard = rand() % 52;
    }
    DrawPile[firstcard] = -1;
    int number, suit;
    number = firstcard % 13;
    suit = firstcard / 13;

    cout <<    " ======================== " << endl;
    typewriter("||  Opening card is ", 100000);                                       //Print opening card
    usleep(500000);
    PrintCard(number, suit);
    cout << "" << "||" << endl;
    cout <<    " ======================== " << endl;
    cout << endl;
    card = firstcard;


    int cardindex;

    while (!win) {                                                   //Start of actual game
        card = firstcard;
        cout << " ========================================================== " << endl;
        cout << "||" << "  Your cards are:                                       " << "||"    << endl;
        PrintHand (PlayerPile);
        cout << " ========================================================== " << endl;

        cout << " ========================================================== "                << endl;
        cout << "||" << "  Your turn. Please play a valid card or                " << "||"    << endl;
        cout << "||" << "  enter -1 to draw a card from the Draw pile            " << "||"    << endl;
        cout << " ========================================================== "                << endl;

        cout << "Your choice: ";
        cin >> cardindex;
        if (cardindex != -1) {
            card = PlayerPile[cardindex];
            bool notdraw = true;
            while (!ValidChecker(card, firstcard)) {
                if (cardindex != -1) {

                    cout << " ========================================================== "                << endl;
                    cout << "||";
                    PrintCard(card % 13, card / 13);
                    cout << " is an invalid card. Please choose another to play  " << "||"    << endl;
                    cout << " ========================================================== "                << endl;
                    cin >> cardindex;
                    if (cardindex != -1) {
                        card = PlayerPile[cardindex];
                    }

                }
                else if (cardindex == -1) {                             //Draw card for player
                    card = rand() % 52;
                    while (DrawPile[card] == -1) {
                        card = rand() % 52;
                    }
                    PlayerPile.push_back(card);
                    DrawPile[card] = -1;
                    cout << "You drew ";
                    PrintCard(card % 13, card / 13);
                    cout << endl;
                    drawcount += 1;
                    cout << "Deck size: " << 52 - drawcount << endl;
                    notdraw = false;
                    break;
                }
            }
            if (notdraw) {
                PlayerPile.erase(PlayerPile.begin() + cardindex);
                firstcard = card;
            }

        }

        else if (cardindex == -1) {                    //Player draws new card
            card = rand() % 52;
            while (DrawPile[card] == -1) {
                card = rand() % 52;
            }
            PlayerPile.push_back(card);
            DrawPile[card] = -1;
            cout << "You drew ";
            PrintCard(card % 13, card / 13);
            cout << endl;
            drawcount += 1;
            cout << "Deck size: " << 52 - drawcount << endl;
        }


        if (PlayerPile.size() == 0) {                            //Win conditions
            win = true;
            cout << "       YOU WIN!" << endl;
            if (numofai == 1) {
                return (50-drawcount/2);
            }
            else {
                return (100-drawcount/2);
            }
            break;
        }
        else if (drawcount == 52) {                //Draw Condition
            win = true;
            if (numofai == 1) {
                if (PlayerPile.size() < aiPile.size()) {
                    cout << "You Win as you have less cards! " << endl;
                    return (50-drawcount/2);
                    break;
                }
                else if (aiPile.size() == PlayerPile.size()) {
                    cout << "Draw" << endl;
                    return 10;
                }
                else {
                    cout << "AI wins as it has less cards! " << endl;
                    return 0;
                }
            }
            else if (numofai == 2) {
                if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                    cout << "You Win as you have less cards! " << endl;
                    return (100-drawcount/2);
                    break;
                }
                else if (aiPile.size() == PlayerPile.size() && PlayerPile.size() == aiPile2.size()) {
                    cout << "Draw" << endl;
                    return 20;
                }
                else {
                    cout << "AI wins as it has less cards! " << endl;
                    return 00;
                }
            }


        }
        cout << " ==================== " << endl;
        cout << "||";
        typewriter("  Top card is ", 100000);
        PrintCard(firstcard % 13, firstcard / 13);
        usleep (500000);
        cout << "" << "||" << endl;
        cout << " ==================== " << endl;
        cout << "AI_1 plays: ";
        if (!AI(firstcard, aiPile)) {        //AI draws card
            card = rand() % 52;
            while (DrawPile[card] == -1) {
                card = rand() % 52;
            }
            aiPile.push_back(card);
            DrawPile[card] = -1;
            cout << "AI_1 drew a card" << endl;
            cout << "AI_1 has " << aiPile.size() << " cards left" << endl;
            cout << endl << endl;

            drawcount += 1;
            cout << " =================== "                << endl;
            cout << "||" << "  Deck size: " << setw(2) << 52 - drawcount << "  " << "||" << endl;
            cout << " =================== "                << endl;
        }
        cout << endl;
        cout << endl;


        if (aiPile.size() == 0) {
            win = true;
            cout << "AI_1 wins!" << endl;
            return 0;
            break;
        }
        else if (drawcount == 52) {                          //Draw condition
            win = true;
            if (numofai == 1) {
                if (PlayerPile.size() < aiPile.size()) {
                    cout << "You Win as you have less cards! " << endl;
                    return (50-drawcount/2);
                    break;
                }
                else if (aiPile.size() == PlayerPile.size()) {
                    cout << "Draw" << endl;
                    return 10;
                }
                else {
                    cout << "AI wins as it has less cards! " << endl;
                    return 0;
                }
            }
            else if (numofai == 2) {
                if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                    cout << "You Win as you have less cards! " << endl;
                    return (100-drawcount/2);
                    break;
                }
                else if (aiPile.size() == PlayerPile.size() && PlayerPile.size() == aiPile2.size()) {
                    cout << "Draw" << endl;
                    return 20;
                }
                else {
                    cout << "AI wins as it has less cards." << endl;
                    return 0;
                }
            }



        }

        cout << " ==================== " << endl;
        cout << "||";
        typewriter("  Top card is ", 100000);
        PrintCard(firstcard % 13, firstcard / 13);
        usleep (500000);
        cout << "" << "||" << endl;
        cout << " ==================== " << endl;

        if (numofai == 2) {                                        //Code for AI number 2
            cout << "AI_2 plays: ";
            if (!AI(firstcard, aiPile2)) {        //AI draws card
                card = rand() % 52;
                while (DrawPile[card] == -1) {
                    card = rand() % 52;
                }
                aiPile2.push_back(card);
                DrawPile[card] = -1;
                cout << "AI_2 drew a card" << endl;
                cout << "AI_2 has " << aiPile2.size() << " cards left" << endl;
                cout << endl << endl;

                drawcount += 1;
                cout << " =================== "                << endl;
                cout << "||" << "  Deck size: " << setw(2) << 52 - drawcount << "  " << "||" << endl;
                cout << " =================== "                << endl;
            }
            cout << endl;
            cout << endl;



            if (aiPile2.size() == 0) {
                win = true;
                cout << "AI_2 wins!" << endl;
                return 0;
                break;
            }
            else if (drawcount == 52) {                          //Draw condition
                win = true;
                if (numofai == 1) {
                    if (PlayerPile.size() < aiPile.size()) {
                        cout << "       YOU WIN!" << endl;
                        return (50-drawcount/2);
                        break;
                    }
                    else if (aiPile.size() == PlayerPile.size()) {
                        cout << "Draw" << endl;
                        return 10;
                    }
                    else {
                        cout << "AI wins as it has less cards." << endl;
                        return 0;
                    }
                }
                else if (numofai == 2) {
                    if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                        cout << "       YOU WIN!" << endl;
                        return (100-drawcount/2);
                        break;
                    }
                    else if (aiPile.size() == PlayerPile.size() && PlayerPile.size() == aiPile2.size()) {
                        cout << "Draw" << endl;
                        return 20;
                    }
                    else {
                        cout << "AI wins as it has less cards." << endl;
                        return 0;
                    }
                }


            }

            cout << " ==================== " << endl;
            cout << "||";
            typewriter("  Top card is ", 100000);
            PrintCard(firstcard % 13, firstcard / 13);
            usleep (500000);
            cout << "" << "||" << endl;
            cout << " ==================== " << endl;

        }



    }                                                                 //End of while game loop
    return 0;
}



//Print Rules of Crazy Eights
//No input, no return, only print
void PrintRules() {

    cout << endl;
    cout << " ========================================================== "                << endl;
    cout << "||" << "                 Rules of Crazy Eights                  " << "||"    << endl;
    cout << "||" << "                                                        " << "||"    << endl;
    cout << "||" << "       A poker UNO game with 1 deck of 52 cards!        " << "||"    << endl;
    cout << "||" << "   Your goal: Finish the card before AI to get points   " << "||"    << endl;
    cout << "||" << "   In each turn, play a card that matches the top card  " << "||"    << endl;
    cout << "||" << "        by suit or rank, or play 8 (wild card)          " << "||"    << endl;
    cout << "||" << "       then you can choose which suit goes next         " << "||"    << endl;
    cout << "||" << "   If you can't play in a turn, draw 1 card instead     " << "||"    << endl;
    cout << "||" << "                                                        " << "||"    << endl;
    cout << "||" << "      If the whole deck is drawn, the player with       " << "||"    << endl;
    cout << "||" << "            fewer cards left in hand wins!              " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    cout << "Enter anything to continue...   "; string _enter;
    getline (cin, _enter); getline (cin, _enter); cout << endl;

}



//Main function for Crazy Eights. It gives option to read rules, start game and choose number of AI to play against
//Takes in player's name and their current score. No output
int unomain(string name, int& playerscore) {

    string numofai, startchoice;

    cout << " ========================================================== "                << endl;
    cout << "||" << "  Hi there! Welcome to the Crazy Eights!                " << "||"    << endl;
    cout << "||" << "  Enter 1:  Play                                        " << "||"    << endl;
    cout << "||" << "  Enter 2:  Read rules and Play                         " << "||"    << endl;
    cout << " ========================================================== "                << endl;

    startchoice = "0";

    while (startchoice != "1" && startchoice != "2") {
        cout << "Your option: " ;
        cin >> startchoice;

        if (startchoice == "1") {
            cout << endl << endl;
            cout << " ========================================================== "                << endl;
            cout << "||" << "  Enter number of AIs you'd like to play with (1 or 2)  " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout << "Your choice: ";
            cin >> numofai;

            while ( numofai != "1" && numofai != "2" ) {
                cout << endl << "⚠️  Sorry, " << numofai << " is an invalid option. Please enter 1 or 2" << endl;
                cout << "Your choice: ";
                cin >> numofai;
            }


            cout << endl;
            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  Before this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "              " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout.flush();
            usleep(500000);

            if (numofai == "1") {playerscore += StartGame (1); }
            if (numofai == "2") {playerscore += StartGame (2); }


            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  After this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "               " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            break;
        }
        else if (startchoice == "2") {

            PrintRules();
            cout << endl << endl;
            cout << " ========================================================== "                << endl;
            cout << "||" << "  Enter number of AIs you'd like to play with (1 or 2)  " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout << "Your choice: ";
            cin >> numofai;

            while ( numofai != "1" && numofai != "2" ) {
                cout << endl << "⚠️  Sorry, " << numofai << " is an invalid option. Please enter 1 or 2" << endl;
                cout << "Your choice: ";
                cin >> numofai;
            }

            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  Before this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "              " << "||"    << endl;
            cout << " ========================================================== "                << endl;

            if (numofai == "1") {playerscore += StartGame (1); }
            if (numofai == "2") {playerscore += StartGame (2); }

            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  After this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "               " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            break;
        }
        else {
            cout << endl << "⚠️  Sorry, " << startchoice << " is an invalid option. Please enter 1 or 2" << endl;
        }
    }
    cout << " ========================================================== "                << endl;
    cout << "||" << "     Round over, thanks for playing Crazy Eights!       " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    string _enter;
    getline (cin, _enter);
    cout << "Enter anything to go back to the main menu...   ";
    getline (cin, _enter);
    cout << endl << endl;

    return 0;
}
