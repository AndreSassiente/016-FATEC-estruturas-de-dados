#include <stdio.h>
#include <stdlib.h>	// NULL, calloc, malloc, free...

void soma_vetor_com_escalar(int v[], int n, int escalar)
{
	for  (int i = 0; i < n; i++)
	{
		v[i] += escalar;
	}
}

void print_vetor(const int *v, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n&V[%d]\t%p\tV[%d]\t%d", i, &v[i], i, v[i]);
		//v[i]++; // é o mesmo que v[i] + 1 == *(v + 1) + 1
	}

	puts("");
}

void desaloca_vetor(int **v)
{
	int *aux = *v;
	free(aux);
	*v = NULL;
}

int main()
{
	// alocacao de um vetor estatico (memoria stack)
	puts("\nVETOR ESTATICO");
	int vs[5] = {0, 10, 20, 30, 40};

	print_vetor(vs, 5);
	soma_vetor_com_escalar(vs, 5, 9);
	print_vetor(vs, 5);

	// alocacao de um vetor dinamico com calloc (memoria heap)
	puts("\nVETOR DINAMICO COM CALLOC");
	int *vh = (int *) calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		vh[i] = i * 100;
	}

	print_vetor(vh, 5);
	soma_vetor_com_escalar(vh, 5, 9);
	print_vetor(vh, 5);

	// desalocando o vetor dinamico
	// free(vh);
	// vh = NULL;

	puts("\nANTES DA FUNCAO DE DESALOCAR VETOR DINAMICO");
	printf("\n&VH\t%p\tVH\t%p\n\n", &vh, vh);

	desaloca_vetor(&vh);

	puts("\nDEPOIS DA FUNCAO DE DESALOCAR VETOR DINAMICO");
	printf("\n&VH\t%p\tVH\t%p", &vh, vh);

	puts("\n\n");

	return 0;

}
