for (size_t i=0; i<5; i++)
{
  n[i]=0;
}

printf("%s%13s\n", "ArrayA", "ArrayB");

for (size_t j=0; j<5; j++)
{
  printf("%7u%13d\n", i, array);
}

}


int disp[2][3];
 /*Counter variables for the loop*/
 int i, j;
 for(i=0; i<2; i++) {
    for(j=0;j<3;j++) {
       printf("Enter value for disp[%d][%d]:", i, j);
       scanf("%d", &disp[i][j]);
    }
 }
 //Displaying array elements
 printf("Two Dimensional array elements:\n");
 for(i=0; i<2; i++) {
    for(j=0;j<3;j++) {
       printf("%d ", disp[i][j]);
       if(j==2){
          printf("\n");
       }
    }
 }
 return 0;



const int CITY = 2;
const int WEEK = 7;
int main()
{
int temperature[CITY][WEEK];

// Using nested loop to store values in a 2d array
for (int i = 0; i < CITY; ++i)
{
  for (int j = 0; j < WEEK; ++j)
  {
    printf("City %d, Day %d: ", i + 1, j + 1);
    scanf("%d", &temperature[i][j]);
  }
}
printf("\nDisplaying values: \n\n");

// Using nested loop to display vlues of a 2d array
for (int i = 0; i < CITY; ++i)
{
  for (int j = 0; j < WEEK; ++j)
  {
    printf("City %d, Day %d = %d\n", i + 1, j + 1, temperature[i][j]);
  }
}
return 0;
}




int main()
{
    int arr[100] = { 0 };
    int i, x, pos, n = 10;

    // initial array of size 10
    for (i = 0; i < 10; i++)
        arr[i] = i + 1;

    // print the original array
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // element to be inserted
    x = 50;

    // position at which element
    // is to be inserted
    pos = 5;

    // increase the size by 1
    n++;

    // shift elements forward
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];

    // insert x at pos
    arr[pos - 1] = x;

    // print the updated array
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
