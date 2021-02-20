// Program: Pig Dice Game
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

int main(void)
{
  int player1=0, player2=0; // points that are scored for that turn
  int score1=0, score2=0;// overall points count (initialized to 0 in the beginning)
  int i; // each turn
  bool turn1=true; //indicates whose turn it is
  bool turn2=false; //indicates whose turn it is

  bool t = true;
  char choice; //choice of play, either continue or hold
  while(t)
  {
    //hold();

    printf("Do you wish to hold your turn? If yes, enter 'Y'. If no, enter 'N'.");
    choice = getchar();
    //scanf("%c", &choice);

    if((turn1) && (choice=='N')) //when it's player1's turn and they want to continue
    {
      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1!=1){score1 = score1 + player1;}
      score();
    }

    else if ((turn1) && (choice=='Y')) //when it's player1's turn and they want to hold
    {
      printf("Player1 holds their turn.\n");
      printf("Player2's turn.\n");
      turn2=true;
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      if (player2==1){score2 = score2 + 0;}
      else {score2 = score2 + player2;}
      score();
    }

    if (score1>=100)
    {
      printf("Player1 wins!\n");
      t = false;
    }

    if((turn2) && (choice=='N')) //when it's player2's turn and they want to continue
    {
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      if (player1==1){score2 = score2 + 0;}
      else {score2 = score2 + player2;}
      score();
    }

    else if ((turn2) && (choice=='Y')) //when it's player2's turn and they want to hold
    {
      printf("Player2 holds their turn.\n");
      printf("Player1's turn.\n");
      turn1=true;
      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1==1){score1 = score1 + 0;}
      else {score1 = score1 + player1;}
      score();
    }

    if (score2>=100)
    {
      printf("Player2 wins!\n");
      t = false;
    }
  }
}
