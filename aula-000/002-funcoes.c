/*
	Trabalhando com fun��es:

	* Passagem por valor.
	* Passagem por refer�ncia.
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

// PASSAGEM POR REFER�NCIA
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
