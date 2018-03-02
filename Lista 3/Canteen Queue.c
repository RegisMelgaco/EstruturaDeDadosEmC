#include <stdio.h>

int num_testes;
int num_notas;
int notas[1000];
int notas_ordenadas[1000];
int certos;
int i;
int j;
int k;
int l;

void main ()
{
	// leitura do numero de testes
	scanf("%d", &num_testes);
	for (j = 0; j < num_testes; ++j)
	{
		// leitura do numero de notas
		scanf("%d", &num_notas);
		// leitura das notas
		for (i = 0; i < num_notas; ++i)
		{
			scanf("%d", (notas + i));
			notas_ordenadas[i] = notas[i];
		}
		// ordenação da fila
		for (i = 0; i < num_notas - 1; ++i)
		{
			l = i;
			for (k = i; k < num_notas; ++k)
			{
				if (notas_ordenadas[l] <= notas_ordenadas[k])
				{
					l = k;
				}
			}
			k = notas_ordenadas[i];
			notas_ordenadas[i] = notas_ordenadas[l];
			notas_ordenadas[l] = k;
		}
		// contagem de quantos estão na ordem
		certos = 0;
		for (i = 0; i < num_notas; ++i)
		{
			if (notas_ordenadas[i] == notas[i])
			{
				certos++;
			}
		}
		// output
		printf("%d\n", certos);
	}
}