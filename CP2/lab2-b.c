//Program: Mega Millions
//Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func()
{
  printf("%s\n", "-------------");
  for (int j=1; j<=6; j++)
  {
    //random number between 1 and 70 (white balls):
    printf("%d\n", 1+(rand()%70));
  }
  //random number between 1 and 25 (the Mega ball):
  printf("%d\n", 1+(rand()%25));
}

void prizes()
{
  int ans;
  printf("%s\n", "Would you like to see a summary of prices? Please enter 1 for yes or 0 for no: ");
  scanf("%d", &ans);

  if (ans==1)
  {
    printf("%s", "Match:                                  ");
    printf("%s", "Prize:                       ");
    printf("%s\n", "Odds:");

    printf("%s", "5 white balls and 1 Mega ball           ");
    printf("%s", "Jackpot                      ");
    printf("%s\n", "1 in 302,575,350");

    printf("%s", "5 white balls                           ");
    printf("%s", "$1,000,000                   ");
    printf("%s\n", "1 in 12,607,306");

    printf("%s", "4 white balls and 1 Mega ball           ");
    printf("%s", "$10,000                      ");
    printf("%s\n", "1 in 931,001");

    printf("%s", "4 white balls                           ");
    printf("%s", "$500                         ");
    printf("%s\n", "1 in 38,792");

    printf("%s", "3 white balls and 1 Mega ball           ");
    printf("%s", "$200                         ");
    printf("%s\n", "1 in 14,547");

    printf("%s", "3 white balls                           ");
    printf("%s", "$10                          ");
    printf("%s\n", "1 in 606");

    printf("%s", "2 white balls and 1 Mega ball           ");
    printf("%s", "$10                          ");
    printf("%s\n", "1 in 693");

    printf("%s", "1 white ball and 1 Mega ball            ");
    printf("%s", "$4                           ");
    printf("%s\n", "1 in 693");

    printf("%s", "1 Mega ball                             ");
    printf("%s", "$2                           ");
    printf("%s\n", "1 in 37");

    printf("%s\n", "Overall chances of winning any prize:                                1 in 24");
    printf("%s\n", "Thank you for playing!");
  }
  else {printf("%s\n", "Thank you for playing!");}
}

int main(void)
{
  int i,play=0;
  printf("How many number of plays would you like get? \n");
  scanf("%d", &play);

  srand(time(NULL)); //for random values
  int seed=5; //number used to seed the random number generator
  srand(seed); //seed the random number generator

  for (i=0; i<play; i++){func();}
  printf("The total cost of your ticket is %d.\n", i*2); //$2 per play
  prizes();
}
