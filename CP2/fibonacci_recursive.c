#include <stdio.h>

long long int fibonacci(int n); //function prototype

long long int fibonnaci(int n)
{
  if (0==n || 1==n) {return n;} //base case
  else {return fibonnaci(n-1) + fibonnaci(n-2);} //recursion
}

int main(void)
{
  int number;
  printf("%s\n", "Enter an integer: ");
  scanf("%u\n", &number);

  long long int result = fibonacci(number);
  printf("Fibonnaci(%u) = %llu\n", number, result);
}
