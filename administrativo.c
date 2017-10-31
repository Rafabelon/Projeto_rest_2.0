#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "administrativo.h"
#include "clientes.h"

void menu_adm() {
    printf("(1) Cadastrar item do cardapio.\n");
    printf("(2) Altera funcionarios.\n");
    printf("(3) Faturamento do dia.\n");
    printf("(4) RESET SYSTEM.\n");
    printf("(5) Sair.\n");
}

void menu_reset() {
    printf("(1) Zerar Banco de dados de clientes.\n");
    printf("(2) Zerar Banco de dados de funcionarios.\n");
    printf("(3) Zerar Banco de dados do cardapio.\n");
    printf("(4) Redefinir senha.\n");
    printf("(5) Sair.\n");
}

void zera_bd_cliente() {
    FILE* out = fopen("bd_cadastro.txt", "w");
    fclose(out);
}

void zera_bd_funcionario() {
    FILE* out = fopen("bd_funcionario.txt", "w");
    fclose(out);
}

void zera_bd_cardapio() {
    FILE* out = fopen("bd_cardapio.txt", "w");
    id_card = 0;
    fclose(out);
}


void cadastra_cardapio(Cardapio *card, char *item, float valor) {
    FILE* out = fopen("bd_cardapio.txt", "a");

    card[id_card].codigo = id_card;
    strcpy(card[id_card].item, item);
    card[id_card].preco = valor;

    fprintf(out, "%d %s %.2f\n", card[id_card].codigo, card[id_card].item, card[id_card].preco);
    id_card++;

    fclose(out);
  //  return card;
}



/*void cria_guarda_pos() {
    int i;
    i = 1;
    FILE* out = fopen("guarda_posicao_card.txt", "w");
    fprintf(out, "%d", i);
    fclose(out);
}*/


/*int guarda_posicao_card() {
    int posicao, num;
    posicao = 0;
    FILE* out = fopen("guarda_posicao_card.txt", "a");
    fscanf(out, "%d", &num);
    posicao = num;
    fclose(out);
    return posicao;
}*/
