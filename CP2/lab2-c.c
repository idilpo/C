//Program: Decimal to Binary Conversion
//Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <math.h>

long long converter(int n)
{
  long long bin=0;
  int rem, i=1, step=1;
  while (n!=0)
  {
    rem = n%2; //remainder is what remains when the number is divided to 2
    n/=2; //n/2 is now the numerator for the next step
    bin += rem*i;
    i*=10;
    step++; //step is incremented each time the number is divided to 2
  }
  return bin;
}

int main()
{
  int n;
  printf("Input a decimal number: ");
  scanf("%d", &n);
  printf("Binary number %lld \n", converter(n));
}
