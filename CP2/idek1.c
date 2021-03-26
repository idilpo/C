#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int addme(int n, ...);
int multiplyme(int n, ...);
void myPrinter(const char *f, ...);

int main()
{
  printf("%d\n", addme(1, 3)); //Calls the 'addme' function.

  printf("%d\n", multiplyme(2, 5, 3)); //Calls the 'multiplyme' function.

  myPrinter("Test", "Test2", "Test3", 1); //Calls the 'myPrinter' function.

  return 0;
}

int addme(int n, ...) //My addme method, that adds variables.
{
  printf("This is the addme function.\n");
  va_list vlist;

  //Declaring Variables.
  int sumOf = 0;
  int i;

  va_start(vlist, n);//Initializes the va_list object.

  for(i = 0; i < n; i++)
  {
    sumOf += va_arg(vlist, int);
  }
  va_end(vlist);//Clean up variable-length argument list

  return sumOf;
}

int multiplyme(int n, ...)//My multiplyme method, that multiplies variables.
{
  printf("This is the multiplyme function.\n");
  va_list vlist;

  //Declaring Variables.
  int p = 1;
  int i;


  va_start(vlist, n);//Initializes the va_list object.
  for( i = 0; i < n; i++)
  {
    p *= va_arg(vlist, int);
  }

  va_end(vlist);//Clean up variable-length argument list

  return p;
}

void myPrinter(const char *f, ...)//My myPrinter method.
{
  printf("This is the myPrinter function.\n");
  va_list args;
  int n;


  va_start(args, f); //Initializes the va_list object.

  n = 0;
  while (*f != '\0')
  {
    //Switch statement that prints out everything held within variables.
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
va_end(args);//Clean up variable-length argument list
}
