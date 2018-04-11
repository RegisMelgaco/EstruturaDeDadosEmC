#include<stdio.h>

int n = 5;
int ny;
int nw = 0;
int x[101];
int y[101];
int w[51];

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

void createVectorW()
{
	for (int i = 0; i < n; i = i + 2)
	{
		w[nw] = x[i];
		nw++;
	}
}

int searchZ(int z)
{
	for (int i = 0; i < n; ++i)
	{
		if (x[i] == z)
		{
			printf("O elemento %d exite na lista na posicao: %d\n",z ,i );
			return 1;
		}
	}
	printf("O elemento %d nao existe na lista\n",z );
	return 0;
}

void searchSmallestAndBigest()
{
	int menor;
	int maior;
	for (int i = 0; i < n; ++i)
	{
		if (!menor || x[i] < menor)
		{
			menor = x[i];
		}
		if (!maior || x[i] > maior)
		{
			maior = x[i];
		}
	}

	printf("O maior eh %d\n", maior );
	printf("O menor eh %d\n", menor );
}

void main()
{
	readVectorX(n);

	printf("Vetor x\n");

	printVector(x,n);

	createVectorY();

	printf("Vetor y\n");

	printVector(y,ny);

	createVectorW();

	printf("Vetor w\n");

	printVector(w,nw);

	searchZ(2);

	searchZ(0);

	searchSmallestAndBigest();

	system("pause");
}