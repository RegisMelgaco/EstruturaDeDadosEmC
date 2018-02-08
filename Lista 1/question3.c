#include<stdio.h>

void createArray(int *array, int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("Prima o elemento %d da lista:\n",i );
		scanf("%d",array);
		array++;
	}
}

void printArray(int *array, int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("i = %d: %d\n",i , *array);
		array++;
	}
}

void unify(int *a, int *b, int *c, int count)
{
	for (int i = 0; i < count; ++i)
	{
		*c = *a;
		c++;
		*c = *b;
		c++;

		a++;
		b++;
	}
}

int seguencialSearch(int *c, int x , int count)
{
	for (int i = 0; i < count*2; ++i)
	{
		if ( *c == x )
		{
			return 1;
		}
		c++;
	}
	return -1;
}

void main()
{
	int count;
	int a[101];
	int b[101];
	int c[201];
	int x;
	int busca;

	printf("Prima o tamanho das arrays:\n");
	scanf("%d", &count);

	createArray(a, count);
	printArray(a, count);

	createArray(b, count);
	printArray(b, count);

	unify(a, b, c, count);
	printf("C:\n");
	printArray(c, count*2);

	printf("Prima um elemento para buscar\n");
	scanf("%d", &busca);
	x = seguencialSearch(c, busca , count);

	if (x == -1)
	{
		printf("Não existe esse elemento na lista\n");
	} else {
		printf("O elemento esta na lista\n");
	}

	system("pause");
}