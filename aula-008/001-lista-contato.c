/*
    Construir um programa para manter uma LISTA de contatos, com uma
    estrutura denominada contato, onde cada contato deve ter as
    seguintes informações:

    * nome - char[80]
    * telefone - int
    * email - char[80]

    Criar um ponteiro da estrutura Contato para representar uma LISTA

    O programa deve ter as seguintes funções:

    * incluir um contato no fim
    * incluir um contato no meio
    * exibir todos os contatos
    * buscar um contato pelo telefone
    * remover um contato
*/



#include <stdio.h>
#include <stdlib.h>

typedef struct contato
{
    char nome[80];
    size_t telefone;
    char email[80];
    struct contato *proximo;
} Contato;

typedef struct
{
    Contato *inicio;
    int tam;
} Lista;

void criarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

int menu = 0;

void cadastrarFim(Lista *lista)
{
    system("cls");

    Contato *novo = (Contato*) malloc(sizeof(Contato));

    fflush(stdin);
    printf("\nNOME\t\t");
    gets(novo->nome);
    fflush(stdin);

    printf("\nTELEFONE\t");
    scanf("%d", &novo->telefone);
    fflush(stdin);

    printf("\nEMAIL\t\t");
    fgets(novo->email, 80, stdin);
    fflush(stdin);

    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        Contato *no = lista->inicio;

        while (no->proximo != NULL)
        {
            no = no->proximo;
        }

        no->proximo = novo;
    }

    lista->tam++;


    printf("\n[ CADASTRO REALIZADO COM SUCESSO ]");
    puts("\n");
    system("pause");
}

void cadastrarMeio(Lista *lista)
{
    system("cls");
    Contato *novo = malloc(sizeof(Contato));

    if (novo == NULL)
    {
        printf("\n[ ERRO AO ALOCAR MEMORIA ]");
        return;
    }

    fflush(stdin);
    printf("\nNOME\t\t");
    gets(novo->nome);
    fflush(stdin);

    printf("\nTELEFONE\t");
    scanf("%d", &novo->telefone);
    fflush(stdin);

    printf("\nEMAIL\t\t");
    fgets(novo->email, 80, stdin);
    fflush(stdin);

    novo->proximo = NULL;

    int meio = lista->tam / 2;  // Calcula a posi  o do meio da lista

    if (lista->inicio == NULL || meio == 0)
    {
        // Se a lista est  vazia ou o meio   o primeiro elemento, insere no in cio
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    else
    {
        Contato *atual = lista->inicio;
        for (int i = 1; i < meio; i++)
        {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    lista->tam++;
}


void exibir(Lista *lista)
{
    system("cls");
    Contato *contato = lista->inicio;

    printf("\nCONTATOS: 0%d", lista->tam);
    printf("\nNOME\t\tTELEFONE\t\tEMAIL\n");

    while (contato != NULL)
    {
        printf("\n%s\t\t%d\t\t%s", contato->nome, contato->telefone, contato->email);
        contato = contato->proximo;
    }

    puts("\n\n");
    system("pause");
}

void buscar(Lista *lista)
{
    system("cls");

    int telefoneBuscado;
    Contato *contato = lista->inicio;

    printf("\nDIGITE O TELEFONE A SER BUSCADO");
    printf("\n\n-> ");
    scanf("%d", &telefoneBuscado);
    fflush(stdin);

    while (contato != NULL)
    {
        if (contato->telefone == telefoneBuscado)
        {
            printf("\n[ TELEFONE ENCONTRADO ]\n");
            printf("\nNOME\t\t%s", contato->nome);
            printf("\nTELEFONE\t%d", contato->telefone);
            printf("\nEMAIL\t\t%s\n\n", contato->email);

            system("pause");
            return;
        }

        contato = contato->proximo;
    }

    printf("\n[ TELEFONE NAO ENCONTRADO ]\n\n");
    system("pause");
}

void remover(Lista *lista)
{
    system("cls");

    int telefoneRemover;
    printf("\nDIGITE O TELEFONE A SER REMOVIDO");
    printf("\n\n-> ");
    scanf("%d", &telefoneRemover);
    fflush(stdin);

    Contato *anterior = NULL;
    Contato *atual = lista->inicio;

    while (atual != NULL)
    {
        if (atual->telefone == telefoneRemover)
        {
            if (anterior == NULL)
            {
                // Remover o primeiro elemento da lista
                lista->inicio = atual->proximo;
            }
            else
            {
                // Remover um elemento no meio ou final da lista
                anterior->proximo = atual->proximo;
            }

            free(atual);
            lista->tam--;

            printf("\n[ CONTATO REMOVIDO COM SUCESSO ]\n\n");
            system("pause");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\n[ TELEFONE NAO ENCONTRADO PARA REMOCAO ]\n\n");
    system("pause");
}


int main()
{
    Lista lista;
    criarLista(&lista);

    do
    {
        system("cls");
        printf("\nCONTATO =================================================\n");

        printf("\n[ 1 ]  CADASTRAR NO FINAL");
        printf("\n[ 2 ]  CADASTRAR NO MEIO");
        printf("\n[ 3 ]  EXIBIR");
        printf("\n[ 4 ]  BUSCAR");
        printf("\n[ 5 ]  REMOVER\n");

        printf("\n[ 6 ]  SAIR");

        printf("\n\n-> ");

        scanf("%d", &menu);
        fflush(stdin);

        switch (menu)
        {

        case 1:
            cadastrarFim(&lista);
            break;

        case 2:
            cadastrarMeio(&lista);
            break;

        case 3:
            exibir(&lista);
            break;

        case 4:
            buscar(&lista);
            break;

        case 5:
            remover(&lista);
            break;

        case 6:
            return 0;
            break;

        default:
            break;
        }

    }
    while (menu != 6);

    return 0;
}
