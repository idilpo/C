//using indexing and pointer notations with arrays:

#include <stdio.h>
#define ARRAY_SIZE 4

int main(void)
{
  int b[] = {10,20,30,40};
  int *bPtr = b;

  puts("Arrat b printed with: \nArray Index notation");

  for (size_t i=0; i<ARRAY_SIZE; ++i)
  {
    printf("b[%u] = %d\n", i, b[i]); //loop through b
  }
  
  //output array b using bPtr and pointer/offset notation
  puts("\nPointer/offset notation where\n"
        "the pointer is the array name");

  for (size_t offset=0; offset<ARRAY_SIZE; ++offset)
  {
    printf("*(b + %u) = %d\n", offset, *(bPtr + offset)); //loop through b
  }
}
