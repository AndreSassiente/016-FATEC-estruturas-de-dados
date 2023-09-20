/*
	Trabalhando com funções:

	* Passagem por valor.
	* Passagem por referência.
*/

// PASSAGEM POR VALOR
//#include <stdio.h>
//
//int soma(int x, int y)
//{
//	int z = x + y;
//
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c;
//
//	c = soma(a, b);
//
//	printf("VALOR DE C -> %d", c);
//	return 0;
//}

// PASSAGEM POR REFERÊNCIA
#include <stdio.h>

void soma(int x, int y, int *z)
{
	*z = x + y;
}

int main()
{
	int a = 10;
	int b = 20;
	int c;

	soma(a, b, &c);

	printf("VALOR DE C -> %d", c);
}
