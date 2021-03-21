#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include <limits>
#include <algorithm>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

void PrintCard(int number, int suit){   //Prints the first 4 cards only
  switch (number){
    case 0:
      cout<<'A';
      break;
    case 1:
      cout<<2;
      break;
    case 2:
      cout<<3;
      break;
    case 3:
      cout<<4;
      break;
    case 4:
      cout<<5;
      break;
    case 5:
      cout<<6;
      break;
    case 6:
      cout<<7;
      break;
    case 7:
      cout<<8;
      break;
    case 8:
      cout<<9;
      break;
    case 9:
      cout<<10;
      break;
    case 10:
      cout<<'J';
      break;
    case 11:
      cout<<'Q';
      break;
    case 12:
      cout<<'K';
      break;
  }
  switch(suit){
    case 0:
      cout<<SPADE;
      break;
    case 1:
      cout<<HEART;
      break;
    case 2:
      cout<<CLUB;
      break;
    case 3:
      cout<<DIAMOND;
      break;
  }
  cout<<" ";
}


void PrintHand(vector<int> PlayerPile){             //print player's cards
  int count=0;
  for (int i=0;i<PlayerPile.size();i++){
    cout<<setw(8)<<setprecision(16);
    cout<<i<<") ";
    PrintCard(PlayerPile[i]%13, PlayerPile[i]/13);
    cout<<setw(8)<<setprecision(16);
    count+=1;
    if (count==2){
      cout<<endl;
      count=0;
    }
  }
  cout<<endl;
}

bool ValidChecker(int &card, int firstcard){
  int firstcardnum=firstcard%13;
  int firstcardsuit=firstcard/13;
  int number=card%13;
  int suit=card/13;
  if (number==7){
    int wildsuit;
    cout<<"You have played a WILD CARD"<<endl;
    cout<<"Please choose the suit that you want"<<endl;
    cout<<"0) SPADE          1) HEARTS"<<endl;
    cout<<"2) CLUB           3) DIAMOND"<<endl;
    cin>>wildsuit;
    card=wildsuit*13+firstcardnum;
    return true;
  }
  if (number==firstcardnum){
    return true;
  }
  else if (suit==firstcardsuit){
    return true;
  }
  else{
    return false;
  }
}




bool AI(int &firstcard, vector<int>& aiPile){
  int firstcardnum=firstcard%13, firstcardsuit=firstcard/13;
  srand(time(NULL));
  int random=rand()%2;
  if (random==1){
    reverse(aiPile.begin(), aiPile.end());
  }
  for (int i=0;i<aiPile.size();i++){
    int number, suit;
    number=aiPile[i]%13;
    suit=aiPile[i]/13;
    if (number==firstcardnum || number==7){
      if (number!=7){
        PrintCard(number, suit);
        firstcard=aiPile[i];
        aiPile.erase(aiPile.begin()+i);
        cout<<endl;
        cout<<"AI has "<<aiPile.size()<<" cards left"<<endl;
        return true;
      }
      else{
        PrintCard(number, suit);
        cout<<endl;
        cout<<"AI has played a WILD CARD. IT has chosen the suit: ";
        int wildsuit=rand()%4;
        while (wildsuit==firstcardsuit){
          wildsuit=rand()%4;
        }
        switch (wildsuit){
          case 0:
            cout<<"SPADE"<<endl;
            break;
          case 1:
            cout<<"HEARTS"<<endl;
            break;
          case 2:
            cout<<"CLUB"<<endl;
            break;
          case 3:
            cout<<"DIAMOND"<<endl;
            break;
        }
        firstcard=wildsuit*13+firstcardnum;
        aiPile.erase(aiPile.begin()+i);
        cout<<"AI has "<<aiPile.size()<<" cards left"<<endl;
        return true;
      }
    }
    else if (suit==firstcardsuit){
      PrintCard(number,suit);
      firstcard=aiPile[i];
      aiPile.erase(aiPile.begin()+i);
      cout<<endl;
      cout<<"AI has "<<aiPile.size()<<" cards left"<<endl;
      return true;
    }
  }
  return false;
}




void StartGame(){       //Starts the game
  cout<<endl;
  cout<<endl;
  string name;
  cout<<"Please enter your name: ";
  cin>>name;
  cout<<"Hi "<<name<<endl;
  vector<int> PlayerPile, aiPile;
  int DrawPile[52], card;

  for (int i=0;i<52;i++){       //Creating draw pile
    DrawPile[i]=i;
  }

  srand (time(NULL));
  for (int i=0; i<7;i++){         //Create card hand for player
    card=rand()%52;
    while (DrawPile[card]==-1){
      card=rand()%52;
    }
    PlayerPile.push_back(card);
    DrawPile[card]=-1;
  }

  for (int j=0;j<7;j++){      //Creatr card hand for AI
    card=rand()%52;
    while (DrawPile[card]==-1){         //Make sure cards do not overlap with cards that are drawn out from drawpile
      card=rand()%52;
    }
    aiPile.push_back(card);
    DrawPile[card]=-1;
  }

  bool win=false;
  int firstcard, drawcount=15;

  firstcard=rand()%52;          //Make opening card
  while (DrawPile[firstcard]==-1){
    firstcard=rand()%52;
  }
  DrawPile[firstcard]=-1;
  int number, suit;
  number = firstcard % 13;
  suit=firstcard/13;
  cout<<"Opening card is ";                                       //Print opening card
  PrintCard(number, suit);
  cout<<endl;
  cout<<endl;
  card=firstcard;


  int cardindex;
  while (!win){                                                   //Start of actual game
    card=firstcard;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Your cards are"<<endl;
    PrintHand(PlayerPile);
    cout<<endl<<"-----------------------------------------"<<endl;
    cout<<name<<"'s turn. Please play a valid card or"<<endl;
    cout<<"press -1 to draw a card from the Draw pile"<<endl;
    cin>>cardindex;
    if (cardindex!=-1){
      card=PlayerPile[cardindex];
      bool notdraw=true;
      while (!ValidChecker(card, firstcard)){
        if (cardindex!=-1){
          PrintCard(card%13, card/13);
          cout<<"is an invalid card. Please choose a valid card to play"<<endl;
          cin>>cardindex;
          if (cardindex!=-1){
            card=PlayerPile[cardindex];
          }

        }
        else if (cardindex==-1){                             //Draw card for player
          card=rand()%52;
          while (DrawPile[card]==-1){
            card=rand()%52;
          }
          PlayerPile.push_back(card);
          DrawPile[card]=-1;
          cout<<"You drew ";
          PrintCard(card%13,card/13);
          cout<<endl;
          drawcount+=1;
          cout<<"Deck size: "<<52-drawcount<<endl;
          notdraw=false;
          break;
        }
      }
      if (notdraw){
        PlayerPile.erase(PlayerPile.begin()+cardindex);
        firstcard=card;
      }

    }

    else if (cardindex==-1){                    //Player draws new card
      card=rand()%52;
      while (DrawPile[card]==-1){
        card=rand()%52;
      }
      PlayerPile.push_back(card);
      DrawPile[card]=-1;
      cout<<"You drew ";
      PrintCard(card%13,card/13);
      cout<<endl;
      drawcount+=1;
      cout<<"Deck size: "<<52-drawcount<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"Top card is ";
    PrintCard(firstcard%13,firstcard/13);
    cout<<endl<<"-----------------------------------------"<<endl;
    cout<<endl;

    if (PlayerPile.size()==0){
      win=true;
      cout<<name<<" wins!"<<endl;
      break;
    }
    else if (drawcount==52){
      win=true;
      cout<<"DRAW"<<endl;
    }
    cout<<endl;
    cout<<"AI plays: ";
    if (!AI(firstcard, aiPile)){        //AI draws card
      card=rand()%52;
      while (DrawPile[card]==-1){
        card=rand()%52;
      }
      aiPile.push_back(card);
      DrawPile[card]=-1;
      cout<<"AI drew a card"<<endl;
      drawcount+=1;
      cout<<"AI has "<<aiPile.size()<<" cards left"<<endl;
      cout<<"Deck size: "<<52-drawcount<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"Top card is ";
    PrintCard(firstcard%13,firstcard/13);
    cout<<endl;

    if (aiPile.size()==0){
      win=true;
      cout<<"AI wins!"<<endl;
      break;
    }
    else if (drawcount==52){
      win=true;
      cout<<"DRAW"<<endl;
    }
  }                                                                 //End of while game loop
}




void PrintRules(){        //Print Rules of Crazy Eights
  cout<<endl;
  cout<<"*********************"<<endl;
  cout<<"Rules of Crazy Eights"<<endl;
  cout<<"*********************"<<endl;
  cout<<endl;
  cout<<"The rules are very simple, it is very similar to Uno"<<endl;
  cout<<"Each player will be given 7 random cards from a deck of 52 cards. The leftover cards will be made into a Draw Pile."<<endl;
  cout<<"Each player takes turns placing down a card from their hand or drawing a card from the draw pile."<<endl;
  cout<<"During a player's they can play a card the matches the current card in the Play pile by suit (i.e Diamonds, Hearts, Clover, Spade)"<<endl;
  cout<<"or a card the matches its rank (number)."<<endl;
  cout<<"For example if the current card is the 3 of Hearts, you can play either a card with rank 3 or with suit Hearts."<<endl;
  cout<<"If you do not have any card that you can play, you may take a card from the draw pile."<<endl;
  cout<<"Cards with rank 8 are special Wild Cards, they can be played at anytime. After playing an 8, the player can choose which suit it takes up"<<endl;
  cout<<"To win this game, you must finish all the cards in your hand before your opponent. If the draw pile becomes empty before any player wins, the game will draw."<<endl;
  cout<<"Are you ready? Lets begin!"<<endl;
}

int main(){
  int startchoice;
  cout<<"Hi there! Welcome to Crazy Eights!"<<endl;
  cout<<"Press 1 to play the game."<<endl;
  cout<<"Press 2 to read the rules."<<endl;

  startchoice=0;
  while (startchoice!=1 || startchoice!=2){
    cin>>startchoice;
    if (startchoice==1){
      StartGame();
      break;
    }
    else if (startchoice==2){
      PrintRules();
      StartGame();
      break;
    }
    else {
      cout<<"Sorry, invalid option. Please enter 1 or 2"<<endl;
    }
  }

}
