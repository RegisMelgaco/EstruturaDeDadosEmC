#include <stdio.h>

void main()
{
	int numTestes;
	int n[62];
	int seqFibo[62];
	int i;
	int k;

	printf("prima o numero de testes\n");
	scanf("%d", &numTestes);

	//entrada dos valores dos testes e segura o maior valor

	for (i = 0; i < numTestes; ++i)
	{
		printf("prima o valor %d para teste:", i);
		scanf("%d", n + i);

		if(i == 0 || n[i] > k) k = n[i];
	}

	//gerar sequencia de fibonacci ate o maior valor

	seqFibo[0] = 0;
	seqFibo[1] = 1;
	for (i = 2; i <= k; ++i)
	{
		seqFibo[i] = seqFibo[i-1] + seqFibo[i-2];
	}

	//prime os valores desejados

	for (i = 0; i < numTestes; ++i)
	{
		printf("Fib(%d) = %d\n", n[i], seqFibo[n[i]]);
	}
}