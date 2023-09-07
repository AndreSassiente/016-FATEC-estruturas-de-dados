/*
    Crie um array de strings, onde cada elementos do array �
    um ponteiro para um conjunto de caracteres (string).
    Em seguida, escreva uma fun��o que recebe esse array e conta quantas
    strings come�am com a letra A.
*/

#include <stdio.h>
#include <string.h>

int contagemA(char *strings[], int tamanho) {

    int i = 0;
    int cont = 0;

    for (i = 0; i < tamanho; i++) {

        if (strings[i][0] == 'a' || strings[i][0] == 'A') {

            cont++;

        }

    }

    return cont;

}

int main () {

    char *array[5] = {"Amora", "banana", "abacaxi", "laranja", "abacate"};
    int tamanhoArray = sizeof(array) / sizeof(array[0]);

    int resultado = contagemA(array, tamanhoArray);

    printf("STRINGS QUE COMECAM COM A LETRA A: %d\n\n\n", resultado);



    return 0;
}
