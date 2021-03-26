#include <stdio.h>
#include <stdarg.h>

//function prototypes:
void addme(int i, ...);
void multiplyme(int i, ...);
void myPrint(const char *f, ...);

int arraySize=10000;
int a[];
int main()
{
  printf("Enter the integers you'd like to compute calculations for: \n");
  scanf("%d ", &a[arraySize]);

  //char *p = a;
  //void (f[3]) (int arraySize, char *p) = {addme, multiplyme, myPrint};
  void (f[3]) (int arraySize, int a[]) = {addme, multiplyme, myPrint};
  printf("Enter 0 for ADDITION, 1 for MULTIPLICATION, 2 for PRINT or enter 3 to TERMINATE the program: ");
  size_t input; //variable to hold user's input
  scanf("%zd", &input);

  while((input!=0) && (input!=1) && (input!=2) && (input!=3))
  {
    printf("An invalid number is entered. ");
    break;
  }

  if(input==3){printf("You've chosen 3, program will TERMINATE.\n");}
  if(input>=0 && input<=2) {(f[input])(arraySize, a);} //executes the entered computation
}

void addme(int i, ...)
{
  int sum=0; //the sum is initialised to 0 at the beginning
  va_list ap; //stores info needed by va_start and va_end
  va_start(ap, i); //initialized the va_list object
  for(int j=0; j<=arraySize; j++)
    {sum+=va_arg(ap, int);} //adds all elements together
  va_end(ap);  //clean up variable-length argument list
  printf("%d ", sum);
}

void multiplyme(int i, ...)
{
  int multiplication=0;
  va_list ap;
  va_start(ap, i);
  for(int j=0; j<=arraySize; j++)
    {multiplication+=va_arg(ap, int);} //multiplies all elements together
  va_end(ap);
  printf("%d ", multiplication);
}

void myPrint(int i, ...)
{
  va_list ap;
  va_start(ap, i);
  for(int j=0; j<=arraySize; j++)
    {printf("%d\n", va_arg(ap, int));}
  va_end(ap);
}
