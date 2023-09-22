#include <stdio.h>
#include <stdlib.h> // NULL, malloc, calloc, free...

int main()
{
	// alocacao de um vetor estatico (memoria stack)
	int VS[5] = {0, 10, 20, 30, 40}; // VS -> vetor stack

	puts("\n==== VETOR ESTATICO ====");
	printf("\n&VS\t%p", &VS);
	printf("\n VS\t%p\n", VS);

	for (int i = 0; i < 5; i++)
	{
		printf("\n&VS[%d]\t%p", i, &VS[i]);
		printf("\n VS[%d]\t%d\n", i, VS[i]);
	}




	// alocacao de um vetor dinamico usando malloc (memoria heap)
	// todos os elementos iniciarao com lixo
	int *VH_MAL = (int *) malloc(5 * sizeof(int)); // VH_MAL -> vetor heap malloc

	puts("\n==== VETOR DINAMICO MALLOC ====");
	printf("\n&VH_MAL\t\t%p", &VH_MAL);
	printf("\n VH_MAL\t\t%p\n", VH_MAL);

	for (int i = 0; i < 5; i++)
	{
		printf("\n&VH_MAL[%d]\t%p", i, &VH_MAL[i]);
		printf("\n VH_MAL[%d]\t%d\n", i, VH_MAL[i]);
	}




	// alocacao de um vetor dinamico usando calloc (memoria heap)
	// todo bloco alocado possui bits 0, isto é,
	// garante que todos os elementos alocados (do vetor) terão valor 0
	int *VH_CAL = (int *) calloc(5, sizeof(int)); // VH_CAL -> vetor heap calloc

	puts("\n==== VETOR DINAMICO CALLOC ====");
	printf("\n&VH_CAL\t\t%p", &VH_CAL);
	printf("\n VH_CAL\t\t%p\n", VH_CAL);

	for (int i = 0; i < 5; i++)
	{
		printf("\n&VH_CAL[%d]\t%p", i, &VH_CAL[i]);
		printf("\n VH_CAL[%d]\t%d\n", i, VH_CAL[i]);
	}

	puts("\n\n");



	return 0;
}
