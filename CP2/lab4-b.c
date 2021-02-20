// Program: Conversion to lower to uppercase
// Author: Idil Bilgic (19206730)

#include <stdio.h>

void copyArrayIndexWay(char * const newArray1, const char * const originalArray1, int max)
{
  for (int i=0; i<max; i++) {newArray1[i]= originalArray1[i];} //assigning each index of the original array to the new one
  puts(newArray1); //converts ascii values into characters
}

void copyPointerWay(char *newArray2, char *originalArray2, int max)
{
  char *p = originalArray2; //declared a pointer that points to the array
  char *t = newArray2; //used a temporary value to switch the values
  char *e = &originalArray2[max-1]; //declared a variable as the last element in the array
  while (p <= e) //loop keeps on running until the pointer reaches the end of the array
  {
    *t = *p;  //using the temporary value to copy the contents
    t++;
    p++;
  }
  puts(newArray2);
}

int main(void)
{
  char originalArray1[] = "COMP10120";
  char originalArray2[] = "COMP10110";
  int max = 10;
  char newArray1[max]; //originalArray1 will be copied to this new array
  char newArray2[max]; //originalArray2 will be copied to this new array
  copyArrayIndexWay(newArray1, originalArray1, max);
  copyPointerWay(newArray2, originalArray2, max);
}
