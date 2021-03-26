//Author: Idil Bilgic (19206730)
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//function prototypes:
int addme(int x, ...);
int multiplyme(int x, ...);
void myPrinter(const char *f, ...);

int main()
{
  printf("%d\n", addme(4,5));
  printf("%d\n", multiplyme(3,7,10));
  myPrinter("test", "alsoTest", "anotherTest", 2);
  return 0;
}

int addme(int x, ...)
{
  printf("Add Me.\n");
  int sum = 0, i; //the sum is initialised to 0 at the beginning
  va_list list; //stores info needed by va_start and va_end
  va_start(list, x); //initialized the va_list object
  for(i = 0; i < x; i++)
    {sum += va_arg(list, int);} //adds all elements together
  va_end(list); //clean up variable-length argument list
  return sum;
}

int multiplyme(int x, ...){
  printf("Mutliply Me.\n");
  va_list list;
  int m = 1, i; //the product is initialised to 0 at the beginning
  va_start(list, x);
  for(i=0; i < x; i++)
    {m *= va_arg(list, int);}
  va_end(list);
  return m;
}

void myPrinter(const char *f, ...){
  va_list args;
  va_start(args, f);
  int n=0;
  while (*f != '\0') //while the current element is not the null character
  {
    switch (*f++) //switch statement prints out all elements
    {
      case 's': //in case of a string
      {
        printf("%s\n", va_arg(args, const char *));
        break;
      }
      case 'd': //in case of an integer
      {
        printf("%d\n", va_arg(args, int));
        break;
      }
      case 'f': //in case of a double/float
      {
        printf("%f\n", va_arg(args, double));
        break;
      }
    }
    n++;
  }
va_end(args);
}
