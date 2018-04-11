#include<stdio.h>

void main()
{
	int len;
	int list[101];
	int array[101];
	int repited[52];
	int buffer;
	int k;
	int i = 0;
	int j = 1;
	repited[0] = 0;

	//input len

	printf("Input the size of the list: ");
	scanf("%d", &len);

	//input list
	for (int i = 0; i < len; ++i)
	{
		printf("Prima o elemento %d da lista:\n",i );
		scanf("%d",&(list[i]));
	}
	
	//sort

	for (int i = 0; i < len; ++i)
	{
		k = i;
		for (int j = i+1; j < len; ++j)
		{
			if (list[k] > list[j])
			{
				k = j;
			}
		}
		buffer = list[i];
		list[i] = list[k];
		list[k] = buffer;
	}

	printf("Lista ordenada\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d\n", list[i]);
	}

	//treat repetitions

	k = 0;
	while(i < len)
	{
		if (list[i] == list[i + 1])
		{
			repited[j] = list[i];
			repited[0] = 1;
			j++;
		} else {
			array[k] = list[i];
			k++;
		}
		i++;
	}

	for (int i = 0; i < len; ++i)
	{
		list[i] = array[i];
	}

	//return of treatment

	if(repited[0])
	{
		printf("A lista sem elementos repetidos eh\n");
		for (int i = 0; i < k; ++i)
		{
			printf("elemento %d: %d\n", i, list[i] );
		}
		printf("Os elementos repetidos sao\n");
		for (int i = 1; i < j; ++i)
		{
			printf("%d\n", repited[i]);
		}
	} else {
		printf("Nao ah elementos repetidos na lista.\n");
	}

	//binary search

	printf("Qual elemento voce deseja buscar?\n");
	scanf("%d", &buffer);

	j = 0;
	i = k;
	while(j <= i)
	{
		k = (i + j)/2;
		if (buffer == list[k])
		{
			printf("o endereco eh: %d\n", k);
			break;
		}
		if (buffer < list[k])
		{
			i = k - 1;
		} else {
			j = k - 1;
		}
	}

	system("pause");
}