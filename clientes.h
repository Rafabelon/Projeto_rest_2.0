#ifndef CLIENTES_H
#define CLIENTES_H


/*Opcao clientes no menu_principal */
#define CLIENTES 1
//#define ADMINISTRATIVO 3
#define ENCERRAR 4

/*Escolhas do menu_clientes*/
#define CADASTRO 1
#define PEDIDO 2
#define CONTA 3
#define SAIR 4

/*escolhas do menu Pedidos */
#define CARDAPIO 1
#define INSERE_PED 2
#define SAI_PED 3

/* Parametros de Pagamento */
#define PARCELA_MAX 12

/*Escolhas do menu pagamneto */
#define CARTAO 1
#define DINHEIRO 2
#define SAI_PAG 3

/*Parametros para Structs*/
#define MAX_CADASTRO 100
#define MAX_CARDAPIO 100
#define CHAR_NOME_MAX 51
#define CHAR_ITEM_MAX 71

extern int id_card; // extern determina que é uma variável global do projeto.
extern int id_cli;

struct cadastro {
    int codigo;
    char nome[CHAR_NOME_MAX];
    int tel;
    float conta;
};


struct cardapio {
    int codigo;
    char item[CHAR_ITEM_MAX];
    float preco;

};

typedef struct cadastro Cadastro;
typedef struct cardapio Cardapio;


/*A funcao menu_clientes imprime as opcoes do modulo clientes*/
void menu_clientes();

/* tem o objetivo de imprimir as opcoes do modulo pedidos */
void menu_pedido();

/* Informa as Modalidades de Pagamento */
void menu_pagamento();

/* A funcao inicia_cadastro tem o objetivo de zerar os valores
// e caracteres da struct Cadastro */
Cadastro* inicia_cadastro();

/* A funcao inicia_cadastro tem o objetivo de zerar os valores
// e caracteres da struct Cardapio */
Cardapio* inicia_cardapio();

/* A funcao cadastro_cliente tem o objetivo de salvar as informacoes
// da struct Cadastro em um arquivo de texto ou banco de dados */
void cadastro_cliente (Cadastro *cad, char *nome, int tel);

/* A funcao imprime_cardapio le as informacoes contidas no arquivo
// bd_cardapio e as imprime na tela */
void imprime_cardapio (Cardapio *card);

/*A funcao registra_pedido recebera o codigo do cliente desejado e a string com
// o nome do item para que o seu preco seja registrado na conta do
// determinado cliente */
void registra_pedido(Cardapio *card, Cadastro *cad, int tam, int id, char *pedido);


float pag_cartao(Cadastro *cad,int id, int parcela);


void troco(Cadastro *cad, int id, float dinheiro);

#endif // CLIENTES_H
