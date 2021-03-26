//non-constant pointer to constant data:
#include <stdio.h>
//sPtr cannot be used to modify the character to which it points, read-only pointer.
void printCharacters(const char *sPtr);
void printCharacters(const char *sPtr)
{
  for (; *sPtr!='\0'; ++sPtr) {printf("%c\n", *sPtr);} //loop through entire string
}

int main(void)
{
  char str[]="print characters of a string";

  puts("The string is: ");
  printCharacters(str);
  puts("");
}
