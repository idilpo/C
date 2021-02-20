#include <stdio.h>

int cubeByValue(int n); //function prototype
int cubeByValue(int n){return n*n*n;} //cube local variable n return result

int main(void)
{
  int number=5; //initializing the number
  printf("The original number is %d\n", number);

  number=cubeByValue(number); //pass number by value to cubeByValue
  printf("\nThe new value of number is %d\n", number);
}
