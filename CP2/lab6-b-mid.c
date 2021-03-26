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
  myPrinter("test", "alsoTest", "anotherTest", 2);
}

int addme(int i, ...)
{
  va_list varList; //stores info needed by va_start and va_end
  int sum=0; //the sum is initialised to 0 at the beginning
  va_start(varList, i); //initialized the va_list object
  for (int j=0; j<i; j++)
    {sum+=va_arg(varList, int);} //adds all elements together
  va_end(varList);  //clean up variable-length argument list
  return sum;
}

int multiplyme(int i, ...)
{
  int m=1;
  va_list varList;
  va_start(varList, i);
  for(int j=0; j<i; j++)
    {m += va_arg(varList, int);} //multiplies all elements together
  va_end(varList);
  return m;
}

void myPrinter(const char *f, ...)
{
  va_list args;
  va_start(args, f);
  int i=0;
  while (*f!='\0') //while the current element is not the null character
  {
    switch (*f++) //switch statement prints out all elements
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
    i++;
  }
  va_end(args);
}
