//Program: Golden nuggets
//Author: Idil Bilgic (19206730)

#include <stdio.h>
#define MAX_SIZE 3

double nugget[MAX_SIZE]; //array declaration
int i,j;
double total=0; //the total value is initialised
double min, max; //lightest and heaviest values
double min_d, max_d; //max and min values for the value of gold

int main(void)
{
  for (i=0; i<4; i++)
  {
    printf("Please enter type the weight of gold nuggets in terms of kilogram: \n");
    scanf("%lf", &nugget[i]);
  }

  for (i=0; i<4; i++){ total = total + nugget[i]; } //calculates the total value for the gold

  for (i=0; i<4; ++i)
  {
    for (j=i+1; j<4; ++j) //checks for the max and min values
    {
      if (nugget[i] > nugget[j])
      {
        max = nugget[i];
        nugget[i] = nugget[j];
        nugget[j] = max;
        min = nugget[0];
      }
    }
  }

  min_d = min * 59260; //1 g gold nugget is 59.26 US dollars = 1 kg gold nugget is 59260 US dollars
  printf("The lightest gold nugget is %.2lf kg and it's value is %.lf US dollars.\n", min, min_d);

  max_d = max * 59260;
  printf("The heaviest gold nugget is %.2lf kg and it's value is %.lf US dollars.\n", max, max_d);

  printf("The total value of all gold nuggets is %.lf US dollars.\n", total * 59260);
}
