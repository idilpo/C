#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//function prototypes:
int addme(int i, ...);
int multiplyme(int i, ...);
void myPrinter(const char *f, ...);

int main()
{
  printf("%d\n", addme(4,5));
  printf("%d\n", multiplyme(3,7,10));
  myPrinter("Test", "alsoTest", "anotherTest", 2);
  return 0;
}

int addme(int i, ...)
{
  va_list varlist;
  int sum=0;
  va_start(varlist, i);
  for(int j=0; j<i; j++)
    {sum += va_arg(varlist, int);}
  va_end(varlist);
  return sum;
}

int multiplyme(int i, ...)
{
  va_list varlist;
  int m=1;
  va_start(varlist, i);
  for(int j=0; j<i; j++)
    {m *= va_arg(varlist, int);}
  va_end(varlist);
  return m;
}

void myPrinter(const char *f, ...)
{
  va_list inputs;
  int i=0;
  va_start(inputs, f);
  while (*f!='\0')
  {
    switch (*f++)
    {
      case 'd':
        printf("%d\n", va_arg(inputs, int));
        break;
      case 'f':
        printf("%f\n", va_arg(inputs, double));
        break;
      case 's':
        printf("%s\n", va_arg(inputs, const char *));
        break;
    }
    i++;
  }
va_end(inputs);
}
