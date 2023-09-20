/*
	PONTEIROS READ ONLY (somente leitura)

	Ao passarmos referência (ponteiro) para uma função, caso a mesma seja
	somente para leitura (read only), podemos evitar uma alteração acidental
	de seu valor dentro da função apenas adicionando a palavra reservada const
*/

#include <stdio.h>

void troca(const int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int main()
{
	int a = 10;
	int b = 20;

	printf("\nA -> %d", a);
	printf("\nB -> %d", b);

	troca(&a, &b);

	printf("\n\nA -> %d", a);
	printf("\nB -> %d", b);

	return 0;
}
