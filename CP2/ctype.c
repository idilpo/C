//non-constant pointer to non-constant data:
#include <stdio.h>
#include <ctype.h>

void conversion(char *sPtr); //function prototype
void conversion(char *sPtr)
{
  while (*sPtr != '\0')
  {
    *sPtr = toupper(*sPtr); //toupper already exists in the ctype.h library
    ++sPtr; //increment so the pointer points to the next character
  }
}

int main(void)
{
  char str[100]; //initializing th array
  printf("Enter any string (max 100 characters with no spaces): "); //asks for user input
  fgets(str, 100, stdin); //reads the string

  printf("The string before conversion: %s \n", str);
  conversion(str); //function call
  printf("The string after conversion: %s \n", str);
}
