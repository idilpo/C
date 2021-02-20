#include <stdio.h>

long long int factorial(int number); //function prototype

long long int factorial(int number)
{
  if (number<=1){return 1;} //base case
  else {return (number*factorial(number-1));} //recursion
}

int main(void)
{
  for (int i=0; i<=21; ++i)
  {
    printf("%u != %llu\n", i, factorial(i));
  }
}
