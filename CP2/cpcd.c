//constant pointer to constant data:
#include <stdio.h>

int main(void)
{
  int x=5, y;
  const int *const ptr = &x;
  printf("%d\n", *ptr);
  *ptr = 7; //error: *ptr is const, cannot assign new value
  ptr = &y; //error: ptr is const, cannot assign new address
}
