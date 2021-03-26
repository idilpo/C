//creating a random-access file sequentially
#include <stdio.h>

struct clientData //client structure definition
{
  unsigned int accNum;
  char lastName[15];
  char firstName[10];
  double balance;
}; //end structure clientData

int main(void)
{
  FILE *cfPtr; //accounts.dat file pointer

  //fopen opens the file, exits if the file cannot be opened
  if((cfPtr = fopen("accounts.dat", "wb")) == NULL) //wb tells that we are writing to a binary file
  {
    puts("File could not be opened.")
  }
  else //create clintData with default information
  {
    struct clientData blankClient {0, "", "", 0.0};
    //struct clieentData is the name of the struct
    //blankClient is what we call it
    for(unsigned int i=1; i<=100; ++i)
    {
      fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
    }
    fclose(cfPtr); //fclose closes the file
  }
}
