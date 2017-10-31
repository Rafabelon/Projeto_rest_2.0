#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

int id_card = 0;

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


Cadastro* inicia_cadastro(int tam) {
    int i;
    Cadastro *cad = malloc(tam * sizeof(Cadastro));

    for (i = 0; i < tam; i++) {
        cad[i].codigo = i;
        strcpy(cad[i].nome, "");
        cad[i].tel = 0;
        cad[i].conta = 0;
    }
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

/*Cardapio* atualiza_card(Cardapio *card, int tam) {
    int i;
    FILE* in = fopen("bd_cardapio.txt", "r");
    for (i = 0; i < tam; i++) {
        fscanf(in, "%f", &card[i].preco);
        if (card[i].preco != 0)
    }
}*/

/* Aqui ta foda no arquivo quando salva so salva em uma unica fila */
void cadastro_cliente(Cadastro *cad, int tam, int id, char *nome, int tel) {

    FILE* out = fopen("bd_cadastro.txt", "a");


    cad[id].codigo = id;
    strcpy(cad[id].nome, nome);
    cad[id].tel = tel;
    printf("B!!\n");
    fprintf(out, "%d %s %d\n", cad[id].codigo, cad[id].nome, cad[id].tel);
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
        }

    }
}
