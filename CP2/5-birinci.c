#include <stdio.h>
#include <string.h>

int main(void)
{
  char county[20], name[20];
  int accNum, ages, agreed, n=0, average_age = 0;

//opening the file:
  FILE *var1, *var2;
  var1 = fopen("customers.txt", "r"); //var1 stores the contents read from "customers.txt"
  var2 = fopen("customers2.txt", "w"); //var2 stores the contents written from "customers.txt"

  while(!feof(var1))
  {
    fscanf(var1,"%s%s%d%d%d" , county, names, &accNum, &ages, &consent);
    if((consent == 1) && (strcmp(county, "Dublin") == 0))
    {
      fprintf(var2, "%s%s%d%d%d\n", county, names, accNum, ages, consent);
      average_age += ages;
      n++;
    }
  }
  average_age = Ages/n;
  fprintf(var2,"\nThe average age: %d", average_age);

  //closing the file:
  fclose(var1);
  fclose(var2);
}
