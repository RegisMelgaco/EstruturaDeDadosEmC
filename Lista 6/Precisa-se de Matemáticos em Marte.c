/*
	ideia: formar uma lista que vai ter a quantidade pessoas por bug, para dai fazer a contagem de quantas pessoas ainda restam.
		manter a contagem: vou troca o numero de pessoas por zero quando forem abduzidos
		contagem: percorro a lista somando todos os valores
*/

#include <stdio.h>

int numero_de_bugs;
int carga_dos_bugs[100000];
char requizicao = 'a';
int num_requizicao;
int contagem_de_pessoas = 0;
int i;

int main(){
	scanf("%d", &numero_de_bugs); //entrada do numero de bugs

	for (i = 0; i < numero_de_bugs; ++i) // leitura de cada bug
	{
		scanf("%d", (carga_dos_bugs + i));
	}

	while(scanf(" %c", &requizicao) != EOF)
	{
		scanf(" %d", &num_requizicao);
		num_requizicao--;
		if (requizicao == 'a')
		{
			carga_dos_bugs[num_requizicao] = -1;
		} else if (requizicao == '?')
		{
			for (i = 0; i < num_requizicao; ++i)
			{
				if (carga_dos_bugs[i] != -1) contagem_de_pessoas += carga_dos_bugs[i];
			}
			printf("%d\n", contagem_de_pessoas);
			contagem_de_pessoas = 0;
		} else {
			printf("entrada invalida\n");
		}
	}
	return 0;
}