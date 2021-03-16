#    ENGG_1340-Group_Project

##   ⭐️  Group members
    Senthil Kumar Sapnesh   (3035790850)
    Wu Kunhuan              (3035771634)



##   ⭐️  Description of the project
    This is a 2 in 1 game.
    Text-game type: Text-based playing cards' puzzle games.
    Players will input the number corresponding to the game to play it in the Main Menu (navigation to different games). After entering games, players can again input different numbers to start, read rules, load previous game progress and so on.
    In case players choose to start the game, related game interfaces will be displayed. After finishing each set of an individual game or both games, a report of the player's overall score will be produced while a ranking table is available to see from the user.



##   ⭐️  List of sub-games
     1)  Crazy Eights
     2)  Make 24



##   ⭐️  Description of each subgame

###  Crazy Eights
     A simple version of Uno with playing cards. In this card game, the player will play against Artificial Intelligence (AI).
     To have a better understanding of this game, please have a look of the following Youtube Video:
     https://www.youtube.com/watch?v=iDQjn3k76Mw

     ⭕️   Game rules
     -    This game uses 1 single suit or more complete suits of the playing cards.
     -    Each player gets 5 randomly selected cards from the suit in the beginning of the game. After dealing 5 cards to each player, another card (Initial Card) will be uncovered from the rest of the pile, and a player will be selected to start discarding his/her cards.
     -    Each time, a player can only discard one card that has either the same rank or the same suit with the Initial Card (if the player is playing the first card of the whole set) or the card played by the last player. When the player has a card "8", he/she can also play that without following the requirement of the same rank/suit. In that case, he/her can choose a suit (similar to choosing which colour after playing a wildcard in Uno) that will be assigned to the next player, this means the next player can only play another 8 or a newly assigned suit's card.
     -    In case no card is available to be played by the player (meets the requirement of the same rank/suit) in a single turn, the player has to pick up cards from the rest of the pile one by one, before he/she has a card that is able to be played. When a single suit is all taken, a new random set will be used to continue.
     -    The Goal is to get rid of all your cards before AI, and that is called winning a single round. For each round, in case the player has won that round, he/she will get certain points according to the total remaining cards of the AI. The more cards AI is remaining, the more points the player is getting. In contrast, if any AI finished the cards before the player, points will be deducted from the player according to the total remaining cards of the player.
     -    Players can choose to play different rounds, e.x. 2, 3 or 5 rounds in a complete game set, points from each game round will be accumulated to have the final point. Players can also choose to play against either 1 or 3 AI, and the calculation of points will be varied.
     -    Bonus points will be available for specific achievements in this game, for example:
     ①  The player finishes all cards before certain turns in a round
     ②  The player win continuously for at least 3 times

     ⭕️   Features
     -    This game has functions that can be used to generate random numbers, e.x. dealing cards       (Code requirement 1)
     -    This game uses arrays, vectors and so on to store datas                                       (Code requirement 2)
     -    This game uses dynamic memory management to store datas                                       (Code requirement 3)
     -    This game supports loading/saving the game status with certain functions                      (Code requirement 4)
     -    This game has different cpp files to store the program for different functions                (Code requirement 5)
     -    This game is simple and fun. A well-looked user interface is available for players to interact with AIs and play cards like normal online games.
     -    Additional features beyond the original game rules, e.x. bonus points are implemented to make this game more creative.

     For more detail, please refer to the game help page in the program.






###  Make 24
     Form an expression with all the given value of each playing card using +, -, *, /, (). (in some modes also include ^, / and %) to form a result of 24.
     To have a better understanding of this game, please have a look on this Youtube video:
     https://www.youtube.com/watch?v=LyyHt7NfBxI

     ⭕️   Game rules:
     -    This game uses 1 single suit or more complete suits of the playing cards.
     -    Each player gets 4 ~ 6 randomly selected cards from the suit in the beginning of the game. After that, they have to type in an expression which includes all of the given numbers exactly once, and one or more kinds of operators to make up the result of 24. There will be a possibility that a set of cards have no such solution of the expression. Players have to identify those cases correctly and choose to skip them (however, there will be a limit of chances for the player to skip a single question, so think it carefully before skipping). In case the player has skipped a non-solution question, some points will be given and the remaining chances to skip the question will noe be reduced.
     -    For each correct expression formed by the player, a certain point will be given based on the time used for the question. The shorter the time used, the higher points for that question gained, so the Goal is to solve the question correctly and fast.
     -    A total set of the game includes certain rounds, e.x. 5, 10 or 20, and the player can choose to play different rounds. Points from each game round will be accumulated to have the final point. Players can also choose to play with either 4, 5 or 6 random selected cards or a mix of them in the game, and the calculation of points will be varied.
     -    Bonus points will be available for specific achievements in this game, for example:
     ①  The player has finished questions correctly within a specific time
     ②  The player has finished questions correctly continuously for at least 3 times
     ③  The player has finished questions correctly within a specific time continuously for at least 3 times

     ⭕️   Features:
     -    This game has functions that can be used to generate random numbers, e.x. dealing cards       (Code requirement 1)
     -    This game uses arrays, vectors and so on to store datas                                       (Code requirement 2)
     -    This game uses dynamic memory management to store datas                                       (Code requirement 3)
     -    This game supports loading/saving the game status with certain functions                      (Code requirement 4)
     -    This game has different cpp files to store the program for different functions                (Code requirement 5)
     -    This game is simple and fun. A well-looked user interface is available for players to see their poker cards and write the expression.
     -    Additional features beyond the original game rules, e.x. bonus points, more operators, more cards, timer, are implemented to make this game more creative.

     For more detail, please refer to the game help page in the program. 

