// Program: Pig Dice Game
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 10000

int i; // each turn
int player1, player2; // points that are scored for that turn
int score1=0, score2=0; // overall points count
char choice[];

int main(void)
{
  srand(time(0));
  for (i=0; i<MAXSIZE; i++)
  {
    player1 = 1+(rand()%6);
    if (player1==1){score1 = score1 + 0;}
    else
    {
      for (int j=0; j<MAXSIZE; j++)
      {
        score1 = score1 + player1;
        printf("Do you wish to hold your turn?");
        scanf("%s", choice);
        break;
      }
    }

    player2 = 1+(rand()%6);
    if (player2==1){score2 = score2 + 0;}
    else
    {
      for (int k=0; k<MAXSIZE; k++)
      {
        score2 = score2 + player2;
        printf("Do you wish to hold your turn?");
        scanf("%s", choice);
        break;
      }
    }
  }

  if (score1>=100){printf("Player1 wins!\n");}
  if (score2>=100){printf("Player2 wins!\n");}
}
