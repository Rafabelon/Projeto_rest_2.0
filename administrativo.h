#ifndef ADMINISTRATIVO_C
#define ADMINISTRATIVO_H
#include "clientes.h"
/*Opcao Funcionarios no menu_principal */
#define ADMINISTRATIVO 3

/* Opcoes Menu_Administrativo */
#define CAD_CARDAPIO 1
#define ALTERA_FUNC 2
#define FATURAMENTO 3
#define RESET 4
#define SAIR_ADM 5

/*opcao reset */
#define TENTAVITA_MAX 3
#define ZERA_BD_CLIENTE 1
#define ZERA_BD_FUNCIONARIO 2
#define ZERA_BD_CARDAPIO 3
#define NOVA_SENHA 4
#define SAI_RESET 5

/* imprime o menu com as opcoes do modulo
// administrativo */
void menu_adm();

/* imprime as opcoes do menu reset */
void menu_reset();

/*Esta funcao limpa/cria o arquivo.txt do cadastro dos clientes*/
void zera_bd_cliente();

/*Esta funcao limpa/cria o arquivo.txt da lista de funcionarios*/
void zera_bd_funcionario();

/*Esta funcao limpa/cria o arquivo.txt que armazena as informacoes
// referentes ao cardapio*/
void zera_bd_cardapio();


void cadastra_cardapio(Cardapio *card, char *item, float valor);



//int guarda_posicao_card();

//void cria_guarda_pos();
#endif // ADMINISTRATIVO_C
