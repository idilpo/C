// Program: Conversion to lower to uppercase
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <ctype.h>

void conversion(char *sPtr); //function prototype
void conversion(char *sPtr)
{
  while (*sPtr != '\0') //the loop runs until the null character
  {
    *sPtr = toupper(*sPtr); //toupper already exists in the ctype.h library
    ++sPtr; //increment so the pointer points to the next character
  }
}

int main(void)
{
  int vowels, numbers, consonants; //initializing the variables
  char str[100]; //initializing the array
  char *ptr; //initializing the pointer
  ptr = str; //pointer is assigned to the array

  printf("Enter any string (max 100 characters with no spaces): "); //asks for user input
  fgets(str, 100, stdin); //reads the string

  for(*ptr=str[0]; *ptr!='\0'; ptr++) //loop runs until the null character
  {
    if(*ptr=='a'|| *ptr=='e'|| *ptr=='i'|| *ptr=='o'|| *ptr=='u'|| *ptr=='A'|| *ptr=='E'|| *ptr=='I'|| *ptr=='O' || *ptr=='U')
    {
		  vowels++; //the vovel count is incremented
    }
    else if (*ptr=='1' || *ptr=='2' || *ptr=='3' || *ptr=='4' || *ptr=='5' || *ptr=='6' || *ptr=='7' || *ptr=='8' || *ptr=='9' || *ptr=='0')
    {
      numbers++; //the number count is incremented
    }
    else {consonants++;} //the consonants count is incremented
  }
 	printf("Total number of vowels in the string = %d \n", vowels);
  printf("Total number of numbers in the string = %d \n", numbers);
  printf("Total number of consonants in the string = %d \n", consonants-1); //minus 1 because the else counts null character as well

  printf("The string before conversion: %s \n", str);
  conversion(str); //function call
  printf("The string after conversion: %s \n", str);
}
