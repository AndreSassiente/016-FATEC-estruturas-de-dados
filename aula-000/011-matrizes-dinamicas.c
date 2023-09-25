#include <stdio.h>
#include <stdlib.h> //malloc, calloc, free, NULL...

#define rows 2
#define cols 3

int main()
{
	int count = 0;

	// ALOCACAO DINAMICA DE MATRIZES
	int **m = (int **) calloc(rows, sizeof(int*));

	// PARA CADA LINHA DA MATRIZ
	for (int i = 0; i < rows; i++)
	{
		m[i] = (int*) calloc(cols, sizeof(int));
	}

	printf("\n&M\t\t%p", &m);
	printf("\n M\t\t%p\n\n", m);

	for (int i = 0; i < rows; i++)
	{
		printf("\n&M[%d]\t\t%p", i, &m[i]);
		printf("\n M[%d]\t\t%p", i, m[i]);

		for (int j = 0; j < cols; j++)
		{
			m[i][j] = count++;

			printf("\n&M[%d][%d]\t%p", i, j, &m[i][j]);
			printf("\n M[%d][%d]\t%d", i, j, m[i][j]);
		}

		puts("\n");
	}



	// DESALOCACAO DE MATRIZ DINAMICA
	for (int i = 0; i < rows; i++)
	{
		free(m[i]);
	}

	free(m);
	m = NULL;

	return 0;
}
