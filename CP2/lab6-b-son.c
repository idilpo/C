#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//function prototypes:
int addme(int i, ...);
int multiplyme(int i, ...);
void myPrinter(const char *f, ...);

int main()
{
  addme(4,5);
  multiplyme(3,7,10);
  myPrinter("Test", "alsoTest", "anotherTest", 2);
  return 0;
}

int addme(int i, ...)
{
  int sum=0;
  va_list ap;
  va_start(ap, i);
  for(int j=0; j<i; j++)
    {sum += va_arg(ap, int);}
  va_end(ap);
  printf("Sum: %d", sum);
  return sum;
}

int multiplyme(int i, ...)
{
  int m=1;
  va_list ap;
  va_start(ap, i);
  for(int j=0; j<i; j++)
    {m *= va_arg(ap, int);}
  va_end(ap);
  printf("Multiplication: %d", m);
  return m;
}

void myPrinter(const char *f, ...)
{
  va_list args;
  va_start(args, f); //Initializes the va_list object.
  int n=0;
  while (*f != '\0')
  {
    switch (*f++)
    {
      case 's':
      {
        printf("%s\n", va_arg(args, const char *));
        break;
      }
      case 'd':
      {
        printf("%d\n", va_arg(args, int));
        break;
      }
      case 'f':
      {
        printf("%f\n", va_arg(args, double));
        break;
      }
    }
    n++;
  }
va_end(args);
}
