/*
	Cada atividade deve atender os requisitos

	* Declarar o tipo abstrato de dados
	* Criar uma variável do tipo abstrato de dados
	* Ler os dados do teclado e preencher os campos da variável
	* Exibir na tela os campos preenchidos da variável do tipo abstrato de dados

	ATIVIDADE 01

	Construir um programa em linguagem C que implemente uma estrutura
	avião (struct aviao), permitindo o cadastro e a exibição, com os seguintes campos:

	* modelo
	* fabricante
	* passageiros
	* comprimento
	* altura
	* velocidade
	* altitude
	* motor

*/

#include <stdio.h>
#include <stdlib.h>


// VARIAVEIS
struct aviaoCadastro
{
    char modelo[20];
    char fabricante[20];
    int passageiros;
    float comprimento;
    float altura;
    float velocidade;
    float altitude;
    int motor;
};

struct aviaoCadastro aviao[99];
int menu_escolha;
int i = 0;


// FUNÇÕES
int cadastro() {

	system("cls");
	printf("\nCADASTRO ==============================================================================================================\n");

	printf("\nMODELO\t\t");
	gets(aviao[i].modelo);

	printf("\nFABRICANTE\t");
	gets(aviao[i].fabricante);

	printf("\nPASSAGEIROS\t");
	scanf("%d", &aviao[i].passageiros);

	printf("\nCOMPRIMENTO\t");
	scanf("%f", &aviao[i].comprimento);

	printf("\nALTURA\t\t");
	scanf("%f", &aviao[i].altura);

	printf("\nVELOCIDADE\t");
	scanf("%f", &aviao[i].velocidade);

	printf("\nALTITUDE\t");
	scanf("%f", &aviao[i].altitude);

	printf("\nMOTOR\t\t");
	scanf("%d", &aviao[i].motor);

	i++;

	printf("\n\n[ CADASTRO CONCLUIDO ]\n\n");
	system("pause");

}

int exibir()
{
	fflush(stdin);
	system("cls");
	printf("\nAVIAO ==============================================================================================================\n");


	if (i == 0)
	{
		printf("\n\n[ SEM CADASTROS NO SISTEMA ]\n\n");
		system("pause");

		main();
	}

	printf("\nMODELO\tFABRICANTE\tPASSAGEIROS\tCOMPRIMENTO\tALTURA\t\tVELOCIDADE\tALTITUDE\tMOTOR");

	for (int j = 0; j < i; j++)
	{
		printf("\n%s\t%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d", aviao[j].modelo, aviao[j].fabricante, aviao[j].passageiros, aviao[j].comprimento, aviao[j].altura, aviao[j].velocidade, aviao[j].altitude, aviao[j].motor);
	}

	printf("\n\n");
	system("pause");
}

int main()
{
    do
    {
        system("cls");
        printf("\n[ 1 ]  CADASTRAR");
        printf("\n[ 2 ]  EXIBIR\n");

        printf("\n[ 9 ]  ENCERRAR");
        printf("\n\n-> ");

        scanf("%d", &menu_escolha);
        fflush(stdin);


        switch(menu_escolha)
        {
        case 1:
            cadastro();
            break;

        case 2:
            exibir();
            break;

        case 9:
            return 0;
            break;

        default:
        	fflush(stdin);
            main();
            break;

        }
    }
    while (menu_escolha != 5);

    return 0;
}


