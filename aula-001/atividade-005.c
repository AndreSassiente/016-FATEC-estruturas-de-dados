/*
	* Faça um programa em C que leia uma matriz de 5 linhas
	com 3 colunas para armazenar a pontuação de 5 atletas
	em 3 aparelhos. As notas são um número inteiro de 0 a 10,
	geradas aleatoriamente.

	* O programa deve:

		* Listar para cada aparelho qual foi o atleta com a
		maior nota.

		* Listar para cada atleta qual foi a sua menor nota
		nos 3 aparelhos
*/

#include <stdlib.h>
#include <stdio.h>

int main(){

	int matriz[5][3];
	int atletas[5] = {1, 2, 3, 4, 5};
	int maiorNota;
	int menorNota[5];
	int atletaMaiorNota[3];
	int aparelhoMenorNota[5];
	int i,j,k = 0;

    //matriz 5x3 gerada aleatoriamente
    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) { matriz[i][j] = rand() % 10; }
    }

    //impressão de notas na tela para conferência
    printf("ATLETA         NOTAS\n");
    printf("           A1   A2   A3");
    for(i=0;i<5;i++){
        printf("\n");
        printf("#%i \t", atletas[i]);
        printf("|");
        for(j=0;j<3;j++){
            printf("| %i |", matriz[i][j]);
        }
        printf("|");
    }
    printf("\n\n\n");


    // verificar qual maior nota e a quem pertence
    for( j = 0; j < 3; j++) {

        maiorNota = 0;

        for ( i = 0 ; i < 5; i++) {

            if (maiorNota < matriz[i][j]) {

                maiorNota = matriz[i][j];
                atletaMaiorNota[j] = atletas[i];

            }

        }
    }


    // verificar em qual aparelho cada atleta teve a menor nota
    for (i = 0; i < 5; i++) {

        menorNota[i] = 10;

        for (j = 0; j < 3; j++) {

            if (matriz[i][j] < menorNota[i]) {

                menorNota[i] = matriz[i][j];
                aparelhoMenorNota[i] = j+1;

            }

        }

    }


    // impressão dos resultados na tela
    printf("MAIORES NOTAS EM CADA APARELHO\n\n");
    printf("APARELHO\tATLETA");
    printf("\n-------------------------");
    for (i = 0; i < 3; i++) { printf("\nA%i\t\t#%i", i+1, atletaMaiorNota[i]); }
    printf("\n\n\n");

	printf("MENORES NOTAS DE CADA ATLETA\n\n");
	printf("ATLETA\t\tAPARELHO");
    printf("\n-------------------------");
    for (i = 0; i < 5; i++) { printf("\n#%i\t\tA%i", i+1, aparelhoMenorNota[i]); }
	printf("\n\n\n");


	return 0;
}
