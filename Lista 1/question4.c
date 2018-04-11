#include<stdio.h>

void getN(int *n)
{
	printf("Prima um numero primo\n");
	scanf("%d", n);
}

int ehPrimo(n)
{
	for (int i = 2; i < n/2; ++i)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void searchAnothers(int n)
{
	int prime;
	prime = n - 1;
	while(!ehPrimo(prime))
	{
		prime--;
	}
	printf("primo 1: %d\n", prime );
	prime--;
	while(!ehPrimo(prime))
	{
		prime--;
	}
	printf("primo 2: %d\n", prime );
	prime = n + 1;
	while(!ehPrimo(prime))
	{
		prime++;
	}
	printf("primo 3: %d\n", prime );
	prime++;
	while(!ehPrimo(prime))
	{
		prime++;
	}
	printf("primo 4: %d\n", prime );
}

void main()
{
	int n;
	getN(&n);

	while(!ehPrimo(n))
	{
		getN(&n);
	}

	searchAnothers(n);

	system("pause");
}