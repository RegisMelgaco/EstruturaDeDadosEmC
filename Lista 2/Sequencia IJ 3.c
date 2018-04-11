#include<stdio.h>

void main()
{
	int i;
	int j;

	for (i = 1; i <= 9; i = i + 2)
	{
		for (j = i + 6; i + 3 < j; j--)
		{
			printf("I=%d J=%d\n", i, j );
		}
	}
}