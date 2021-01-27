//Program: Student Number Adder
//Author: Idil Bilgic (19206730)

#include <stdio.h>
#define MAX_SIZE 7 //limits the size of the array

int number[MAX_SIZE];
int i;
int sum=0; //the sum value is initialised

int main(void)
{
  for (i=0; i<8; i++)
  {
    //makes sure the user needs to type exactly eight digits for the program to work:
    printf("Please enter your student number digit by digit: \n");
    scanf("%d", &number[i]);
  }

  for (i=0; i<8; i++)
  {
    sum = sum + number[i];
    printf("%d\n", number[i]);
  }
  printf("The total sum of all digits in your student number is %d.\n", sum);
}
