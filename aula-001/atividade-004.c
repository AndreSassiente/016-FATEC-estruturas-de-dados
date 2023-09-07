/*
	* Faça um programa em C que leia uma matriz 4 x 4 de
	números inteiros gerados aleatoriamente.

	* Exibir na tela a localização (linha e a coluna) do maior e
	do menor valor.

*/

#include<stdlib.h>
#include<stdio.h>

int main() {

	int matriz[4][4];
	int linhaMaior, colunaMaior, linhaMenor, colunaMenor;
	int maior = 0;
	int menor = 100;
	int i, j, k = 0;


    // matriz 4x4 gerada automaticamente
    srand(time(NULL));

    for (i = 0; i < 4; i++) {

        for (j = 0; j < 4; j++) { matriz[i][j] = rand()%100; }

    }


    // matriz gerada sendo impressa na tela
    for (i = 0; i < 4; i++) {

        printf("\n");

        for (j = 0; j < 4; j++){ printf("%2d\t", matriz[i][j]); }
    }

    // descobrir qual o maior valor
    for (i = 0; i < 4; i++) {

        for (j = 0; j < 4; j++) {

            if (maior < matriz[i][j]) {

                maior = matriz[i][j];
                linhaMaior = i + 1;
                colunaMaior = j + 1;

            }

        }

    }

	// altera o valor da variavel menor para o maior valor encontrado
    menor = maior;

    // verifica qual menor valor a partir do maior valor encontrado
    for (i = 0; i < 4; i++){

        for (j = 0; j < 4; j++) {

            if (menor > matriz[i][j]) {

                menor = matriz[i][j];
                linhaMenor = i + 1;
                colunaMenor = j + 1;
            }
        }
    }

    // impressão dos resultados na tela
    printf("\n\n\n");
    printf("MAIOR VALOR\t%i\nLINHA\t\t%2i\nCOLUNA\t\t%2i\n", maior, linhaMaior, colunaMaior);

    printf("\n\n\n");
    printf("MENOR VALOR\t%2i\nLINHA\t\t%2i\nCOLUNA\t\t%2i\n", menor, linhaMenor, colunaMenor);

    printf("\n\n\n");
	return 0;
}
