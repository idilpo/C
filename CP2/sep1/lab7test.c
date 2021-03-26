#include <stdio.h>
#include <stdlib.h>

#define array1 50000

void test();

int main()
{
  int i, userSum = 0;

  for(i = 1; i < array1; ++i)
  {
    if( i % 3 != 0 && i % 5 != 0)
    {
      userSum += i;
    }
  }

  printf("%d\n", userSum);

  test();
}

void test()
{
  int userMax, userMin, userSum;
  int divOne, divTwo;
  int i = 0;

  printf("Please enter your Maximum and Minimum: \n");
  scanf("%d %d",&userMax, &userMin);

  printf("Please enter the Two numbers you want to not be divisible by: \n");
  scanf("%d %d", &divOne, &divTwo);

  for(i = 1; i < userMax; ++i)
  {
    if( i % divOne != 0 && i % divTwo != 0)
    {
      userSum += i;
    }
  }
  printf("%d\n", userSum);
}
