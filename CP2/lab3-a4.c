// Program: Pig Dice Game
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXSIZE 10000

void start(); //function prototype
void start() //function that prints the game's instructions
{
  printf("---------------------------------------------------------------------------------------------------------------------\n");
  printf("Welcome to the Pig Dice Game!\n");
  printf("Instructions:\n");
  printf("The Pig Dice Game is a two-player game where player1 starts off by rolling the dice.\n");
  printf("After the dice roll, player has two options: continue rolling or hold their turn (in which case it's player2's turn).\n");
  printf("Aside from rolling a 1, rolls are added to player's total score. In case of rolling a 1, 0 points are scored.\n");
  printf("Whoever gets more than or equal to 100 points first, wins.\n");
  printf("---------------------------------------------------------------------------------------------------------------------\n");
}

int score(); //function prototype
int score(score1, score2) //function that shows the scoreboard
{
  printf("Game Scoreboard:\n");
  printf("Player1: %d - Player2: %d\n", score1, score2);
  return 0;
}

void hold();
void hold(choice)
{
  printf("Do you wish to hold your turn? If yes, enter 'Y'. If no, enter 'N'.");
  //scanf("%c", &choice);
  choice = getchar();
}

void game(); //function prototype
void game()
{
  int player1, player2; // points that are scored for that turn
  int score1=0, score2=0;// overall points count (initialized to 0 in the beginning)
  int i; // each turn
  int turn; //indicates whose turn it is
  for (i=0; i<MAXSIZE; i++)
  {
    bool t = true;
    char choice; //choice of play, either continue or hold
    turn=player1;
    while(t)
    {
      score();
      hold();

      if((turn=player1) && (choice=='N'))
      {
        player1 = 1+(rand()%6);
        printf("Player1 rolled a %d.\n", player1);
        if (player1==1){score1 = score1 + 0;}
        else {score1 = score1 + player1;}
        score();
      }

      else if ((turn=player1) && (choice1=='Y'))
      {
        printf("Player1 holds their turn.\n");
        printf("Player2's turn.\n");
        turn=player2;
        player2 = 1+(rand()%6);
        printf("Player2 rolled a %d.\n", player1);
        if (player2==1){score2 = score2 + 0;}
        else {score2 = score2 + player2;}
        score();
      }

      t = false;
    }
  }
}

int main(void)
{
  srand(time(0)); //generates random numbers for the dice roll

  start(); //function that starts the game by giving instructions
  printf("Player1 starts.\n");
  while ((score1<=100) && (score2<=100))
  {
    game();
  }

}
