//Program: Leap Year
//Author: Idil Bilgic (19206730)

#include <stdio.h>
int year;
int main(void)
{
  printf("Please enter a year: ");
  scanf("%d", &year);

  //leap years should be evenly divisible to 4 but not evenly divisible to 100:
  if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0)
    printf("%d is a leap year", year);
  else
    printf("%d is not a leap year.\n", year);
}
