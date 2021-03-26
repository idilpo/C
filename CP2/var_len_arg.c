#include <stdio.h>
#include <stdarg.h>

double average(int i, ...)
{
  double total = 0; //initialised the total
  va_list ap; //stores information needed by va_start and va_end
  va_start(ap, i); //initialized the va_list object

  for(int j=1; j<=i; ++j) //process variable-length argument list
  {
    total += va_arg(ap, double);
  }

  va_end(ap); //clean up variable-length argument list
  return total/i; //calculating the average
}
int main(void)
{
  double w = 37.5;
  double x = 22.5;
  double y = 1.7;
  double z = 10.2;

  printf("%s%.1f%\n%s%.1f%\n%s%.1f%\n%s%.1f%\n\n", "w = ", w, "x = ", x, "y = ", y, "z = ", z);
  printf("%s%.3f\n%s%.3f\n%s%.3f\n%s%.3f\n", "The average of w and x is ", average(2,w,x),
    "The average of w, x and y is ", average(3,w,x,y), "The average of w, x, y and z is ", average(4,w,x,y,z));
}
