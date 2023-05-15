//  Author:       Senthil Kumar Sapnesh  (3035790850)
//  Description:  Implementation of Crazy Eights game (Similar to Uno).
//                All Functions needed for this game is in this c++ code.

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

#include "Unomain.h"

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

//  Define the suit characters for the poker cards

using namespace std;






//  Print out like a typewriter
//  Takes in a string line and speed of output. Prints string line at speed.
void typewriter(string line, int speed) {
    for (int i = 0; i < line.length(); i++) {
        cout << line[i];
        cout.flush();
        usleep(speed);
    }
}

// This function prints the playing cards with the symbol and rank
//  Prints the cards given by number and suit (Takes in the rank of a card and its corresponding suit in terms of an integer)
//  Also prints them out like a typewriter
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

//  Prints out the cards in the player's hand by taking in the player's pile
void PrintHand(vector<int> PlayerPile) {             //  print player's cards
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

//  Checks if a card played by player and AI is valid or not
//  Takes in the card played by player and top card on deck. Outputs true if valid and false otherwise
bool ValidChecker(int& card, int firstcard) {
    int firstcardnum = firstcard % 13;
    int firstcardsuit = firstcard / 13;
    int number = card % 13;
    int suit = card / 13;
    if (number == 7) {

        int wildsuit = 0;
        string wildsuit_str = ""; 

        cout << " ========================================================== "                << endl;
        cout << "||" << "  You have played a WILD CARD                           " << "||"    << endl;
        cout << "||" << "  Please choose the suit that you want                  " << "||"    << endl;
        cout << "||" << "  0 for SPADES          1 for HEARTS                    " << "||"    << endl;
        cout << "||" << "  2 for CLUBS           3 for DIAMONDS                  " << "||"    << endl;
        cout << " ========================================================== "                << endl;
        
        cout << "Your choice: ";
        getline(cin, wildsuit_str);
        while (wildsuit_str != "0" && wildsuit_str != "1" && wildsuit_str != "2" && wildsuit_str != "3") {
            cout << endl << "Invalid suit. Please enter a number between 0 and 3. " << endl; 
            cout << "Your choice: ";
            getline(cin, wildsuit_str);
        }

        wildsuit = wildsuit_str[0] - '0'; 
        card = wildsuit * 13 + firstcardnum;

        if      (wildsuit == 0) {cout << "The suit has been changed into: SPADES!   "   << endl << endl; }
        else if (wildsuit == 1) {cout << "The suit has been changed into: HEARTS!   "   << endl << endl; }
        else if (wildsuit == 2) {cout << "The suit has been changed into: CLUBS!    "   << endl << endl; }
        else                    {cout << "The suit has been changed into: DIAMONDS! "   << endl << endl; }

        usleep (1000000);

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

//  This function deals with the cards played by AIs. Checks if AI has any valid cards to play
//  Takes in firstcard and the AI's cards pile. Outputs true if a valid card has been player and false otherwise
bool AI (int& firstcard, vector<int>& aiPile, string AI_id) {

    // AI re-arranges its card to put the suits in order
    // AI counts and finds the most suit it has
    int cardcount[4] = {0, 0, 0, 0}; 
    vector<int> AI_SPADES; 
    vector<int> AI_HEARTS; 
    vector<int> AI_CLUBS; 
    vector<int> AI_DIAMONDS; 
    for (int card = 0; card < aiPile.size(); card++) {
        if (aiPile[card] / 13 == 0) {
            AI_SPADES.push_back(aiPile[card]); 
        }
        if (aiPile[card] / 13 == 1) {
            AI_HEARTS.push_back(aiPile[card]); 
        }
        if (aiPile[card] / 13 == 2) {
            AI_CLUBS.push_back(aiPile[card]); 
        }
        if (aiPile[card] / 13 == 3) {
            AI_DIAMONDS.push_back(aiPile[card]); 
        }
        if (aiPile[card] % 13 != 7) {
            cardcount[aiPile[card] / 13] += 1; 
        }
    }
    // Bubble sort, Reverse order
    int suits[4] = {0, 1, 2, 3}; 
    for (int p = 0; p < 3; p++){
        for (int q = 0; q < 3 - p; q++) {
            if (cardcount[q] < cardcount[q+1]) {
                int temp = 0; 
                temp = cardcount[q]; 
                cardcount[q] = cardcount[q+1]; 
                cardcount[q+1] = temp; 
                temp = suits[q]; 
                suits[q] = suits[q+1]; 
                suits[q+1] = temp; 
            }
        }
    }

    // AI re-arranges its card to put the most suit it has in the beginning
    // Try to play those cards first
    aiPile.clear(); 
    for (int s = 0; s < 4; s++) {
        if (suits[s] == 0) {
            // cout << endl << "AI SPADES: "; 
            for (int i = 0; i < AI_SPADES.size(); i++) {
                aiPile.push_back(AI_SPADES[i]); 
                // cout << AI_SPADES[i] << " "; 
            }
        }
        if (suits[s] == 1) {
            // cout << endl << "AI HEARTS: "; 
            for (int i = 0; i < AI_HEARTS.size(); i++) {
                aiPile.push_back(AI_HEARTS[i]); 
                // cout << AI_HEARTS[i] << " "; 
            }
        }
        if (suits[s] == 2) {
            // cout << endl << "AI CLUBS: "; 
            for (int i = 0; i < AI_CLUBS.size(); i++) {
                aiPile.push_back(AI_CLUBS[i]); 
                // cout << AI_CLUBS[i] << " "; 
            }
        }
        if (suits[s] == 3) {
            // cout << endl << "AI DIAMONDS: "; 
            for (int i = 0; i < AI_DIAMONDS.size(); i++) {
                aiPile.push_back(AI_DIAMONDS[i]); 
                // cout << AI_DIAMONDS[i] << " "; 
            }
        }
    }
    // cout << endl << "AI SUITS: "; 
    for (int i = 0; i < (sizeof(suits)/sizeof(int)); i++) {
        // cout << suits[i] << " "; 
    }
    // cout << endl << "AI CARDCOUNT: "; 
    for (int i = 0; i < (sizeof(cardcount)/sizeof(int)); i++) {
        // cout << cardcount[i] << " "; 
    }
    // cout << endl << endl; 
    // usleep(3000000); 

    // AI re-arranges its card to put all eights to the back
    // Only play them when no other card can be played
    vector<int> non_eights; 
    vector<int> eights; 
    for (int i = 0; i < aiPile.size(); i++) {
        if (aiPile[i] % 13 == 7) {eights.push_back(aiPile[i]); }
        else {non_eights.push_back(aiPile[i]); }
    } 
    aiPile.clear(); 
    for (int i = 0; i < non_eights.size(); i++) {
        aiPile.push_back(non_eights[i]); 
    }
    for (int i = 0; i < eights.size(); i++) {
        aiPile.push_back(eights[i]); 
    }

    int firstcardnum = firstcard % 13, firstcardsuit = firstcard / 13;

    for (int i = 0; i < aiPile.size(); i++) {

        int number, suit;
        number = aiPile[i] % 13;
        suit = aiPile[i] / 13;

        if (number == firstcardnum || number == 7) {

            if (number != 7) {
                typewriter ("AI_" + AI_id + " has played: ", 100000);
                PrintCard (number, suit);
                firstcard = aiPile[i];
                aiPile.erase(aiPile.begin() + i);
                cout << endl;
                usleep (1000000);
            }

            else {

                typewriter ("AI_" + AI_id + " plays: ", 100000);
                PrintCard (number, suit);
                cout << endl;
                usleep (1000000);
                cout << "AI_" + AI_id + " has played a WILD CARD. IT has chosen the suit: "; 
                usleep (1000000);

                // AI plays a while card
                // AI chooses the most suit it has
                int wildsuit = suits[0]; 

                switch (wildsuit) {
                case 0:
                    cout << "SPADES" << endl;
                    break;
                case 1:
                    cout << "HEARTS" << endl;
                    break;
                case 2:
                    cout << "CLUBS" << endl;
                    break;
                case 3:
                    cout << "DIAMONDS" << endl;
                    break;
                }
                usleep (1000000);

                if      (wildsuit == 0) {cout << "The suit has been changed into: SPADES!   "   << endl << endl; }
                else if (wildsuit == 1) {cout << "The suit has been changed into: HEARTS!   "   << endl << endl; }
                else if (wildsuit == 2) {cout << "The suit has been changed into: CLUBS!    "   << endl << endl; }
                else                    {cout << "The suit has been changed into: DIAMONDS! "   << endl << endl; }

                firstcard = wildsuit * 13 + firstcardnum;
                aiPile.erase(aiPile.begin() + i);
                usleep (1000000); 
            }
            cout << "AI_" + AI_id + " has " << aiPile.size() << " card";
            if (aiPile.size() >= 2) {cout << "s"; }
            cout << " left. " << endl;
            usleep (1000000);
            return true;
        }

        else if (suit == firstcardsuit) {
            typewriter ("AI_" + AI_id + " has played: ", 100000);
            PrintCard (number, suit);
            firstcard = aiPile[i];
            aiPile.erase(aiPile.begin() + i);
            cout << endl;
            usleep (1000000);
            cout << "AI_" + AI_id + " has " << aiPile.size() << " card";
            if (aiPile.size() >= 2) {cout << "s"; }
            cout << " left. " << endl;
            usleep (1000000);
            return true;
        }
    }

    cout.flush();
    usleep (50000);
    cout.flush();
    return false;
}

// Check whether the input is an integer
int checkInteger(string num) {
    if (num == "") {return false; }
    if (num[0] == '-') {
        num = num.substr(1, num.length() - 1); 
        if (num == "") {return false; }
    }
    for (int i = 0; i < num.length(); i++) {
        if (num[i] < '0' || num[i] > '9') {
            return false; 
        }
    } return true; 
}

//  Starts a new game of Crazy Eights. Handles each player's turn of playing a card and drawing a card
//  Takes in the number of AI player has chosen. Returns the score after game ends.
int StartGame (int numofai, string name, int achievment[3]) {       //Starts the game

    system ("clear");

    vector<int> PlayerPile, aiPile, aiPile2;
    int DrawPile[52], card;

    for (int i = 0; i < 52; i++) {       //  Creating draw pile
        DrawPile[i] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < 7; i++) {         //  Create card hand for player
        card = rand() % 52;
        while (DrawPile[card] == -1) {
            card = rand() % 52;
        }
        PlayerPile.push_back(card);
        DrawPile[card] = -1;
    }

    for (int j = 0; j < 7; j++) {      //  Create card hand for AI
        card = rand() % 52;
        while (DrawPile[card] == -1) {         //  Make sure cards do not overlap with cards that are drawn out from drawpile
            card = rand() % 52;
        }
        aiPile.push_back(card);
        DrawPile[card] = -1;
    }

    if (numofai == 2) {
        for (int j = 0; j < 7; j++) {      //  Create card hand for AI2
            card = rand() % 52;
            while (DrawPile[card] == -1) {         //  Make sure cards do not overlap with cards that are drawn out from drawpile
                card = rand() % 52;
            }
            aiPile2.push_back(card);
            DrawPile[card] = -1;
        }
    }

    bool win = false;
    int firstcard, drawcount;

    if (numofai == 1){
      drawcount = 15;  // 15 cards used
    }
    else{
      drawcount = 22;  // 22 cards used
    }

    firstcard = rand() % 52;          //  Make opening card
    while (DrawPile[firstcard] == -1) {
        firstcard = rand() % 52;
    }
    DrawPile[firstcard] = -1;
    int number, suit;
    number = firstcard % 13;
    suit = firstcard / 13;

    system ("clear");

    cout <<    " ======================== " << endl;
    typewriter ("||  Opening card is ", 100000);                                       //Print opening card
    PrintCard (number, suit);
    cout << "" << "||" << endl;
    cout <<    " ======================== " << endl;
    usleep (1000000);
    cout << " ==================== "                << endl;
    cout << "||" << "  Deck size:  " << setw(2) << 52 - drawcount << "  " << "||" << endl;
    cout << " ==================== "                << endl;
    usleep (1000000);
    cout << " ========================================================== "                << endl;
    cout << "||" << "                    It is YOUR turn!                    " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    usleep (1000000);
    cout << endl;
    card = firstcard;

    int cardindex; string _trash;

    while (!win) {                                                   //  Start of actual game

        card = firstcard;
        cout << " ========================================================== " << endl;
        cout << "||" << "  Your cards are:                                       " << "||"    << endl;
        PrintHand (PlayerPile);
        cout << " ========================================================== " << endl;

        cout << " ========================================================== "                << endl;
        cout << "||" << "  Your turn. Please play a valid card or                " << "||"    << endl;
        cout << "||" << "  enter -1 to draw a card from the Draw pile            " << "||"    << endl;
        cout << " ========================================================== "                << endl;

        string cardindex_string = ""; 

        cout << "Your choice: ";
        while (cardindex_string == "") {
            getline(cin, cardindex_string); 
        }

        while (!checkInteger(cardindex_string)) {
            cout << endl << "Sorry, Please enter -1 or a number between 0 and " << PlayerPile.size() - 1 << endl;
            cout << "Your choice: ";
            cardindex_string = ""; 
            while (cardindex_string == "") {
                getline(cin, cardindex_string); 
            }
        }

        stringstream s; 
        s << cardindex_string; 
        s >> cardindex; 

        if (cardindex != -1) {

            card = PlayerPile[cardindex];
            bool notdraw = true;
            while (!ValidChecker(card, firstcard)) {

                if (cardindex != -1) {

                    cout << " ========================================================== "                << endl;
                    cout << "||";
                    if (cardindex >= 0 && cardindex <= PlayerPile.size() - 1) {
                        PrintCard(card % 13, card / 13);
                        cout << " is an invalid card. Please choose another to play  " << "||"    << endl;
                    } else {
                        cout << " The card id doesn't exist, please choose a valid id" << "||"    << endl;
                    }
                    cout << " ========================================================== "                << endl;
                    cout << "Your choice: ";
                    cin >> cardindex;
                    if (cardindex != -1) {
                        card = PlayerPile[cardindex];
                    }

                }
                else if (cardindex == -1) {                             //  Draw card for player
                    card = rand() % 52;
                    while (DrawPile[card] == -1) {
                        card = rand() % 52;
                    }
                    PlayerPile.push_back(card);
                    DrawPile[card] = -1;
                    cout << "You drew ";
                    PrintCard(card % 13, card / 13);
                    usleep (2000000);

                    cout << endl << endl;

                    notdraw = false;
                    break;
                }
            }
            if (notdraw) {
                if (PlayerPile[cardindex] % 13 != 7) {
                    cout << "You have played: ";
                    PrintCard (PlayerPile[cardindex] % 13, PlayerPile[cardindex] / 13); 
                    usleep (2000000);
                }
                PlayerPile.erase(PlayerPile.begin() + cardindex);
                firstcard = card;
            }

        }

        else if (cardindex == -1) {                    //  Player draws new card
            card = rand() % 52;
            while (DrawPile[card] == -1) {
                card = rand() % 52;
            }
            PlayerPile.push_back(card);
            DrawPile[card] = -1;
            cout << "You drew ";
            PrintCard(card % 13, card / 13);
            usleep (2000000);

            cout << endl << endl;
        }

        if (PlayerPile.size() == 0) {                            //  Win conditions
            win = true;

            system ("clear");

            cout << " ========================================================== "      << endl;
            cout << "||" << "  YOU WIN as you have played all of your cards!" << "         " << "||" << endl;
            cout << " ========================================================== "      << endl;
            usleep (3000000);  

            if (numofai == 1) {
                achievment[0] = 50 - (drawcount - 15) / 2;
                achievment[1] = drawcount;
                achievment[2] = 2;
                return (50 - (drawcount - 15) / 2);  //  note:  Avoid decimals
            }
            else {
                achievment[0] = 100 - (drawcount - 22);
                achievment[1] = drawcount;
                achievment[2] = 2;
                return (100 - (drawcount - 22));
            }



            break;
        }

        else if (drawcount == 52) {                          //  Draw condition
            win = true;

            system ("clear");

            cout << " ========================================================== "      << endl;
            cout << "||" << "  All of the cards in the deck have been drawn!" << "         " << "||" << endl;

            if (numofai == 1) {
                if (PlayerPile.size() < aiPile.size()) {
                    achievment[0] = 20;
                    achievment[1] = 52;
                    achievment[2] = 12;
                    cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 20;
                }
                else if (aiPile.size() == PlayerPile.size()) {
                    achievment[0] = 10;
                    achievment[1] = 52;
                    achievment[2] = 11;
                    cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                    cout << " ========================================================== "           << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 10;
                }
                else {
                    achievment[0] = 0;
                    achievment[1] = 52;
                    achievment[2] = 10;
                    string AI_win = "1"; 
                    cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 0;
                }
            }
            else if (numofai == 2) {
                if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                    achievment[0] = 40;
                    achievment[1] = 52;
                    achievment[2] = 12;
                    cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 40;
                }
                else if (aiPile.size() <= PlayerPile.size() && PlayerPile.size() <= aiPile2.size()) {
                    achievment[0] = 20;
                    achievment[1] = 52;
                    achievment[2] = 11;
                    cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                    cout << " ========================================================== "           << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 20;
                }
                else {
                    achievment[0] = 0;
                    achievment[1] = 52;
                    achievment[2] = 10;
                    string AI_win = "1"; if (aiPile2.size() < aiPile.size()) {AI_win = "2";}
                    cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 0;
                    //  When the game ends, output the game result
                }
            }


        }

        //  The game comes to AI_1's turn

        system ("clear");

        cout << " ==================== " << endl;
        cout << "||";
        typewriter("  Top card is ", 100000);
        PrintCard (firstcard % 13, firstcard / 13);
        cout << "" << "||" << endl;
        cout << " ==================== " << endl;
        usleep (1000000);
        cout << " ==================== "                << endl;
        cout << "||" << "  Deck size:  " << setw(2) << 52 - drawcount << "  " << "||" << endl;
        cout << " ==================== "                << endl;
        usleep (1000000);
        cout << " ========================================================== "                << endl;
        cout << "||" << "                   It is AI_1's turn!                   " << "||"    << endl;
        cout << " ========================================================== "                << endl;
        usleep (1000000);

        if (!AI(firstcard, aiPile, "1")) {        //  AI_1 draws card
            card = rand() % 52;
            while (DrawPile[card] == -1) {
                card = rand() % 52;
            }
            aiPile.push_back(card);
            DrawPile[card] = -1;
            cout << "AI_1 drew a card. " << endl;
            usleep (1000000);
            cout << "AI_1 has " << aiPile.size() << " cards left. " << endl;
            drawcount += 1;
        } usleep (1000000);

        if (aiPile.size() == 0) {
            win = true;

            system ("clear");

            achievment[0] = 0;
            achievment[1] = drawcount;
            achievment[2] = 0;
            cout << " ========================================================== "      << endl;
            cout << "||" << "  AI_1 wins as it has played all of its cards! " << "         " << "||" << endl;
            cout << " ========================================================== "      << endl;
            usleep(3000000);
            cout << "Enter anything to continue...   ";
            string _enter; getline (cin, _enter);
            cout << endl << endl;

            return 0;
            break;
        }

        else if (drawcount == 52) {                          //  Draw condition
            win = true;

            system ("clear");

            cout << " ========================================================== "      << endl;
            cout << "||" << "  All of the cards in the deck have been drawn!" << "         " << "||" << endl;

            if (numofai == 1) {
                if (PlayerPile.size() < aiPile.size()) {
                    achievment[0] = 20;
                    achievment[1] = 52;
                    achievment[2] = 12;
                    cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 20;
                }
                else if (aiPile.size() == PlayerPile.size()) {
                    achievment[0] = 10;
                    achievment[1] = 52;
                    achievment[2] = 11;
                    cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                    cout << " ========================================================== "           << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 10;
                }
                else {
                    achievment[0] = 0;
                    achievment[1] = 52;
                    achievment[2] = 10;
                    string AI_win = "1";
                    cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 0;
                }
            }
            else if (numofai == 2) {
                if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                    achievment[0] = 40;
                    achievment[1] = 52;
                    achievment[2] = 12;
                    cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 40;
                }
                else if (aiPile.size() <= PlayerPile.size() && PlayerPile.size() <= aiPile2.size()) {
                    achievment[0] = 20;
                    achievment[1] = 52;
                    achievment[2] = 11;
                    cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                    cout << " ========================================================== "           << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 20;
                }
                else {
                    achievment[0] = 0;
                    achievment[1] = 52;
                    achievment[2] = 10;
                    string AI_win = "1"; if (aiPile2.size() < aiPile.size()) {AI_win = "2";}
                    cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                    cout << " ========================================================== "      << endl;
                    usleep(3000000);
                    cout << "Enter anything to continue...   ";
                    string _enter; getline (cin, _enter);
                    cout << endl << endl;

                    return 0;
                    //  When the game ends, output the game result
                }
            }

        }

        if (numofai == 2) {                                        //  Code for AI number 2
            system ("clear");
            cout << " ==================== " << endl;
            cout << "||";
            typewriter("  Top card is ", 100000);
            PrintCard (firstcard % 13, firstcard / 13);
            cout << "" << "||" << endl;
            cout << " ==================== " << endl;
            usleep (1000000);
            cout << " ==================== "                << endl;
            cout << "||" << "  Deck size:  " << setw(2) << 52 - drawcount << "  " << "||" << endl;
            cout << " ==================== "                << endl;
            usleep (1000000);
            cout << " ========================================================== "                << endl;
            cout << "||" << "                   It is AI_2's turn!                   " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            usleep (1000000);

            //  The game comes to AI_2's turn (if applicable)

            if (!AI (firstcard, aiPile2, "2")) {        //  AI draws card
                card = rand() % 52;
                while (DrawPile[card] == -1) {
                    card = rand() % 52;
                }
                aiPile2.push_back(card);
                DrawPile[card] = -1;
                cout << "AI_2 drew a card" << endl;
                usleep (1000000);
                cout << "AI_2 has " << aiPile2.size() << " cards left. " << endl;
                drawcount += 1;
            }
            usleep (1000000);

            if (aiPile2.size() == 0) {
                win = true;

                system ("clear");

                achievment[0] = 0;
                achievment[1] = drawcount;
                achievment[2] = 0;
                cout << " ========================================================== "      << endl;
                cout << "||" << "  AI_2 wins as it has played all of its cards! " << "         " << "||" << endl;
                cout << " ========================================================== "      << endl;
                usleep(3000000);
                cout << "Enter anything to continue...   ";
                string _enter; getline (cin, _enter);
                cout << endl << endl;

                return 0;
                break;


            }


            else if (drawcount == 52) {                          //  Draw condition
                win = true;

                system ("clear");

                cout << " ========================================================== "      << endl;
                cout << "||" << "  All of the cards in the deck have been drawn!" << "         " << "||" << endl;

                if (numofai == 1) {
                    if (PlayerPile.size() < aiPile.size()) {
                        achievment[0] = 20;
                        achievment[1] = 52;
                        achievment[2] = 12;
                        cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                        cout << " ========================================================== "      << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 20;
                    }
                    else if (aiPile.size() == PlayerPile.size()) {
                        achievment[0] = 10;
                        achievment[1] = 52;
                        achievment[2] = 11;
                        cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                        cout << " ========================================================== "           << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 10;
                    }
                    else {
                        achievment[0] = 0;
                        achievment[1] = 52;
                        achievment[2] = 10;
                        string AI_win = "1";
                        cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                        cout << " ========================================================== "      << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 0;
                    }
                }
                else if (numofai == 2) {
                    if (PlayerPile.size() < aiPile.size() && PlayerPile.size() < aiPile2.size()) {
                        achievment[0] = 40;
                        achievment[1] = 52;
                        achievment[2] = 12;
                        cout << "||" << "  YOU WIN as you have the least cards remaining!" << "        " << "||" << endl;
                        cout << " ========================================================== "      << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 40;
                    }
                    else if (aiPile.size() <= PlayerPile.size() && PlayerPile.size() <= aiPile2.size()) {
                        achievment[0] = 20;
                        achievment[1] = 52;
                        achievment[2] = 11;
                        cout << "||" << "  Players have same amount of cards remaining. Draw!" << "    " << "||" << endl;
                        cout << " ========================================================== "           << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 20;
                    }
                    else {
                        achievment[0] = 0;
                        achievment[1] = 52;
                        achievment[2] = 10;
                        string AI_win = "1"; if (aiPile2.size() < aiPile.size()) {AI_win = "2";}
                        cout << "||" << "  AI_" << AI_win << " wins as it has the least cards remaining!" << "        " << "||" << endl;
                        cout << " ========================================================== "      << endl;
                        usleep(3000000);
                        cout << "Enter anything to continue...   ";
                        string _enter; getline (cin, _enter);
                        cout << endl << endl;

                        return 0;

                        //  When the game ends, output the game result
                    }
                }


            }
        }

        system ("clear");

        cout << " ==================== " << endl;
        cout << "||";
        typewriter("  Top card is ", 100000);
        PrintCard (firstcard % 13, firstcard / 13);
        cout << "" << "||" << endl;
        cout << " ==================== " << endl;
        usleep (1000000);
        cout << " ==================== "                << endl;
        cout << "||" << "  Deck size:  " << setw(2) << 52 - drawcount << "  " << "||" << endl;
        cout << " ==================== "                << endl;
        usleep (1000000);
        cout << " ========================================================== "                << endl;
        cout << "||" << "                    It is YOUR turn!                    " << "||"    << endl;
        cout << " ========================================================== "                << endl;
        usleep (1000000);

        //  The game comes to your turn

    }                                                                 //  End of while game loop
    return 0;
}

// This function prints out the scoreboard after the round.
// Takes in number of ais, achievements and the name of player and prints out a scoreboard.
//  At the same time, have the file output for this round ready.
void show_result (int numofai, int achievment[3], string name) {

    system ("clear");

    string _scoreboard_line = "Here is " + name + "'s scoreboard for this round: ";
    typewriter (_scoreboard_line, 100000);
    usleep (1000000);

    cout << endl;

    cout << " ========================================================== "                                                   << endl;
    cout << "||" << "                     Crazy Eights                       " << "||" << endl;
    cout << "||" << "                                                        " << "||" << endl;
    cout << "||" << setw(20) << "  Game Mode: "       << setw(12) << numofai << " AIs"                      << "                    " << "||" << endl;
    cout << "||" << setw(20) << "  Cards remained: "      << setw(16) << 52 - achievment[1]                 << "                    " << "||" << endl;

    if (achievment[2] == 0)   {cout << "||" << setw(20) << "  Game status: " << setw(16) << "AI wins!" << "                    " << "||" << endl;}
    if (achievment[2] == 2)   {cout << "||" << setw(20) << "  Game status: " << setw(16) << "YOU WIN!" << "                    " << "||" << endl;}
    if (achievment[2] == 10)  {cout << "||" << setw(20) << "  Game status: " << setw(16) << "AI wins!" << "                    " << "||" << endl;}
    if (achievment[2] == 11)  {cout << "||" << setw(20) << "  Game status: " << setw(16) << "Draw!"    << "                    " << "||" << endl;}
    if (achievment[2] == 12)  {cout << "||" << setw(20) << "  Game status: " << setw(16) << "YOU WIN!" << "                    " << "||" << endl;}

    cout << "||" << "                                                        "                                                   << "||" << endl;
    cout << "||" << setw(20) << "  Overall Score: "                       << setw(16) << achievment[0] << "                    " << "||" << endl;
    cout << " ========================================================== "                                           << endl;


    ofstream fout;
    fout.open(" [Game result]  " + name + ".txt", ios::app);
    fout << " ========================================================== "      << endl;
    fout << "||" << "                     Crazy Eights                       " << "||" << endl;
    fout << "||" << "                                                        " << "||" << endl;
    fout << "||" << setw(20) << "  Game Mode: "       << setw(12) << numofai << " AIs"                      << "                    " << "||" << endl;
    fout << "||" << setw(20) << "  Cards remained: "      << setw(16) << 52 - achievment[1]                 << "                    " << "||" << endl;

    if (achievment[2] == 0)   {fout << "||" << setw(20) << "  Game status: " << setw(16) << "AI wins!" << "                    " << "||" << endl;}
    if (achievment[2] == 2)   {fout << "||" << setw(20) << "  Game status: " << setw(16) << "YOU WIN!" << "                    " << "||" << endl;}
    if (achievment[2] == 10)  {fout << "||" << setw(20) << "  Game status: " << setw(16) << "AI wins!" << "                    " << "||" << endl;}
    if (achievment[2] == 11)  {fout << "||" << setw(20) << "  Game status: " << setw(16) << "Draw!"    << "                    " << "||" << endl;}
    if (achievment[2] == 12)  {fout << "||" << setw(20) << "  Game status: " << setw(16) << "YOU WIN!" << "                    " << "||" << endl;}

    fout << "||" << "                                                        "                                                   << "||" << endl;
    fout << "||" << setw(20) << "  Overall Score: "                       << setw(16) << achievment[0] << "                    " << "||" << endl;
    fout << " ========================================================== "      << endl;
    fout << endl << endl;
    fout.close();

    cout << "Enter anything to end this round...   ";
    string _enter; getline (cin, _enter);
    cout << endl << endl;

}

//  Print Rules of Crazy Eights
//  No input, no return, only print
void PrintRules() {

    system ("clear");
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
    cout << "Enter anything to start...   "; string _enter;
    getline (cin, _enter); getline (cin, _enter); cout << endl;
}

//  Main function for Crazy Eights. It gives option to read rules, start game and choose number of AI to play against
//  Takes in player's name and their current score. No output
int unomain(string name, int& playerscore) {

    string numofai, startchoice;
    int achievment[3] = {0, 0, 0};    // score, cards used, game status

    system ("clear");

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

            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||" << "  Enter number of AIs you'd like to play with (1 or 2)  " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout << "Your choice: ";
            cin >> numofai;

            while ( numofai != "1" && numofai != "2" ) {
                cout << endl << "Sorry, " << numofai << " is an invalid option. Please enter 1 or 2" << endl;
                cout << "Your choice: ";
                cin >> numofai;
            }

            cout << endl;
            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  Before this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "              " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout.flush();

            usleep (1000000); 
            cout << "Enter anything to continue...   ";
            string _enter; getline (cin, _enter); getline (cin, _enter); cout << endl << endl;

            if (numofai == "1") {playerscore += StartGame (1, name, achievment); }
            if (numofai == "2") {playerscore += StartGame (2, name, achievment); }

            system ("clear");

            if (numofai == "1") {show_result (1, achievment, name);}
            if (numofai == "2") {show_result (2, achievment, name);}

            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  After this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "               " << "||"    << endl;
            cout << " ========================================================== "                << endl;

            usleep (1000000); 
            cout << "Enter anything to continue...   ";
            getline (cin, _enter); cout << endl << endl;

            break;
        }
        else if (startchoice == "2") {

            PrintRules();

            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||" << "  Enter number of AIs you'd like to play with (1 or 2)  " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            cout << "Your choice: ";
            cin >> numofai;

            while ( numofai != "1" && numofai != "2" ) {
                cout << endl << "Sorry, " << numofai << " is an invalid option. Please enter 1 or 2" << endl;
                cout << "Your choice: ";
                cin >> numofai;
            }

            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  Before this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "              " << "||"    << endl;
            cout << " ========================================================== "                << endl;
            usleep (1000000);
            cout << "Enter anything to continue...   ";
            string _enter; getline (cin, _enter); getline (cin, _enter); cout << endl << endl;


            if (numofai == "1") {playerscore += StartGame (1, name, achievment); }
            if (numofai == "2") {playerscore += StartGame (2, name, achievment); }


            system ("clear");
            if (numofai == "1") {show_result (1, achievment, name);}
            if (numofai == "2") {show_result (2, achievment, name);}

            system ("clear");
            cout << " ========================================================== "                << endl;
            cout << "||";
            typewriter ("  After this round the score is:    ", 100000);
            cout << setw(5) << playerscore << "               " << "||"    << endl;
            cout << " ========================================================== "                << endl;

            usleep (1000000); 
            cout << "Enter anything to continue...   ";
            getline (cin, _enter); cout << endl << endl;

            break;
        }
        else {
            cout << endl << "Sorry, " << startchoice << " is an invalid option. Please enter 1 or 2" << endl;
        }
    }
    cout << " ========================================================== "                << endl;
    cout << "||" << "     Round over, thanks for playing Crazy Eights!       " << "||"    << endl;
    cout << " ========================================================== "                << endl;
    string _enter;
    cout << "Enter anything to go back to the main menu...   ";
    getline (cin, _enter); cout << endl << endl;

    return 0;
}


