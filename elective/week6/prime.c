#include <stdio.h>
#include <math.h>

void sieve_of_erathosthenes(int limit, int temp_arr[])
{
      int c1, c2;
      for(c1 = 0; c1 < limit; c1++)
      {
            temp_arr[c1] = 1;
      }
      temp_arr[0] = 0, temp_arr[1] = 0;
      for(c1 = 2; c1 < sqrt(limit); c1++)
      {
            for(c2 = c1*c1; c2 < limit; c2 = c2 + c1)
            {
                  temp_arr[c2] = 0;
            }
      }
}

int main()
{
      int limit, count;
      printf("\nEnter The Limit N To Print Prime Numbers:\t");
      scanf("%d", &limit);
      int temp_arr[limit];
      sieve_of_erathosthenes(limit, temp_arr);
      printf("\n");
      for(count = 0; count < limit; count++)
      {
            if(temp_arr[count] == 1)
            {
                  printf("%d\t", count);
            }
      }
      printf("\n");
      return 0;
}











#include<stdio.h>
int main()
{
	int n;
	printf("Enter the Number: ");
	scanf("%d",&n);
	int i,j,arr[n];

	for(i=1; i<=n; i++)
	{
		arr[i]=1;
	}

	for(i=2; i*i<=n; i++)
	{
		if(arr[i]==1)
		{
			for(j=i*i; j<=n; j+=i)
			{
				arr[j]=0;
			}
		}
	}
	for(i=2; i<n; i++)
	{
		if(arr[i]==1)
			printf("%d\t",i);
	}
}











#include <stdio.h>
int main()
{
	int first, last;
	printf("Enter the First number to last Number of Limit to Check: ");
	scanf("%d %d",&first, &last);

	int i,j, arr[last];

	for(i=2; i<=last; i++) {arr[i]=1;}

	for(i=2; i*i<=last; i++)
	{
		if(arr[i]==1)
		{
			for(j=i*i; j<=last; j+=i)
			{
				arr[j]=0;
			}
		}
	}

	for(i=first; i<=last; i++)
	{
		if(arr[i]==1) {printf("%d\t",i);}
	}
}
