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

void hold();
void hold(choice)
{
  printf("Do you wish to hold your turn? If yes, enter 'Y'. If no, enter 'N'.");
  //scanf("%c", &choice);
  choice = getchar();
}

int score(); //function prototype
int score(score1, score2) //function that shows the scoreboard
{
  printf("--Game Scoreboard--\n");
  printf("Player1:%d - Player2:%d\n", score1, score2);
  return 0;
}

int main(void)
{
  int player1, player2; // points that are scored for that turn
  int score1=0, score2=0;// overall points count (initialized to 0 in the beginning)
  int i; // each turn
  char choice; //choice of play, either continue or hold
  int turn; //indicates whose turn it is

  bool t = true;
  while(t)
  {
    hold(choice);

    while ((choice!='Y') || (choice!='N')) //in case of the entry of an invalid character
    {
      printf("Please enter a valid character.\n");
      choice = getchar();
      break;
    }

    turn=player1;
    do
    {
      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1==1){score1 = score1 + 0;}
      else {score1 = score1 + player1;}
      score(score1, score2);
    }
    while((turn=player1) && (choice=='N'));

    do
    {
      printf("Player1 holds their turn.\n");
      printf("Player2's turn.\n");
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      if (player2==1){score2 = score2 + 0;}
      else {score2 = score2 + player2;}
      score(score1, score2);
    } while((turn=player1) && (choice=='Y'));

    if (score1>=100)
    {
      printf("Player1 wins!\n");
      t = false;
    }

    turn=player2;
    do
    {
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      if (player1==1){score2 = score2 + 0;}
      else {score2 = score2 + player2;}
      score(score1, score2);
    }
    while((turn=player2) && (choice=='N'));

    do
    {
      printf("Player2 holds their turn.\n");
      printf("Player1's turn.\n");
      turn=player1;
      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1==1){score1 = score1 + 0;}
      else {score1 = score1 + player1;}
      score(score1, score2);
    }
    while((turn=player2) && (choice=='Y'));

    if (score2>=100)
    {
      printf("Player2 wins!\n");
      t = false;
    }
  }
}
