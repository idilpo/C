#include <stdio.h>

int main(void)
{
  int n[5];

  for (size_t i=0; i<5; ++i)
  {
    n[i]=0; //set the element at location i to 0
  }

  printf("%s%13s\n", "Element", "Value");

  //output contents of array n in tabular form
  for (size_t i=0; i<5; ++i)
  {
    printf("%7u%13d\n", i, n[i]);
  }
}
