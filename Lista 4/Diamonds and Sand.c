#include <stdio.h>

char teste[1000];
int abertos;
int contagem;
int testes;
int i, j;

void main()
{
	scanf("%d", &testes);

	for (j = 0; j < testes; ++j)
	{
		scanf("%s", teste);

		i = 0;
		contagem = 0;
		abertos = 0;

		while(1)
		{
			if (teste[i] == NULL)
			{
				break;
			}
			if (teste[i] == '<')
			{
				abertos++;
			} else if (teste[i] == '>')
			{
				if (abertos > 0)
				{
					contagem++;
					abertos--;
				}
			}
			i++;
		}
		printf("%d\n", contagem);
	}
}