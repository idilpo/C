//Program: Greatest Common Divisor
//Author: Idil Bilgic (19206730)

#include <stdio.h>

int gcd(); //function prototype

int main(void)
{
  int x,y;
  printf("Please enter two integers: ");
  scanf("%d %d", &x, &y);
  printf("The Greatest Common Divisor (GDC) of %d and %d is %d.\n", x, y, gcd(x,y));
}
//data_type functionName(datatype parameters);
int gcd(int x, int y) //function that calcultes gdc
{
  if (y==0){return x;}
  else {return gcd(y, x%y);}
}
