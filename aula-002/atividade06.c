/*
	Implemente uma função que recebe um ponteiro para um array de inteiros
	e seu tamanho. A função deve retornar o maior elemento no array.
*/

#include <stdio.h>

int maiorNumero(int *numeros[], int tamanho) {

	int maior = 0;
	int i = 0;

	for (i = 0; i < tamanho; i++) {

		if (numeros[i] > maior) { maior = numeros[i]; }

	}

	return maior;

}

int main() {

	int *numeros[5] = {2, 3, 5, 67, 10};
	int tamanhoArray = sizeof(numeros) / sizeof(numeros[0]);
	int resultado = maiorNumero(numeros, tamanhoArray);

	printf("MAIOR NUMERO DENTRO DO ARRAY: %d", resultado);

	return 0;
}
