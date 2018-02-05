#include<stdio.h>

int list[101];
int count = 5;

void getList

void simpleSort()
{
	int buffer;
	int k;

	for (int i = 0; i < count; i++)
	{
		k = i;
		for (int j = i; j < count; j++)
		{
			if (list[j] > list[i])
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

	simpleSort();

	printf("resposta!\n");

	for (int i = 0; i < count; i++)
	{
		printf("%d\n", list[i]);
	}

	system("pause");
}