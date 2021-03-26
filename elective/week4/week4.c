#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num1, num2, dif; //num1 and num2 are random numbers generated
int size; //random values that the user wants to generate between 1 and "size"
int sum=0; //sum of numbeers are initialized to0

int main(void)
{
  printf("Enter the range you would like to calculate for (1 to N): \n");
  scanf("%d", &size);

  srand(time(0)); //random value generator
  double differences[size]; //array that contains different distances between randomly generated numbers

  for (int i=0; i<size; i++)
  {
    num1 = 1+(rand()%size);
    num2 = 1+(rand()%size);

    if (num1>num2){dif=num1-num2;}
    else if (num2>num1){dif=num2-num1;}
    else {dif=0;} //when num1==num2

    differences[i] = dif;//distances are collected in an array
    sum += differences[i]; //sum of all distancees are calculted
    printf("%d and %d then %d\n", num1, num2, dif); //this line is only for debugging
    printf("%.2f\n", differences[i]); //this line is only for debugging
  }

  double average = sum/size;
  printf("\nThe average distance between numbers is %.2f.\n", average);
}
