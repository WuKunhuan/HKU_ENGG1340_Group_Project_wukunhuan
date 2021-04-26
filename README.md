#    ENGG_1340-Group_Project

##   ⭐️  Group members (Group 50)
    Senthil Kumar Sapnesh   (3035790850)
    Wu Kunhuan              (3035771634)



##   ⭐️  Description of the project
    This project is a 2 in 1 game.
    There are a total of 5 rounds. In each round, the player can choose to play either Crazy Eights or 24 Calculation.
    When player enters the main menu, they will be asked to input their name. The game will check if a [Game saved] file exists and if so will prompt player if they want to continue from where they left off or want to start a new game.
    After Round 2 and Round 4, players will play a Slot Machine which gives them a chance to double their bet score.
    Players will input the number corresponding to the game in the Main Menu to play it (navigation to different games). After entering games, players can again input different numbers to start the game, read the rules, and choose the game mode.
    After 5 rounds, a file with title starting with [Game result] then with the player's name will be created with their performance of the game that they played. Before each round, the player can also choose to save his or her game progress, and enter it again in the future.
  
## ⭐️ Compilation and execution instructions
   
    First, download all the files into a single folder and open a terminal for that folder. 
    Then, enter the following 2 commands in the terminal one by one: 

    make MainMenu
    ./MainMenu

    After these steps, a terminal interface of the game will be available. Follow the game instructions in the game for the normal operation. Always save the game progress to avoid loss of progress from accidental crashes. Please refer to the Sample Gamerun file for a better sense of how the game interface looks like. 
    Sometimes, if nothing is coming up in the game, just return one more blank line, and then it should be OK (the getline function sometimes let users to enter again in case the previous enter is nothing). Have fun with both subgames and try different game modes  :)
    
    After finishing the game, if needed you can type in the following command to clear the .o files
    make clean
    



##   ⭐️  List of subgames
     1)  Crazy Eights
     2)  Make 24



##   ⭐️  Descriptions of each subgame

###  Crazy Eights
     A playing cards version of Uno. In this card game, the player will play against Artificial Intelligence (AI).
     

     ⭕️   Game rules
     -    This game uses all cards in a deck of plaing cards except for the Joker cards.
     -    Each player gets 7 randomly selected cards from the Deck in the beginning of the game. After dealing 7 cards to each player, another card (Opening Card) will be uncovered from the rest of the pile, and the player will start discarding his/her cards first.
     -    Each time, the player can only discard one card that has either the same rank or the same suit with the Top Card, by entering the integer Card ID provided in the interface. When the player has a card "8", he/she can also play that without following the requirement of the same rank/suit. In that case, he/she can choose a new suit (similar to choosing which colour after playing a wildcard in Uno) that will be assigned to the current top card, this means the next player can only play the newly assigned suit's card or the previous number (the number before the 8 was played).
     -    In case no card is available to be played by the player (meets the requirement of the same rank/suit) in a single turn, the player has to draw a card by entering -1 from the rest of the pile.
     -    Get rid of all your cards before AI to win. For each round, in case the player wins, he/she will get certain points according to the total remaining from the Deck. The less number of cards drawed, the more points the player is getting. In contrast, if any AI finished the cards before the player, player will not get any point.
     -    If both AI and player cannot finish their cards before the Deck becomes empty, the player with the least number of cards will win. If players have the same number of cards, it is a draw.
     -    Players can choose to play against either 1 AI or 2 AIs, and the calculation of points will be varied. In detail, for 1 AI the maximum score available is 50 for the round, but for 2 AIs, the maximum score will be 100 for the round. When the round is finished a scoreboard will be displayed at the end. 



     ⭕️   Features
     -    This game distributes 7 random cards to each of the player in the beginning of the round, also chooses random cards each time from the Deck when a card is needed to be drawn or the player / AI. This meets the code requirement 1: Generation of random game sets or events. 
     -    This game uses structs to store the player data in [Game saved] and [Game result] files. After that, when reloading games, the corresponding data will be stored in the struct in the main menu program. This meets the code requirement 2: Data structures for storing game status. 
     -    This game uses Vectors to store the Player's and AIs' piles, and processes the card adding or playing process when it comes to the player/AI's turn. This meets the code requirement 3: Dynamic memory management. 
     -    This game supports loading / saving game progress, also outputting the game result after all 5 rounds, together with the [Game saved] and [Game result] files. Additionally, this game supports storing multiple users' game progress and result. This meets the code requirement 4: File input/output. 
     -    This game is one of the subgames in the 2-in-1 main menu. Under the main menu's program, there are both program files (.cpp) for the subgames. When compiling, it will use all the cpp files to generate the MainMenu program.  This meets the code requirement 5: Program codes in multiple files. 
     -    The cards in player's hand and other statements print in a typewriter format.

     -    This game is simple and fun. You can choose to play with either 1 AIs or 2 AIs. A well-looked user interface is available for players to interact with AIs and play cards like normal online games.
     -    The terminal will clear itself after each card is played to make it easier for the player to see what is happening.
     






###  Make 24
    Form an expression with all the given value of each playing card using +, -, *, /, (). (in some modes also include ^, / and %) to form a result of 24. To have a better understanding of this game, please have a look on this Youtube video:
     https://www.youtube.com/watch?v=LyyHt7NfBxI

     ⭕️   Game rules
    -    Each time the player gets 4 ~ 6 randomly selected cards, based on his or her game option. After that, the player has to type in an expression which includes all of the given numbers exactly once, and one or more kinds of operators to make up the result of 24. All the questions given are solvable.
     -    For each correct expression formed by the player, a certain point will be given based on the time used for the question, minimum 5 points and maximum 20 points. The shorter the time used, the higher points for that question gained, so the Goal is to solve the question correctly and fast at the same time.
     -    A complete round consists of 5 questions. Points from each question will be accumulated to have the final point for the round, this means the maximum score available for a single round is 20 * 5 = 100. When the round is finished a scoreboard will be displayed at the end, consisting the overall score and the overall grade for the round. 

     -    Bonus points will be available for specific achievements in this game, for example:
     ①  The player has finished questions correctly within a specific time
     ②  The player has finished questions correctly continuously for at least 3 times
     ③  The player has finished questions correctly within a specific time continuously for at least 3 times

     ⭕️   Features
    -    This game selects random question sets and assign random suits to the given cards provided in the calculation. This meets the code requirement 1: Generation of random game sets or events. 
     -    This game uses structs to store the player data in [Game saved] and [Game result] files. After that, when reloading games, the corresponding data will be stored in the struct in the main menu program. This meets the code requirement 2: Data structures for storing game status. 
     -    This game uses Vectors to store the numbers and operators provided by the player in the game. After that, in order to figure out whether the calculation result is 24, this game makes good use of the push_back (), pull_back (), back (), etc. vector functions to analyse the expression string entered by the player correctly. This meets the code requirement 3: Dynamic memory management. 
     -    This game supports loading / saving game progress, also outputting the game result after all 5 rounds, together with the [Game saved] and [Game result] files. Additionally, this game supports storing multiple users' game progress and result. Specially for the 24 calculation subgame, there are question banks provided in advance to store those questions that has solutions and load them for random questions in the game. This meets the code requirement 4: File input/output. 
     -    This game is one of the subgames in the 2-in-1 main menu. Under the main menu's program, there are both program files (.cpp) for the subgames. When compiling, it will use all the cpp files to generate the MainMenu program.  This meets the code requirement 5: Program codes in multiple files. 

     -    This game is simple and fun, popular among Chinese kids. You can choose different game modes, calculating the traditional 4 numbers, also 5 numbers and 6 numbers' question sets. The more you practice with it, the higher the score will be! 
     -    The terminal will clear itself after each question to make it easier for the player to see what is happening.



     For more detail, please refer to the game help page in the program. 

## Slot machine
    - After rounds 2 and 4, a slot machine minigame will appear. Players can bet a portion of their score in this game to try their luck to double their bet. The game will roll 3 random numbers and if all the 3 numbers match, the player's bet will be doubled. Otherwise the bet will be deducted from the score. 
    
    
    
## Non-Standard C/C++ Libraries:
    #include <time.h> - Used for 24 Calculation time based scoring system
    #include <limits>
    #include <algorithm>
    #include <unistd.h> - Used in print statements like a typewriter
    #include <chrono> - Used for 24 Calculation time based scoring system
## Academy server used for testing
    Latest test was done on Academy11 server, but tests were also done on Academy21 server.
   
## Special note
    Git commit comments were made in the extended description part of each commit for files
