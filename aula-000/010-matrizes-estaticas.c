#include <stdio.h>
#define rows 2	// linhas
#define cols 3	// colunas

int main()
{
	int m[rows][cols] = {{0, 1, 2}, {3, 4, 5}};

	printf("\n&M\t\t%p", &m);
	printf("\n M\t\t%p\n\n", m);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("\n&M[%d][%d]\t%p", i, j, &m[i][j]);
			printf("\n M[%d][%d]\t%d", i, j, m[i][j]);
		}

		puts("\n");
	}

	return 0;
}
