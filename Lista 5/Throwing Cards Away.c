#include <stdio.h>

int pilha[110];
int marcador;
int n;


void main()
{
	while(1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		for (marcador = 1; marcador <= n; ++marcador)
		{
		pilha[marcador - 1] = marcador;
		}
		printf("Discarded cards:");
		marcador = 0;
		while(1)
		{
			// descarta
			printf(" %d", pilha[marcador]);
			marcador++;
			// move para baixo
			pilha[n] = pilha[marcador];
			marcador++;
			n++;
			// parametro de parada
			if (marcador == n - 1)
			{
				printf("\nRemaining card: %d\n", pilha[marcador]);
				break;
			} else {
				printf(",");
			}
		}
	}
}