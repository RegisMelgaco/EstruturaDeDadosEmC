/*
Atividade:
Construa um pseudo-simulador, para simular o funcionamento da fila de hotcat, que receba
como entrada o numero de servidores distribuindo o lanche e retorne o tempo médio de
espera, o numero de pessoas atendidas, e o numero Maximo de clientes simultaneamente na
fila.

tempo medio
numero de pessoas atendidas
numero maximo simultaneo
*/

/* Logica para a média: quando é adicionado um novo elemento que representa o aluno na fila, é colocado o tempo em que o aluno foi introduzido na fila. Posteriormente, quando é feito a retirada do elemento da fila, é feita a diferensa com o tempo atual e por sua vez é usado no calculo da media, como é facil ver */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int tempo_prox = 0;     // contador do tempo apartir do começo da destribuição em segundos
int tempo = 1;          // tempo absoluto da simulação em segundos
int maximo = -1;        // contador do maximo de alunos
int alunos = 0;         // contagem de alunos
int frente = -1;        // marcador de onde é a frente da fila
int atras = -1;         // marcador de onde é a trazeira da fila
int tam = 1000;         // tamanho da array fila
int fila[1000];         // array fila onde estarão os alunos
int tempos_espera;        // soma dos tempos gastos nas filas
int servidores;         // quantos servidores estão servindo a comida
int i;                  // variavel auxiliar

int esta_vazio()          // teste se a array fila está vazia
{
	if (frente == -1 && atras == -1)
	{
		return 1;
	} else {
		return 0;
	}
}

int esta_cheio()          // teste se a array fila está cheia
{
	if ((atras + 1) % tam == (frente) % tam)
	{
		return 1;
	} else {
		return 0;
	}
}

void chega_mais()         // soma mais um aluno na contagem de alunos, coloca-o na fila, conta os alunos na fila, além de relatar se a array está cheia
{
	if (esta_vazio())
	{
		atras = 0;
		frente = 0;
	} else if (esta_cheio())
	{
		printf("A fila ja esta cheia!\n");
	} else {
		atras++;
	}
	fila[atras % tam] = tempo;

	if (atras - frente > maximo)
	{
		maximo = atras - frente;
	}
}

void servir()             // soma os tempos gastos e faz a adição do elemento da fila
{
	alunos++;
	tempos_espera += tempo - fila[frente];
	if (esta_vazio())
	{
		printf("A fila ja esta vazio\n");
	} else if (atras == frente)
	{
		frente = -1;
		atras = -1;
	} else {
		frente++;
	}
}

void quando_chega_prox()  // definição de quanto tempo vai levar até o proximo aluno
{
	if (tempo_prox < 900)                   // Entre 30 a 15 minutos antes
	{
		tempo_prox += 15 + rand() % 11;
	} else if (tempo_prox < 1500)           // Entre 15 a 5 minutos antes
	{
		tempo_prox += 4 + rand() % 13;
	} else if (tempo_prox < 1800)           // Entre 5 e o inicio da distribuição
	{
		tempo_prox += 2 + rand() % 7;
	} else if (tempo_prox < 2400)           // Entre o inicio e 10 minutos depois 
	{
		tempo_prox += 2 + rand() % 17;
	} else if (tempo_prox < 3000)           // Entre 10 a 20 minutos após a distribuição
	{
		tempo_prox += 5 + rand() % 31;
	} else if (tempo_prox < 3600)           // Entre 20 a 30 minutos após a distribuição 
	{
		tempo_prox += 25 + rand() % 11;
	}
}

void main()
{
	srand((unsigned) time(NULL));      // entradade de um numero pra geração de um pseudo-aleatorio
	scanf("%d", &servidores);          // entrada do numero de servidores
	
	do             // simulação
	{
		if (tempo_prox < tempo && tempo_prox < 3600)  // adição de novas pessoas à fila
		{
			quando_chega_prox();
			chega_mais();
		}
		if ((!esta_vazio()) && (tempo % 4) == 0 && tempo >= 1800)  // distribuição
		{
			for (int i = 0; (i < servidores) && (!esta_vazio()); ++i)
			{
				servir();
			}
		}

		tempo++;
	} 
	while(tempo < 3600);

	printf("Tempo médio de espera: %d segundos\n", tempos_espera/alunos);
	printf("Total de atendidos: %d\n", alunos);
	printf("Numero Maximo de alunos na fila: %d\n", maximo);
}