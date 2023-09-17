#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;            // numero do voo
    char data[20];     // data do voo
    char horario[20];  // horario do voo
    char saida[20];    // aeroporto de saida
    char chegada[20];  // aeroporto de chegada
    char rota[20];     // rota
    char tempo[20];    // tempo estimado de voo
    int passageiros;   // passageiros a bordo
} VOO;


int menu;              // escolha do menu principal
int iv = 0;            // indice para cadastro de voos cadastrados
int i = 0;             // indice para uso geral
int ic = 0;            // indice para consulta de voos cadastrados
int ix = 0;            // indice para exclusao de voos cadastrados
int idvc = 1;          // id fixo para cada voo cadastrado

void cadastrarVoo(VOO *voo)
{
    fflush(stdin);
    system("cls");
    printf("\nCADASTRAR VOO ===================================================\n");

    printf("\nID\t\t\t#%d\n", idvc);
    voo[iv].id = idvc;
    fflush(stdin);

    printf("\nDATA\t\t\t");
    scanf(" %[^\n]", voo[iv].data);
    fflush(stdin);

    printf("\nHORARIO\t\t\t");
    scanf(" %[^\n]", voo[iv].horario);
    fflush(stdin);

    printf("\nAEROPORTO SAIDA\t\t");
    scanf(" %[^\n]", voo[iv].saida);
    fflush(stdin);

    printf("\nAEROPORTO CHEGADA\t");
    scanf(" %[^\n]", voo[iv].chegada);
    fflush(stdin);

    printf("\nROTA\t\t\t");
    scanf(" %[^\n]", voo[iv].rota);
    fflush(stdin);

    printf("\nTEMPO\t\t\t");
    scanf(" %[^\n]", voo[iv].tempo);
    fflush(stdin);

    printf("\nPASSAGEIROS\t\t");
    scanf("%d", &voo[iv].passageiros);
    fflush(stdin);

    iv++;
    idvc++;

    printf("\n=================================================================\n\n");
    printf("\n[  VOO CADASTRADO COM SUCESSO  ] \n\n\n");
    system("pause");
}

void consultarVoo(VOO *voo)
{
    system("cls");
    printf("\nSELECIONE O VOO PARA CONSULTA ===================================\n");

    for (i = 0; i < iv; i++)
    {
        printf("\n[ %d ]", voo[i].id);
    }

    printf("\n\n-> ");
    scanf("%d", &ic);
    fflush(stdin);
    ic--;
    system("cls");
    printf("\nCONSULTA =======================================================\n\n");

    printf("\nVOO ID\t\t%d", voo[ic].id);
    printf("\nDATA\t\t%s", voo[ic].horario);
    printf("\nHORARIO\t\t%s", voo[ic].horario);
    printf("\nSAIDA\t\t%s", voo[ic].saida);
    printf("\nCHEGADA\t\t%s", voo[ic].chegada);
    printf("\nROTA\t\t%s", voo[ic].rota);
    printf("\nTEMPO\t\t%s", voo[ic].tempo);
    printf("\nPASSAGEIROS\t%d", voo[ic].passageiros);

    printf("\n\n\n");
    system("pause");
}

void removerVoo(VOO *voo)
{
    system("cls");
    printf("\nSELECIONE O VOO PARA EXCLUSAO ===================================\n");

    for (i = 0; i < iv; i++)
    {
        printf("\n[ %d ]", voo[i].id);
    }

    printf("\n\n-> ");
    scanf("%d", &ix);
    //ix--;

    //voo[ix] = voo[ix+1];
    --iv;

    voo[ix].id = voo[ix+1].id;
    strcpy(voo[ix].data, voo[ix+1].data);
    strcpy(voo[ix].horario, voo[ix+1].horario);
    strcpy(voo[ix].saida, voo[ix+1].saida);
    strcpy(voo[ix].chegada, voo[ix+1].chegada);
    strcpy(voo[ix].rota, voo[ix+1].rota);
    strcpy(voo[ix].tempo, voo[ix+1].tempo);
    voo[ix].passageiros = voo[ix+1].passageiros;

    printf("\n=================================================================\n\n");
    printf("\n[  VOO REMOVIDO COM SUCESSO  ] \n\n\n");
    system("pause");

}

int main()
{
    VOO *voo = (VOO *)malloc(sizeof(VOO));

    do
    {
        system("cls");
        printf("\nVOEBEM AIRLINES =================================================\n");

        printf("\n[ 1 ]  CADASTRAR");
        printf("\n[ 2 ]  CONSULTAR");
        printf("\n[ 3 ]  REMOVER\n\n");

        printf("\n[ 5 ]  SAIR");

        printf("\n\n-> ");

        scanf("%d", &menu);
        fflush(stdin);

        switch (menu)
        {

        case 1:
            cadastrarVoo(voo);
            voo = (VOO *)realloc(voo, (iv + 1) * sizeof(VOO));
            break;

        case 2:
            if (iv == 0)
            {
                printf("\n[ SEM REGISTROS NO SISTEMA ] \n\n\n");
                system("pause");
            }
            else
            {
                consultarVoo(voo);
            }
            break;

        case 3:
            if (iv == 0)
            {
                printf("\n[ SEM REGISTROS NO SISTEMA ] \n\n\n");
                system("pause");
            }
            else
            {
                removerVoo(voo);
                if (iv == 1){ voo = (VOO *)realloc(voo, iv * sizeof(VOO)); }
                if (iv > 1){ voo = (VOO *)realloc(voo, (iv - 1) * sizeof(VOO)); }
            }
            break;

        case 5:
            free(voo);
            return 0;
            break;

        default:
            break;
        }

    }
    while (menu != 5);

    return 0;
}
