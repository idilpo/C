//initializing mutidimensional arrays
#include <stdio.h>

void printArray(int a[][3]); //function prototype

int main(void)
{
  int array1[2][3] = {{1,2,3}, {4,5,6}};
  puts("Values in array1 by row are:");
  printf(array1);

  int array2[2][3] = {1,2,3,4,5};
  puts("Values in array2 by row are:");
  printf(array2);

  int array3[2][3] = {{1,2}, {4}};
  puts("Values in array3 by row are:");
  printf(array3);
}

void printArray(int a[][3])
{
  for (size_t i=0; i<=1; ++i) //loop through rows
  {
    for (size_t j=0; j<=2; ++j) //output column values
    {
      printf("%d", a[i][j]);
    }
    printf("\n"); //start new line of output
  }
}
