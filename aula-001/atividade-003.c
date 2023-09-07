/*
	* Fa�a um programa em C que declare dois vetores de
	n�meros reais com 20 elementos cada. Esses elementos
	devem ser gerados aleatoriamente.

	* Crie um novo vetor que seja a intersec��o entre os 2
	vetores anteriores, ou seja, que ter� em apenas os
	n�meros que est�o em ambos os vetores.

	* N�o deve conter n�meros repetidos.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float vetor1[20];
float vetor2[20];
float vetor3[20];
int i,j,k;

int main()
{
    // vetores gerados aleatoriamente
    srand(time(NULL));
    for (i = 0; i < 20; i++)
    {
        vetor1[i] = rand() % 100;
        vetor2[i] = rand() % 100;

    }

    // intersec��o entre os 2 vetores anteriores sem repeti��o de elementos
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (vetor1[i] == vetor2[j])
            {
                for (k = 0; k < 20; k++)
                {
                    if (vetor3[k] == vetor1[i])
                    {
                        break;
                    }
                    else if (vetor3[k] == 0)
                    {
                        vetor3[k] = vetor1[i];
                        k = 20;
                    }
                }
            }
        }
    }


    // impress�o do vetor 03 criado
    printf("VETOR 03: \n");
    for (i = 0; i < 20; i++)
    {

        if (vetor3[i] != 0)
        {
            printf("%.2f\t", vetor3[i]);
        }

    }

    printf("\n\n");

    return 0;
}


