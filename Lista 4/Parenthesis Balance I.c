#include <stdio.h>

int contagem;
short correto;
char expressao[10000];
int i;

void main()
{
	while (scanf("%s",&expressao) != EOF)
	{
		correto = 1;
		// quebra do loop
		if (expressao[0] == NULL)
		{
			break;
		}
		// teste se tem erros por contagem
		contagem = 0;
		i = 0;
		while (*(expressao + i) != NULL)
		{
			if (expressao[i] == '(') // soma na contagem
			{
				contagem++;
			}
			if (expressao[i] == ')') // subtrai na contagem
			{
				contagem--;
			}
			if (contagem < 0) // testa se a contagem fica negativa
			{
				correto = 0;
				break;
			}
			i++;
		}
		if (contagem != 0)
		{
			correto = 0;
		}
		if (correto)
		{
			printf("correct\n");
		} else {
			printf("incorrect\n");
		}
	}
}