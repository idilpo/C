//applying sizeeof to an array name returns the number of bytes in the array

#include <stdio.h>
#define SIZE 20

size_t getSize(float *ptr); //prototype
size_t getSize(float *ptr)
{
  return sizeof(ptr);
}

int main(void)
{
  float array[SIZE];
  printf("The number of bytes in the array is %u"
        "\nThe number of bytes returned by getSize is %u", sizeof(array), getSize(array));
}
