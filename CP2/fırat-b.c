// Created by Firat Metin 19205389
#include <stdio.h>
#include <stdarg.h>
#define maxSize 1000 //helps with inputting longer strings into the array.
int print(int number, ...)//prints out calculations from sumall and productall
{
    int i; va_list ap;
    va_start(ap, number);
    int collect = va_arg(ap, int);
    printf("%d\n", collect);
    return collect;
}
int sumAll(int arguments, ...)
{
    int sum=0; va_list ap;
    va_start(ap, arguments);
    for(int i=0; i<arguments;i++){sum += va_arg(ap, int);}
    va_end(ap);
    printf("Sum : ");print(1, sum);
    return sum;
}
int productAll(int arguments, ...)
{
    int mult=1; va_list ap;
    va_start(ap, arguments);
    for(int i=0; i<arguments;i++){mult *= va_arg(ap, int);}
    va_end(ap);
    printf("Product : ");print(1, mult);
    return mult;
}
void myPrinter(const char *print, ...)
{
    va_list ap;
    va_start(ap, print);
    while (*print != '\0') { // while not null.
        switch (*print++) {//switch statement:
            case 'S': //string printing.
                printf("%s\n", va_arg(ap,const char *));
                break;
            case 'I': //integer printing.
                printf("%d\n", va_arg(ap,int));
                break;
            case 'D'://float/double printing.
                printf("%f\n", va_arg(ap,double));
                break;
        }
    }
}
int main(void)
{
    int n1,n2,n3; double n4; char n5[maxSize]; //max 4 inputs could be made to the program.
    printf("Please input integer,integer, integer, float and a string : ");
    scanf("%d%d%d%lf%s", &n1,&n2,&n3,&n4,n5); //scan all the input
    sumAll(3,n1,n2,n3); //only 3/4 arguments are used as they are digit-related
    productAll(3, n1,n2,n3);//only 3/4 arguments are used as they are digit-related
    myPrinter("IIIDS",n1,n2,n3,n4,n5);
}

