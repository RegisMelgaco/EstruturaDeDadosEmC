#include<stdio.h>

int list[101];
int count = 5;

void makeList()
{
	int i = 0;
	int buffer = 0;

	while(i < count)
	{
		printf("prima o numero %d da lista\n", i);
		scanf("%d", &buffer);
		if(buffer < 256)
		{
			list[i] = buffer;
			i++;
		}
	}
}

void printList()
{
	printf("resposta!\n");

	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", list[i]);
	}
}

void printEvenOdd() {
	int odd = 0;
	for (int i = 0; i < count; ++i)
	{
		if (list[i] % 2 == 0)
		{
			odd++;
		}
	}
	printf("There are %d odd number(s) and %d even number(s).\n",odd , (count - odd) );
}

void simpleSort()
{
	int buffer;
	int k;

	for (int i = 0; i < count; ++i)
	{
		k = i;
		for (int j = i; j < count; ++j)
		{
			if (list[j] >= list[i])
			{
				k = j;
			}
		}
		buffer = list[i];
		list[i] = list[k];
		list[k] = buffer;
	}
}

void main()
{
	makeList();

	simpleSort();

	printList();

	printEvenOdd();

	system("pause");
}