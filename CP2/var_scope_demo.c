#include <stdio.h>
//function prototypes:
void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x=1; //global variable

int main(void)
{
  int x=5;
  printf("local x in outer scope of main is %d\n", x);

  {
    //start new scope
    int x=7;
    printf("local x in inner scope of main is %d\n", x);
    //end scope
  }

  printf("local x in outer scope of main is %d\n", x);

  useLocal(); //has automatic local x
  useStaticLocal(); //has static local x
  useGlobal(); //uses global x
  useLocal(); //automatic local x has reinitialized
  useStaticLocal(); //static local x retains its prior value
  useGlobal(); //global x also retains its value

  printf("\nlocal x in main is %d\n", x);
}

void useLocal(void)
{
  int x=25; //initialized each time useLocal is called
  printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
  ++x;
  printf("\nlocal x in useLocal is %d after exitting useLocal\n", x);
}

//initializes static local variable x only the first time the function is called
//value of x is saved between calls to this function
void useStaticLocal()
{
  //initialized at once
  static int x=50;
  printf("\nlocal static x is %d on entering useStaticLocal\n", x);
  ++x;
  printf("\nlocal static x is %d on exitting useLocal\n", x);
}

void useGlobal()
{
  //modifies global variable x during each call
  printf("\nglobal x is %d on entering useGlobal\n", x);
  x*=10;
  printf("\nglobal x is %d on exitting useGlobal\n", x);
}
