#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fatias = 2;
	int linhas = 2;
	int colunas = 3;
	int count = 0;

	// ALOCACAO DINAMICA DE MATRIZES 3D
	int ***m = (int***) calloc(fatias, sizeof(int**));

	// para cada fatia
	for (int k = 0; k < fatias; k++)
	{
		m[k] = (int**) calloc(linhas, sizeof(int*));

		// para cada linha
		for (int i = 0; i < linhas; i++)
		{
			m[k][i] = (int*) calloc(colunas, sizeof(int*));
		}
	}

	printf("\n&M\t\t%p\tM\t\t%p\n\n", &m, m);

	printf("========================================================================\n");

	// para cada fatia
	for (int k = 0; k < fatias; k++)
	{
		printf("\n&M[%d]\t\t%p\tM[%d]\t\t%p", k, &m[k], k, m[k]);

		// para cada linha
		for (int i = 0; i < linhas; i++)
		{
			printf("\n&M[%d][%d]\t%p\tM[%d][%d]\t\t%p",
			k, i, &m[k][i], k, i, m[k][i]);

			// para cada coluna
			for (int j = 0; j < colunas; j++)
			{
				m[k][i][j] = count++;

				printf("\n&M[%d][%d][%d]\t%p\tM[%d][%d][%d]\t%d",
				k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
			}
			puts("");
		}

		puts("");
		printf("\n========================================================================\n");

	}

	// DESALOCAR MATRIZ DINAMICA
	// para cada fatia
	for (int k = 0; k < fatias; k++)
	{
		// para cada linha
		for (int i = 0; i < linhas; i++)
		{
			free(m[k][i]);
		}

		free(m[k]);
	}

	free(m);
	m = NULL;


	return 0;
}
