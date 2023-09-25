#include <stdio.h>
#include <stdlib.h>

#define fatia 2
#define linha 2
#define coluna 3

int main()
{
    // 02 fatias, 02 linhas, 03 colunas
    int m[fatia][linha][coluna] =
    {
        // fatia [0]
        {
            { 0, 1, 2 },		//linha [0]
            { 3, 4, 5 } 		//linha [1]
        },

        // fatia [1]
        {
            { 6, 7, 8 },		//linha [0]
            { 9, 10, 11 }	    //linha [1]
        },
    };

    printf("\n&M\t\t%p", &m);
    printf("\n M\t\t%p\n\n", m);

    printf("==========================================================");

    // para cada fatia
    for (int k = 0; k < fatia; k++)
    {
        // para cada linha
        for (int i = 0; i < linha; i++)
        {
            // para cada coluna
            for (int j = 0; j < coluna; j++)
            {
                printf("\n&M[%d][%d][%d]\t%p\tM[%d][%d][%d]\t%d",
                       k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
            puts("");
        }

        printf("==========================================================");
    }

    puts("\n");

    return 0;
}
