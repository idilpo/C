#include <stdio.h>
#include <stdlib.h>

#define arr 50000

void range(); //function prototype

int main()
{
  int sum=0;
  for(int i=1; i<arr; ++i)
  {
    /*
    if (i%3!=0)
    {
      if (i%5!=0)
      {
        sum += i;
      }
    }
    */
    if((i%3!=0) && (i%5!=0)) {sum += i;}
  }
  printf("%d \n", sum);

  range();
}

void range()
{
  int sum_too=0;
  int max, min;
  int input1, input2;

  printf("Please enter the maximum and minimum values you'd like to range between: \n");
  scanf("%d %d", &max, &min);

  printf("Please enter the two numbers you want not to be divisible by: \n");
  scanf("%d %d", &input1, &input2);

  for(int i=1; i<max; ++i)
  {
    if(i%input1!=0)
    {
      if (i%input2!=0)
      {
        sum_too += i;
      }
    }
  }
  printf("%d \n", sum_too);
}
