/*
    Fazer um programa em Linguagem C que crie uma estrutura de dados
    voo (struct voo) para a empresa VOEBEM. A estrutura voo deve ser
    implementada de forma dinâmica e deve conter os seguintes dados:

    * número do voo
    * data do voo
    * horário do voo
    * aeroporto de saída
    * aeroporto de chegada
    * rota
    * tempo estimado de voo
    * passageiros a bordo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vID;            // numero do voo
    char vData[10];     // data do voo
    char vHorario[10];  // horario do voo
    char vSaida[30];    // aeroporto de saida
    char vChegada[30];  // aeroporto de chegada
    char vRota[30];     // rota
    char vTempo[20];    // tempo estimado de voo
    int vPassageiros;   // passageiros a bordo
} VOO;

int qtd_voo;


int main() {

    VOO *voebem;
    int n;

    printf("Quantos voos serao cadastrados?");
    scanf("%d", &n);

    voebem = (VOO*) malloc (n*sizeof(VOO));


    return 0;
}


