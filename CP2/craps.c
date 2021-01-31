#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//enumaration constrants represent game status
enum Status {CONTINUE, WON, LOST};

int rollDice(void); //function prototype

int main(void)
{
  srand(time(NULL)); //random number generator using current time

  int myPoint;
  enum Status gameStatus; //either continue, won, or lost
  int sum = rollDice(); //first roll of the rollDice

  switch (sum) //determines the game status based on sum of dice
  {
    //win on first roll:
    case 7:
    case 11:
      gameStatus = WON;
      break;

    //lose on first roll:
    case 2:
    case 3:
    case 12:
      gameStatus = LOST;
      break;

    //remember point:
    default:
      gameStatus = CONTINUE; //player should keep rolling
      myPoint = sum; //remember the point
      printf("Point is %d\n", myPoint);
      break;
  }

  while (CONTINUE == gameStatus) //player should keep rolling
  {
    sum = rollDice();

    if (sum == myPoint) //win by  making a point
    {
      gameStatus = WON;
    }
    else
    {
      if (7 == sum) //lose by rolling 7
      {
        gameStatus = LOST;
      }
    }
  }

  if (WON == gameStatus) //did the player win?
  {
    puts("Player wins.");
  }
  else {
    puts("Player loses.");
  }
}

int rollDice(void)
{
  int die1 = 1 + (rand()%6); //pick random die1 value
  int die2 = 1 + (rand()%6); //pick random die2 value

  printf("Player rolled %d + %d = %d\n", die1, die2, die1+die2);
  return die1+die2;
}
