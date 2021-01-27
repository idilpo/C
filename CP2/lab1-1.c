//my implementation before but it has way too many variables
#include <stdio.h>

double nug1, nug2, nug3, nug4; //declaration of variables
double min, max; //declaration of the lightest and the heaviest values
double min_d, max_d; //declaration of the US dolar values for the max and min values
double total;

int main(void)
{
  printf("Please enter type the weight of gold nuggets in terms of gram: \n");
  scanf("%lf%lf%lf%lf", &nug1, &nug2, &nug3, &nug4);

  /* checking for the lightest value: */
  min = nug1;
  if(nug1 > nug2)
  {
    min = nug2;
    if (nug2 > nug3)
    {
      min = nug3;
      if (nug3 > nug4)
      {
        min = nug4;
      }
    }
  }

  /* checking for the heaviest value: */
  max = nug1;
  if(nug1 < nug2)
  {
    max = nug2;
    if (nug2 < nug3)
    {
      max = nug3;
      if (nug3 < nug4)
      {
        max = nug4;
      }
    }
  }

  min_d = min * 59.26; //1 g gold nugget is 59.26 US dollars
  printf("The lightest gold nugget is %.2lf g and it's value is %.4lf.\n", min, min_d);

  max_d = max * 59.26;
  printf("The heaviest gold nugget is %.2lf g and it's value is %.4lf.\n", max, max_d);

  total = (nug1 + nug2 + nug3 + nug4) * 59.26;
  printf("The total value of all gold nuggets is %.4lf.\n", total);

}
