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
  printf("Game Score-board:\n");
  printf("Player1: %d - Player2: %d\n", score1, score2);
  return 0;
}

int main(void)
{
  int i; // each turn
  int player1, player2; // points that are scored for that turn
  int score1=0, score2=0;// overall points count (initialized to 0 in the beginning)
  srand(time(0)); //generates random numbers for the dice roll

  start(); //function that starts the game by giving instructions
  printf("Player1 starts.\n");
  while ((score1<=100) && (score2<=100))
  {
    bool t = true;
    char choice1, choice2; //choice of play, either continue or hold

    while(t)
    {
      printf("Do you wish to hold your turn? If yes, enter 'Y'. If no, enter 'N'.");
      //choice1 = getchar();
      scanf("%c", &choice1);

      if(choice1=='Y') //Player1 holds their turn
      {
        printf("Player1 holds their turn.\n");
        printf("Player2's turn.\n");
        printf("Do you wish to hold your turn? If yes, enter 'Y'. If no, enter 'N'.");
        //choice2 = getchar();
        scanf("%c", &choice2);

        if(choice2=='Y') //Player2 holds their turn
        {
          printf("Player2 holds their turn.\n");
        }

        if(choice2=='N') //Player2 plays
        {
          player2 = 1+(rand()%6);
          printf("Player2 rolled a %d.\n", player2);
          score2 = score2 + player2;
        }

        while ((choice2!='Y') && (choice2!='N')) //in case of the entry of an invalid character
        {
          printf("Please enter a valid character.\n");
          scanf("%c", &choice2);
          break;
        }

        break;
      }

      if(choice1=='N') //when Player1 continues their turn
      {
        player1 = 1+(rand()%6);
        printf("Player1 rolled a %d.\n", player1);
        score1 = score1 + player1;
      }

      while ((choice1!='Y') && (choice1!='N')) //in case of the entry of an invalid character
      {
        printf("Please enter a valid character.\n");
        scanf("%c", &choice1);
        break;
      }

      t = false;

      break;
    }
  }

  if (score1>=100){printf("Player1 wins!\n");}
  if (score2>=100){printf("Player2 wins!\n");}
}
