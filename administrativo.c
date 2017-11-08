#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "administrativo.h"
#include "clientes.h"
#include "funcionarios.h"

float fat_diario = 0; // Armazena todos os valores dos pedidos

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
    id_cli = 0;
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

int inicia_senha() {
    int senha;
    FILE* in = fopen("senha.txt", "r");

    fscanf(in, "%d", &senha);
    fclose(in);
    return senha;
}

void cadastra_cardapio(Cardapio *card, char *item, float valor) {
    FILE* out = fopen("bd_cardapio.txt", "a");

    card[id_card].codigo = id_card;
    strcpy(card[id_card].item, item);
    card[id_card].preco = valor;

    fprintf(out, "%d %s %.2f\n", card[id_card].codigo, card[id_card].item, card[id_card].preco);
    id_card++;

    fclose(out);
}


int troca_senha(int nova_senha) {
    FILE* in = fopen("senha.txt", "w");

    fprintf(in, "%d", nova_senha);

    fclose(in);
    return nova_senha;
}




