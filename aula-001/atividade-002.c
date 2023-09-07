/*
	Faça um programa em C com dois vetores com 5 números
	inteiros cada, gerados aleatoriamente.

	* Na sequência, ordenar os vetores na ordem crescente.
	Para a ordenação utilize o método bolha.

	* Criar um terceiro vetor com 10 posições em ordem
	crescente, resultante da intercalação dos dois vetores.

	* Exibir os elementos do terceiro vetor na tela.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int vetor1 [5];
    int vetor2 [5];
    int vetor3 [10];
    int aux;
    int i;
    int j;

    srand(time(NULL));




	// vetor 01 gerado aleatoriamente
    for (i = 0; i < 5; i++) { vetor1[i] = rand() % 100;}

    // vetor 02 gerado aleatoriamente
    for (i = 0; i < 5; i++) { vetor2[i] = rand() % 100;}




	// vetor 01 ordenado em ordem crescente
    for( i = 0; i < 5; i++ ) {

        for( j = i + 1; j < 5; j++ ) {

            if ( vetor1[i] > vetor1[j] ) {

                aux = vetor1[i];
                vetor1[i] = vetor1[j];
                vetor1[j] = aux;

            }

        }

    }

	// vetor 02 ordenado em ordem crescente
    for( i = 0; i < 5; i++ ) {

        for( j = i + 1; j < 5; j++ ) {

            if ( vetor2[i] > vetor2[j] ) {

                aux = vetor2[i];
                vetor2[i] = vetor2[j];
                vetor2[j] = aux;

            }

        }

    }




	// vetor 03 resultante da intercalação vetor 01 + vetor 02
	for (i = 0; i < 5; i++)		{ vetor3[i] = vetor1[i]; }
    for (i = 0; i < 5; i++ )	{ vetor3[i+5] = vetor2[i]; }




	// vetor 03 ordenado em ordem crescente
	for( i = 0; i < 10; i++ ) {

        for( j = i + 1; j < 10; j++ ) {

            if ( vetor3[i] > vetor3[j] ) {

                aux = vetor3[i];
                vetor3[i] = vetor3[j];
                vetor3[j] = aux;

            }

        }

    }




    // vetor 03 exibição na tela
    printf("vetor 03 exibido na tela:\n");
    for (i = 0; i < 10; i++) { printf("%d\t", vetor3[i]); }

    return 0;
}
