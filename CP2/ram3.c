//reading a random-access file sequentially
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
  if((cfPtr = fopen("accounts.dat", "rb")) == NULL) //wb tells that we are reading from a binary file
  {
    puts("File could not be opened.")
  }
  else
  {
    printf("%-6s%-16s%-11s%10s\n", "Acc", "Last Name", "First Name", "Balance");

    //read all records from a file (until eof)
    while(!feof(cfPtr))
    {
      //create clientData with default information
      struct clientData client = {0, "", "", 0.0};
      int result = fread(&client, sizeof(struct clientData), 1, cfPtr);

      if(result!=0 && client.accNum!=0) //display record
      {
        printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);
      }
    }

    fclose(cfPtr); //fclose closes the file
  }
}
