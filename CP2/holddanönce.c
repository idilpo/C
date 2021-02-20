#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int score(); //function prototype
int score(int score1, int score2) //function that shows the scoreboard
{
  printf("--Game Scoreboard--\n");
  printf("Player1:%d - Player2:%d\n", score1, score2);
  return 0;
}

int main(void)
{
  srand(time(0)); //for generating random numbers
  int player1, player2; //points that are scored for that turn
  int score1=0, score2=0; //overall points count (initialized to 0 in the beginning)
  bool t = true; //for the while loop
  char choice; //choice of play, either continue or hold

  //game instructions are printed in the beginning:
  printf("---------------------------------------------------------------------------------------------------------------------\n");
  printf("Welcome to the Pig Dice Game!\n");
  printf("Instructions:\n");
  printf("The Pig Dice Game is a two-player game where player1 starts off by rolling the dice.\n");
  printf("After the dice roll, player has two options: continue rolling or hold their turn (in which case it's player2's turn).\n");
  printf("Aside from rolling a 1, rolls are added to player's total score. In case of rolling a 1, 0 points are scored.\n");
  printf("Whoever gets more than or equal to 100 points first, wins.\n");
  printf("---------------------------------------------------------------------------------------------------------------------\n");

  while(t) //main while loop that keeps running until someone reaches 100
  {
    //do-while loop for player1:
    //the loop keeps on running if player1 one wants to continue up to 100

    do
    {
      //if input is invalid, the loop keeps going on until a valid input is entered
      printf("Player 1:Please enter N if you want to continue or press Y if you want to hold!:\n");
      choice = getchar();

      if(choice=='N') //when player1 wants to continue
      {
        player1 = 1+(rand()%6);
        printf("Player1 rolled a %d.\n", player1);
        if (player1==1 )
        {
        score1 = score1 + 0; //score hasnt changed if 1 is rolled
        break;
        }
        else if (player1 >0)
        {
          score1 = score1 + player1; //score is updated according to the number on the dice
          score(score1, score2); //scoreboard is shown at the end of each turn
        }
      }

      else if (choice=='Y') //when player1 wants to hold
      {
        printf("Player1 holds their turn.\n");
        printf("Player2's turn.\n");
        player2 = 1+(rand()%6);
        printf("Player2 rolled a %d.\n", player2);
        break; //breaks out of the loop and goes to player2
      }
      }while(score1 < 100);

      if (score1>=100)
      {
        printf("Player1 wins!\n");
        t = false; //end of game: t is set to false to exit the while loop
      }



      //while loop for player2:
      //the loop keeps on running if player2 one wants to continue up to 100
      while(score2<100 && score1<100)
      {
      //if input is invalid, the loop keeps going on until a valid input is entered
      printf("Player1: Please enter N if you want to continue or press Y if you want to hold!:\n");
      choice = getchar();

      if(choice=='N') //when player2 wants to continue
      {
        player2 = 1+(rand()%6);
        printf("Player2 rolled a %d.\n", player2);
        if (player2==1)
        {
          score2 = score2 + 0; //score hasnt changed if 1 is rolled
          break;
        }
        else
        {
          score2 = score2 + player2; //score is updated according to the number on the dice
          score(score1, score2); //scoreboard is shown at the end of each turn
        }
      }


      else if(choice == 'Y') //when player2 wants to hold
      {
        printf("Player2 holds their turn.\n");
        printf("Player1's turn.\n");
        player1 = 1+(rand()%6);
        printf("Player1 rolled a %d.\n", player1);
        if (player1==1)
        {
          score1 = score1 + 0;
          break; //break because it's going to be the other player's turn, goes to the next while loop by breaking from this one
        }
        else
        {
          score1 = score1 + player1;
          break; //same reason as above
        }
        score(score1, score2); //scoreboard is shown at the end of each turn
        break; //same reason as above
    }
  }
  }

    if (score2>=100)
    {
      printf("Player2 wins!\n");
      t = false; //end of game: t is set to false to exit the while loop
    }
  }
