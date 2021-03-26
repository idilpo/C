#include <stdio.h>
#include <stdarg.h>
#define MAX_SIZE 1000 //helps with inputting longer strings into the array.

int print(int n, ...)//prints out calculations from sumall and productall
{
  int i; va_list ap;
  va_start(ap, n);
  int collect = va_arg(ap, int);
  printf("%d\n", collect);
  return collect;
}

int addme(int args, ...)
{
  int sum=0; va_list ap;
  va_start(ap, args);
  for(int i=0; i<args; i++)
    {sum += va_arg(ap, int);}
  va_end(ap);
  printf("Sum : ");print(1, sum);
  return sum;
}

int multiplyme(int args, ...)
{
  int m=1; va_list ap;
  va_start(ap, args);
  for(int i=0; i<args; i++)
    {m *= va_arg(ap, int);}
  va_end(ap);
  printf("Multiplication : ");print(1, m);
  return m;
}

void myPrinter(const char *print, ...)
{
  va_list ap;
  va_start(ap, print);
  while (*print!='\0') // while not the null character
  {
    switch (*print++)
    {
      case 's':
          printf("%s\n", va_arg(ap,const char *));
          break;
      case 'd':
          printf("%d\n", va_arg(ap,int));
          break;
      case 'f':
          printf("%f\n", va_arg(ap,double));
          break;
    }
  }
}

int main(void)
{
  int n1,n2,n3;
  double n4;
  char n5[MAX_SIZE];
  printf("Please input integer,integer, integer, float and a string: ");
  scanf("%d%d%d%lf%s", &n1,&n2,&n3,&n4,n5); //scans all the input
  addme(3,n1,n2,n3);
  multiplyme(3, n1,n2,n3);
  myPrinter("IIIDS",n1,n2,n3,n4,n5);
}
