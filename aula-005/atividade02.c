/*
	Cada atividade deve atender os requisitos

	* Declarar o tipo abstrato de dados
	* Criar uma variável do tipo abstrato de dados
	* Ler os dados do teclado e preencher os campos da variável
	* Exibir na tela os campos preenchidos da variável do tipo abstrato de dados

	ATIVIDADE 02

	Construir um programa em Linguagem C que implemente uma estrutura pedido (struct pedido),
	permitindo o cadastro e exibição com os seguintes campos:

	* numero do pedido
	* nome-cliente
	* telefone
	* endereco (deve ser um tipo abstrato para endereco)
		logradouro
		numero
		bairro
		coomplemento
	* itens[10] (deve ser um tipo abstrato para item)
		sabor
		tamanho
		quantidade
	* pagamento (deve ser um tipo abstrato para pagamento)
		forma de pagamento
		valor pedido
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// variaveis
typedef struct {
	char logradouro[50];
	char numero[10];
	char bairro[20];
	char complemento[20];
} ENDERECO;

typedef struct {
	char sabor[20];
	char tamanho[2];
	int quantidade;
} ITEM;

typedef struct {
	int formaPagamento;
	float totalPedido;
} PAGAMENTO;

typedef struct {
	int pedidoID;
	int qtd_itens;
	char clienteNome[30];
	char telefone[15];
	ENDERECO clienteEndereco;
	ITEM itens[10];
	PAGAMENTO pagamento;
} PEDIDO;

PEDIDO pedidos[99];

int menu_escolha = 0;
int ic = 1;
int id_cadastro = 1;
int i = 1;
int ii = 1;
int pedidoSelecionado = 0;


// funções
int cadastrar() {

	system("cls");
	printf("\nCADASTRAR ==============================================================================================================\n");

	printf("\nID\t\t\t#000%d\n", id_cadastro);
	pedidos[ic].pedidoID = id_cadastro;

	printf("\nNOME DO CLIENTE\t\t");
	fgets(pedidos[ic].clienteNome, 30, stdin);
	fflush(stdin);

	printf("\nTELEFONE\t\t");
	fgets(pedidos[ic].telefone, 12, stdin);
	fflush(stdin);

	printf("\n\nENDERECO");
	printf("\n\tLOGADOURO\t");
	fgets(pedidos[ic].clienteEndereco.logradouro, 50, stdin);

	printf("\n\tNUMERO\t\t");
	fgets(pedidos[ic].clienteEndereco.numero, 5, stdin);

	printf("\n\tBAIRRO\t\t");
	fgets(pedidos[ic].clienteEndereco.bairro, 20, stdin);

	printf("\n\tCOMPLEMENTO\t");
	fgets(pedidos[ic].clienteEndereco.complemento, 20, stdin);

	printf("\nQUANTOS ITENS?\t\t");
	scanf("%d", &pedidos[ic].qtd_itens);
	fflush(stdin);

	for (ii = 0; ii < pedidos[ic].qtd_itens; ii++) {

		printf("\nITEM\t\t#%d", ii+1);
		printf("\n\nSABOR\t\t");
		gets(pedidos[ic].itens[ii].sabor);
		fflush(stdin);

		printf("\nTAMANHO\t\t");
		gets(pedidos[ic].itens[ii].tamanho);
		fflush(stdin);

		printf("\nQUANTIDADE\t");
		scanf("%d", &pedidos[ic].itens[ii].quantidade);
		fflush(stdin);

	}

	printf("\nPAGAMENTO\n");
	printf("\n[ 1 ]  CREDITO");
	printf("\n[ 2 ]  DEBITO");
	printf("\n[ 3 ]  PIX");

	printf("\n\n-> ");
	scanf("%d", &pedidos[ic].pagamento.formaPagamento);
	fflush(stdin);



	printf("\nVALOR TOTAL\t\tR$ ");
	scanf("%f", &pedidos[ic].pagamento.totalPedido);
	fflush(stdin);

	printf("\n[  ITEM ADICIONADO COM SUCESSO  ] \n\n");
	ic++;
	id_cadastro++;

	system("pause");
}

int exibir() {

	printf("\nSELECIONE O PEDIDO");

	for (i = 1; i < id_cadastro; i++)
	{
		printf("\n[ 000%d ]\t%s", pedidos[i].pedidoID, pedidos[i].clienteNome);
	}

	printf("\n\n-> ");
	scanf("%d", &pedidoSelecionado);
	fflush(stdin);

	system("cls");

	printf("\nID PEDIDO\t\t\t000%d", pedidos[pedidoSelecionado].pedidoID);
	printf("\n============================================================\n");
	printf("\nNOME CLIENTE\t\t\t%s", pedidos[pedidoSelecionado].clienteNome);
	printf("\nTELEFONE\t\t\t%s\n", pedidos[pedidoSelecionado].telefone);

	printf("\nENDERECO ===================================================\n");
	printf("\nLOGADOURO\t\t\t%s", pedidos[pedidoSelecionado].clienteEndereco.logradouro);
	printf("\nNUMERO\t\t\t\t%s", pedidos[pedidoSelecionado].clienteEndereco.numero);
	printf("\nBAIRRO\t\t\t\t%s", pedidos[pedidoSelecionado].clienteEndereco.bairro);
	printf("\nCOMPLEMENTO\t\t\t%s", pedidos[pedidoSelecionado].clienteEndereco.complemento);

	printf("\nPEDIDO =====================================================\n");
	printf("\nITEM\t\tSABOR\t\tTAMANHO\t\tQUANTIDADE");

	for (ii = 0; ii < pedidos[pedidoSelecionado].qtd_itens; ii++)
	{
		printf("\n#%d\t\t%s \t%s\t\t%d", ii+1, pedidos[pedidoSelecionado].itens[ii].sabor, pedidos[pedidoSelecionado].itens[ii].tamanho, pedidos[pedidoSelecionado].itens[ii].quantidade);
	}

	printf("\n\n============================================================\n");
	if (pedidos[pedidoSelecionado].pagamento.formaPagamento == 1) { printf("\nPAGAMENTO\t\t\tCREDITO"); }
	if (pedidos[pedidoSelecionado].pagamento.formaPagamento == 2) { printf("\nPAGAMENTO\t\t\tDEBITO"); }
	if (pedidos[pedidoSelecionado].pagamento.formaPagamento == 3) { printf("\nPAGAMENTO\t\t\tPIX"); }

	printf("\nVALOR TOTAL\t\t\tR$ %.2f\n\n\n", pedidos[pedidoSelecionado].pagamento.totalPedido);

	system("pause");


}

int main() {

	do {
		system("cls");
		printf("\nPEDIDOS =================================================\n");

		printf("\n[ 1 ]  CADASTRAR");
		printf("\n[ 2 ]  EXIBIR");

		printf("\n[ 5 ]  ENCERRAR");

		printf("\n\n-> ");

		scanf("%d", &menu_escolha);
		fflush(stdin);

		switch(menu_escolha) {

			case 1:
				cadastrar();
			break;

			case 2:
				if (ic <= 1) {
					printf("\n[ SEM PEDIDOS NO SISTEMA ] \n\n\n");
					system("pause");
					main();
				} else {
					system("cls");
					printf("\nPEDIDOS ================================================================================================================\n\n");
					exibir();
				}

				printf("\n\n");
				system("pause");
			break;

			case 5:
				return 0;
			break;

			default:
				main();
			break;
		}

	} while (menu_escolha != 5);

	return 0;
}
