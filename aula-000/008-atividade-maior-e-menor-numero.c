/*
	Crie uma função que calcule o mínimo e o maximo de um vetor de inteiros e
	retorne os valores em duas variáveis diferentes.
*/

#include <stdio.h>

void maiorEmenor(const int v[], int tam, int* maior, int* menor)
{
	*menor = v[0];
	*maior = v[0];

	for (int i = 0; i < tam; i++)
	{
		if (v[i] < *menor) { *menor = v[i]; }
		if (v[i] > *maior) { *maior = v[i]; }
	}

}

int main()
{
	int v[5] = {4, 7, 18, 22, 5};
	int tamanhoV = (sizeof(v) / sizeof(v[0]));

	int maior;
	int menor;

	maiorEmenor(v, tamanhoV, &maior, &menor);

	printf("\n MAIOR\t%d", maior);
	printf("\n MENOR\t%d", menor);

	return 0;
}
