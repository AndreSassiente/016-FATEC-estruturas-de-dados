/*
	Declare uma vari�vel inteira x com valor 5.
	Declare um ponteiro p que aponta para x.
	Imprima o valor de x atrav�s de p.
*/

#include <stdio.h>

int main() {

	int x = 5;
	int *px = &x;

	printf("VALOR DE X ATRAVES DE P: %d", *px);

	return 0;
}
