/*
	Declare uma variável inteira x com valor 5.
	Declare um ponteiro p que aponta para x.
	Imprima o valor de x através de p.
*/

#include <stdio.h>

int main() {

	int x = 5;
	int *px = &x;

	printf("VALOR DE X ATRAVES DE P: %d", *px);

	return 0;
}
