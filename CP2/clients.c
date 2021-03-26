#include <stdio.h>

int main(void)
{
  FILE *cfPtr; //cfPtr = clients.txt file pointer

  if ((cfPtr = fopen("clients.txt", "w")) == NULL)
  {
    puts("File could not be opened");
  }
  else
  {
    puts("Enter the account, name and balance.");
    puts("Enter EEOF to end input.");
    printf("%s\n", "?");

    unsigned int account; //account number
    char name[30]; //account name
    double balance; //account balance

    scanf("%d%29s%lf", &account, name, &balance);

    while (!feof(stdin)) //writes account, name and balance into file with fprintf
    {
      fprintf(cfptr, "%d %s %.2f\n", account, name, balance);
      printf("%s", "? ");
      scanf("%d%29s%ld", &account, name, &balance);
    }

    fclose(cfPtr); //fclose closes file
  }
}
