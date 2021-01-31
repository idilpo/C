#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int seed; //number used to seed thee random number generator

  printf("%s", "Enter seed: ");
  scanf("%d", &seed);

  srand(seed); //seed the random number generator

  for (int i=1; i<=10; ++i) //loops 10 times
  {
    printf("%10d\n", 1+(rand()%6)); //random number between 1 and 6
    if (i % 5 == 0) {puts("");} //if counter is divisible by 5, begin a new line of output
  }
}
