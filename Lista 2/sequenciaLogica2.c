#include<stdio.h>

void main()
{
	int x;
	int y;

	printf("prima o valor de x: ");
	scanf("%d", &x);
	printf("prima o valor de y: ");
	scanf("%d", &y);

	for (int i = 1; i <= y; ++i)
	{
		if (i % x == 0)
		{
			printf("%d\n", i);
		} else {
			printf("%d ", i);
		}
	}
}