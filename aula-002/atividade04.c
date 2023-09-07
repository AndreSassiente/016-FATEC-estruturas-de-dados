/*
    Escreva uma função que recebe dois ponteiros para inteiros e troca os
    valores apontadospor eles.
*/

#include <stdio.h>

void trocarValores(int *pA, int *pB) {

    int aux;
    aux = *pA;
    *pA = *pB;
    *pB = aux;

}

int main() {

    int A = 2;
    int B = 5;

    int *ponteiroA = &A;
    int *ponteiroB = &B;

    printf("\nVALOR DE A: %d", A);
    printf("\nVALOR DE B: %d\n\n", B);

    trocarValores(ponteiroA, ponteiroB);

    printf("\nVALOR DE A: %d", A);
    printf("\nVALOR DE B: %d\n\n", B);


    return 0;
}
