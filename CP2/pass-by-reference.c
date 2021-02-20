#include <stdio.h>

void cubeByValue(int *nPtr); //function prototype
void cubeByValue(int *nPtr)
{
  //calculate the cube of *nPtr (actually modifies number in main)
  *nPtr = *nPtr * *nPtr * *nPtr;
}

int main(void)
{
  int number=5; //initializing the number
  printf("The original number is %d\n", number);

  cubeByValue(&number); //pass number by value to cubeByValue
  printf("\nThe new value of number is %d\n", number);
}
