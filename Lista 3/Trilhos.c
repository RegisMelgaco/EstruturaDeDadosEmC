		#include <stdio.h>

int limPilha = 1000;
int topo = -1;
int estacao[1000];
int trem[1000];
int teste[1000];
int len;
int i;
int j;
int k;

int isempty ()
{
	if (topo == -1) { return 1; }
	else return 0;
}
int isfull ()
{
	if (topo == limPilha) { return 1; }
	else { return 0; }
}
int peek ()
{
	return estacao[topo];
}
int pop ()
{
	if (!isempty())
	{
		topo = topo - 1;
		return estacao [topo + 1];
	} else {
		printf("Não ha elementos na pilha!\n");
	}
}
void push (int elemento)
{
	if (!isfull())
	{
		topo = topo + 1;
		estacao[topo] = elemento;
	} else {
		printf("A pilha esta cheia!\n");
	}
}

void main ()
{
	//laço dos blocos
	while(1)
	{
		//leitura do len e teste de fim de código
		scanf("%d", &len);
		if (len == 0)
		{
			break;
		}
		//teste dos trens
		while(1)
		{
			//leitura do primeiro numero do trem e teste do fim de bloco
			scanf("%d", trem);
			if (trem[0] == 0)
			{
				break;
			}
			for (i = 1; i < len; ++i) //leitura do resto do trem
			{
				scanf("%d", (trem + i));
			}
			i = len - 1; // marcador para trem
			j = len; // marcador da ordem
			while(1) //tentativa de reprodução do trem
			{
				push(trem[i]);
				while(peek() == j && !isempty())
				{
					j--;
					pop();
				}
				if (i < 1)
				{
					break;
				}
				i--;
			}
			// resposta
			if(j == 0)
			{
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			// limpeza da pilha
			while(!isempty())
			{
				pop();
			}
		}
		printf("\n");
	}
}