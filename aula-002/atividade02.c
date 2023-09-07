/*
	Escreva uma função que recebe um ponteiro para um inteiro
	como parâmetro e dobra o valor do inteiro apontado pelo ponteiro.
*/

#include <stdio.h>

void dobrarValor(int *p) { *p = *p * 2;}

int main() {

	int numero = 256;
	int *ponteiro = &numero;

	printf("\nVALOR: %d", numero);

	dobrarValor(ponteiro);

	printf("\nVALOR DOBRADO: %d", *ponteiro);

	return 0;
}
