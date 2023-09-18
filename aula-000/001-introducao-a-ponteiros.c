// Introdução a ponteiros

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int *p1 = NULL;
	int *p2;

	printf("\nA\t%d", a);
	printf("\n&A\t%p\n", &a);

	printf("\nP1\t%p", p1);
	printf("\n&P1\t%p\n", &p1);

	printf("\nP2\t%p", p2);
	printf("\n&P2\t%p\n", &p2);

	p1 = &a;
	p2 = p1;
	*p2 = 4;

	printf("\n=========================\n");

	printf("\nA\t%d", a);
	printf("\n&A\t%p\n", &a);

	printf("\nP1\t%p", p1);
	printf("\n&P1\t%p", &p1);
	printf("\n*P1\t%d\n", *p1);

	printf("\nP2\t%p", p2);
	printf("\n&P2\t%p", &p2);
	printf("\n*P2\t%d\n", *p2);

	return 0;
}
