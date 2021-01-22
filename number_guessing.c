#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num1; //first input from the user
int n; //will get assigned the random number
int i=0; //for the loop
int lower=1, upper=100; //limitations for the random number

int main(void)
{
  puts("I am thinking of a number between 1 and 100.");
  puts("Can you guess my number?");
  puts("Please type your guess: ");
  scanf("%d", &num1);

  srand(time(0));
  for(i=0; i<1; i++)
  {
    n=(rand() % (upper - lower + 1)) + lower;
    printf("%d\n", n);
  }

  if(num1>n) {printf("Too high, please try again.\n");}
  if(num1<n) {printf("Too low, please try again.\n");}
  if(num1==n) {printf("You got it! My number was %d !\n", i);}

  return 0;
}
