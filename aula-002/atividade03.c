/*
	Crie um array de inteiros com 15 elementos.
	Escreva uma função que recebe um ponteiro para o primeiro
	elemento do array e seu tamanho como parâmetro e retorne o valor
	médio dos elementos.
*/

#include <stdio.h>

float calcularMedia(int *ponteiro, int tamanho) {

	int somaTotal = 0;
	int i = 0;

	for (i = 0; i < tamanho; i++) { somaTotal += ponteiro[i]; }

	return (somaTotal / tamanho);

}

int main() {

	int array[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int tamanhoArray = sizeof(array) / sizeof(array[0]);
	int *pArray = &array;
	float media = calcularMedia(pArray, tamanhoArray);

	printf("\nMEDIA: %.2f", media);

	return 0;
}
