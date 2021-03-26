#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_COUNT 12

const char *strings[] =
{
  "COMP10120", "is", "my", "favourite", "module", "and",
  "I", "learn", "lots", "of", "interesting", "things"
};

void jumble()
{
  srand(time(NULL)); //used to randomise
  int size = STR_COUNT;
  if (size>1)
  {
    for (int i=0; i<size-1; i++) //the loop runs from the first index until the null index
    {
      int j = rand() % STR_COUNT; //pick a random index j to swap
      const char* temp = strings[j];
      strings[j] = strings[i];
      strings[i] = temp;
    }
  }
}

void output_str()
{
  printf("The jumbled string is:\n");
  for (int k=0; k<STR_COUNT; k++) {printf("%s ", strings[k]);}
}

void select()
{
  srand(time(NULL)); //used to randomise
  int random = rand() % STR_COUNT;
  printf("A randomly selected word: %s\n", strings[random]);
}

int main()
{
  printf("The original string is:\n");
  for (int k=0; k<STR_COUNT; k++) {printf("%s ", strings[k]);} //goes through the loop and prints the initial strings
  printf("\n");
  jumble();
  output_str();
  printf("\n");
  select();
}
