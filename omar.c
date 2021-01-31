#include <stdio.h>
#include <math.h>

int main(void)
{
  int x0=0, y0=0;
  int x1,y1,x2,y2,x3,y3;
  double r1,r2,r3,per;
  scanf("%d%d\n", x1, y1);
  scanf("%d%d\n", x2, y2);
  scanf("%d%d\n", x3, y3);

  r1 = sqrt(pow(x1, 2)+pow(y1,2));
  r2 = sqrt(pow(x2, 2)+pow(y2,2));
  r3 = sqrt(pow(x3, 2)+pow(y3,2));

  per = r1+r2+r3;
  printf("The triangle perimeter is %d", per);
}
