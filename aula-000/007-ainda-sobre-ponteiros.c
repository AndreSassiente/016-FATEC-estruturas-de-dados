#include <stdio.h>

int main()
{
	int v[5] = {3, 6, 7, 8, 4};
	int *p;

	p = v;

	printf("\nV\t%p", v);
	printf("\n&V\t%p", &v);
	printf("\n&V[0]\t%p", &v[0]);
	printf("\nP\t%p", p);

	puts("\n\n");
	return 0;
}
