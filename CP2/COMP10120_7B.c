//Idil Bilgic (19206730)
#include <stdio.h>
#include <stdlib.h>
#define arr 50000

void range(void)
{
  int sum_too=0; //a new sum variable is initialised to 0
  int min, max; //user inputs that will determine the range are declared
  int input1, input2; //user inputs that will determine the condition are declared

  printf("Please enter the minimum and maximum values you'd like to range between: \n");
  scanf("%d %d", &min, &max);

  printf("Please enter the two numbers you want not to be divisible by: \n");
  scanf("%d %d", &input1, &input2);

  for(int i=min; i<max; ++i) //loop continues from the enterred min value to the max value
  {
    if((i%input1!=0) && (i%input2!=0)) //if the current i is not divisible by the two enterred numbers
    {
      sum_too = sum_too + i; //add the element and update the sum_too value
    }
  }
  printf("The sum from %d to %d is %d.\n", min, max, sum_too);
}

int main(void)
{
  int sum=0; //sum of nuumbers is initialised to 0 in the beginning
  for (int i=1; i<=50000; i++) //loop continues from the 1 to 50000
  {
    if ((i%3!=0) && (i%5!=0)) //if the current i is not divisible by 3 or 5
    {
      sum = sum + i; //add the element and update the sum value
    }
  }
  printf("The sum from 1 to 50000 is %d.\n", sum);
  printf("Would you like to enter a different range to calculate the sum for? Enter 1 for yes, 0 for no: ");
  int choice;
  scanf("%d", &choice); //gets user choice
  if (choice==0) //if the user chooes not to continue
  {
    printf("You have chosen 0, program will terminate.");
    exit(0); //exitting the program
  }
  else if (choice==1) //if the user chooes to continue and enter another range
  {
    range(); //calling the range function
  }
}
