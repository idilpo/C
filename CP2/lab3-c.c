// Program: Circle
// Author: Idil Bilgic (19206730)

#include <stdio.h>
#include <math.h>

int main(void)
{
  double a, r, c; //stands for area, radius, circumference

  printf("Enter the radius of a circle: ");
  scanf("%lf", &r);

  while (r<=0)
  {
    printf("Radius cannot be smaller than or equal to 0. Please re-enter: ");
    scanf("%lf", &r);
  }
  
  a=M_PI*r*r;
  printf("Area of circle: %.3f\n", a);
  c=2*M_PI*r;
  printf("Circumference of circle: %.3f\n", c);
}
