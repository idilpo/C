/*
Author: 19205389 Mehmet Firat Metin
Write a program in C to find area and circumference of circle. Sample Output:
Enter the radius of a circle: 5
Area of circle=78.5
Circumference of circle  =31.4
Ensure adequate error checking/handling is in place.
*/
#include <stdio.h>
#include <math.h>

void circumferance(int r)
{
    double C = 2*M_PI*r;
    printf("The circumferance is: %lf\n", C);
}

void area(int r)
{
    double A = M_PI*pow(r, 2);
    printf("The area is: %lf\n", A);
}
int main(void)
{
    double r, stat,temp;// Radius
    printf("Please enter the radius:");
    scanf("%lf",&r);
    while(r <= 0) // radius can't be negative nor 0, validation & verfication
    {
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Input %.2f is invalid; please enter a new number: ",r);
        stat = scanf("%lf", &r);
	}
    circumferance(r); area(r);
}
