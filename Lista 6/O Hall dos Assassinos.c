#include <stdio.h>

char nomes[10][100000];
int mortes_ou_morto[100000];
int i = 0;
int j;
void main()
{
	//entrada
	while(scanf("%s", (nomes + (i*10))) != EOF)
	{
		scanf("%d", mortes_ou_morto+i);
		i++;
	}

	for (j = 0; j <= i; ++j)
	{
		printf("%s %d\n", (nomes + (j*10)), mortes_ou_morto[j]);
	}
}