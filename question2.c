#include<stdio.h>

int n = 5;
int ny;
int x[101];
int y[101];

void readVectorX()
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x[i]);
	}
}

void printVector(int vec[101], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\n", vec[i]);
	}
}

void createVectorY()
{
	for (int i = 0; i < n; ++i)
	{
		if (x[i] > 10 && x[i] < 40)
		{
			y[ny] = x[i];
			ny++;
		}
	}
}

void main()
{
	readVectorX(n);

	printf("Vetor x\n");

	printVector(x,n);

	printf("Vetor y\n");

	createVectorY();

	printVector(y,ny);

	system("pause");
}