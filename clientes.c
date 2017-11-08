#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "administrativo.h"
#include "funcionarios.h"

int id_card = 0; //Conta o numero de intens do cardapio
int id_cli = 0; //Conta o numero de clientes cadastrados

void menu_clientes() {
    printf("(1) Cadastro.\n");
    printf("(2) Pedidos.\n");
    printf("(3) Conta.\n");
    printf("(4) Sair.\n");
}

void menu_pedido() {
    printf("(1) Visualizar Cardapio.\n");
    printf("(2) Inserir pedido.\n");
    printf("(3) Sair. \n");
}

void menu_pagamento() {
    printf("Escolha a Forma de pagamento.\n");
    printf("(1) Cartao de Credito.\n");
    printf("(2) Dinheiro.\n");
    printf("(3) Sair.\n");
}


Cadastro* inicia_cadastro() {
    Cadastro *cad = malloc(MAX_CADASTRO * sizeof(Cadastro));
    FILE* in = fopen("bd_cadastro.txt", "r");

    while (fscanf(in, "%d %s %d", &cad[id_cli].codigo, cad[id_cli].nome, &cad[id_cli].tel) != EOF)
       id_cli++;

    fclose(in);
    return cad;
}

Cardapio* inicia_cardapio() {
    Cardapio *card = malloc(MAX_CARDAPIO * sizeof(Cardapio));
    FILE* in = fopen("bd_cardapio.txt", "r");

    while (fscanf(in, "%d %s %f", &card[id_card].codigo, card[id_card].item, &card[id_card].preco) != EOF)
        id_card++;

    fclose(in);
    return card;
}


void cadastro_cliente(Cadastro *cad, char *nome, int tel) {

    FILE* out = fopen("bd_cadastro.txt", "a");


    cad[id_cli].codigo = id_cli;
    strcpy(cad[id_cli].nome, nome);
    cad[id_cli].tel = tel;
    fprintf(out, "%d %s %d\n", cad[id_cli].codigo, cad[id_cli].nome, cad[id_cli].tel);
    id_cli++;
    printf("ID_CLI: %d\n", id_cli);
    fclose(out);
}


void imprime_cardapio(Cardapio *card) {
    int i;
    for (i = 0; i < id_card; i++)
        printf("%d %s %.2f \n", card[i].codigo, card[i].item, card[i].preco);
}

void registra_pedido(Cardapio *card, Cadastro *cad, int tam, int id, char *pedido) {
    int i;
    for (i = 0; i < tam; i++) {
        if (strcmp(pedido, card[i].item) == 0) {
            cad[id].conta = cad[id].conta + card[i].preco;
            fat_diario = fat_diario + cad[id].conta;
        }
    }
}

float pag_cartao(Cadastro *cad,int id, int parcela) {
    float par;
    par = cad[id].conta / parcela;
    cad[id].conta = 0;
    return par;
}

void troco(Cadastro *cad, int id, float dinheiro) {
    float n[] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.10, 0.05};
    int i, cont;
    float troco;
    troco = dinheiro - cad[id].conta;
    printf("Entregue o troco ao cliente na seguinte configuracao.\n");
    printf("O troco eh de: R$ %.2f\n", troco);
    for (i = 0; i < 10; i++) {
        cont = 0;
        while (troco >= n[i]) {
            troco = troco - n[i];
            cont++;
        }
        if (cont > 0) {
            if (n[i] > 1)
                printf("%d Notas de %.2f\n", cont, n[i]);
            else
                printf("%d Moedas de %.2f\n", cont, n[i]);
        }
    }
    cad[id].conta = 0;
}
