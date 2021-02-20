//Program: Multiplication Tables
#include <stdio.h>

void multi(); //function prototype

int main(void)
{
  int n,m; //n:size of the table, m:number that will be produced
  printf("%s", "Please enter a number: ");
  scanf("%d", &n);
  printf("%s", "Please enter the size of the multiplication table: ");
  scanf("%d", &m);

  multi();
}

void multi()
{
  int n,m;
  int result=0;
  for (int i=1; i<=m; i++)
  {
    result=i*n;
    printf("%d\n", result);
    i++;
  }
}
