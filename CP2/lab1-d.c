//Program: Quarry Calculator
//Author: Idil Bilgic (19206730)

#include <stdio.h>
int c,p; //variables for cement and purchase

int main(void)
{
  printf("Please enter the amount of bags of cement you would like to purchase (1 bag is 10kg): \n");
  scanf("%d", &c);

  if ((1<=c) && (c<=10)) {p = c * 10;}
  if ((11<=c) && (c<=50)) {p = 100 + ((c-10)*9.50);}
  if (c>=51) {p = 100 + (40*9.50) + ((c-50)*9);}

  printf("Your purchase will be %d Euros.\n", p);
}
