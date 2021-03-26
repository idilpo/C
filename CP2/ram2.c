//writing data randomly to a random-access file
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
  //rb+ tells that we are reading from and writing to a binary file
  if((cfPtr = fopen("accounts.dat", "rb+")) == NULL)
  {
    puts("File could not be opened.")
  }
  else //create clintData with default information
  {
    struct clientData blankClient {0, "", "", 0.0};

    printf("%s\n", "Enter account number (1 to 100, 0 to end input): ");
    scanf("%d\n", &client.accNum);

    //user enters information which is copied into file
    while(client.accNum!=0)
    {
      //user enters last name and balance:
      printf("%s\n", "Enteer lastname, firstname, balance");

      //set record lastName, firstName, and balance value
      fscanf(stdin, "%14s%9s%lf", client.lastname, client.firstName, &client.balance);

      //seek position in the file to user-specified record
      //SEEK_SET indicates that the seek starts in the beginning of the file
      fseek(cfPtr, (client.accNum-1) * sizeof(struct clientData), SEEK_SET);

      //write useer-specified information in file
      fwrite(&client, sizeof(struct clientData), 1, cfPtr);

      //enable useer to input another account number
      printf("%s\n", "Enter account number: ");
      scanf("%d", &client.accNum);
    }

    fclose(cfPtr); //fclose closes the file
  }
}
