#include <stdio.h>
#include <string.h>

int main(void)
{
  char county[20], names[20];
  int accNum, ages, consent, n=0, all_ages=0;

//opening the file:
  FILE *var1, *var2;
  var1 = fopen("customers.txt", "r"); //var1 stores the contents read from "customers.txt"
  var2 = fopen("customers2.txt", "w"); //var2 stores the contents written from "customers.txt"

  while(!feof(var1))
  {
    fscanf(var1,"%s %8s  %d  %d  %d" , county, names, &accNum, &ages, &consent); //reading in the variables
    if((consent==1) && (strcmp(county, "Dublin")==0)) //printing the variables accordingly:
    {
      fprintf(var2, "%s %8s  %d  %d  %d\n", county, names, accNum, ages, consent);
      all_ages += ages; //ages get summed up
      n++;
    }
  }
  int av_age = all_ages/n; //calculating the average of all ages
  fprintf(var2,"The average age: %d", av_age);

  //closing the file:
  fclose(var1);
  fclose(var2);
}
