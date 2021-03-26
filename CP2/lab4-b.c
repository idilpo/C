// Program: Conversion to lower to uppercase
// Author: Idil Bilgic (19206730)

#include <stdio.h>

void copyArrayIndexWay(); //function prototype
void copyArrayIndexWay(char * const newArray1, const char * const originalArray1, int max_size)
{
  for (int i=0; i<max_size; i++) {newArray1[i]= originalArray1[i];} //assigning the new array index by index according to the original one
  puts(newArray1); //converts ascii values into characters
}

void copyPointerWay(); //function prototype
void copyPointerWay(char *newArray2, char *originalArray2, int max_size)
{
  char *p = originalArray2; //declared a pointer that points to the array
  char *t = newArray2; //used a temporary value to switch the values between arrays
  char *e = &originalArray2[max_size-1]; //declared a variable as the last element in the array
  while (p <= e) //loop keeps on running until the pointer reaches the end of the array
  {
    *t = *p;  //using the temporary value to copy the contents
    t++; //temporary count is incremented for the next loop
    p++; //pointer count is incremented for the next loop
  }
  puts(newArray2);
}

int main(void)
{
  char originalArray1[] = "COMP10120";
  char originalArray2[] = "COMP10110";
  int max_size = 10; //maximum size that the array can have is assigned
  char newArray1[max_size]; //originalArray1 will be copied to this new array
  char newArray2[max_size]; //originalArray2 will be copied to this new array
  
  printf("\n");
  copyArrayIndexWay(newArray1, originalArray1, max_size); //function call for copying index
  printf("The content in originalArray1 is copied to newArray1.\n");
  printf("While doing so, a for loop is used to iterate over the original array and assign each index to the new array.\n");
  printf("\n");
  copyPointerWay(newArray2, originalArray2, max_size); //function call for copying pointer
  printf("The pointer in originalArray2 is copied to newArray2.\n");
  printf("While doing so, a while loop uses temporary values to copy pointers. Both the temporary count and the pointer count is incremented with each loop.\n");
}
