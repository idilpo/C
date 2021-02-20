//constant pointer to non-constant data:
#include <stdio.h>

int main(void)
{
  int x, y;
  int * const ptr = &x;
  //ptr is a constant pointer to an integeer that can be modified through ptr,
  //but ptr always points to the same memory location
  *ptr = 7; //allowed: *ptr is not const
  ptr = &y; //error: ptr is const, cannot assign new address
}
