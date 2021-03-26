#include <stdio.h>
int main()
{
	int n;
	int i,j,a[n];

	printf("Enter a number that you'd like to calculate primes for: ");
	scanf("%d",&n);

	for(i=1; i<=n; i++) {a[i]=1;}

	for(i=2; i*i<=n; i++)
	{
		if(a[i]==1)
		{
			for(j=i*i; j<=n; j+=i) {a[j]=0;}
		}
	}
	for(i=2; i<n; i++)
	{
		if(a[i]==1)
			printf("%d\n", i);
	}
}
