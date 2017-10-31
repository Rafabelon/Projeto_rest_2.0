#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clientes.h"
#include "funcionarios.h"
#include "administrativo.h"

/* imprime o cabecalho do programa com a data e hora */
void cabecalho();

/*A funcao menu_principal imprime o primeiro menu do sistema */
void menu_principal();

int main() {
    int opt, opt_cli, opt_ped, /*opt_func,*/ opt_adm/*, i*/;
    int id_cli, cod_cli, cod_cli_conta;
    int senha, cont_senha, tenta_senha, opt_reset;
    int sai_cad, sai_card, cad_tel;
    char cad_nome[CHAR_NOME_MAX];
    char item_card[CHAR_NOME_MAX];
    char pedido[CHAR_ITEM_MAX];
    float preco;

    id_cli = 1;
    cod_cli = 0;
    sai_cad = 1;
    sai_card = 1;

    senha = 4566;

    Cadastro *cad = inicia_cadastro(MAX_CADASTRO);

    Cardapio *card = inicia_cardapio();
    /*for (i = 0; i < MAX_CARDAPIO; i++) {
        printf("%d %s %.f\n", card[i].codigo, card[i].item, card[i].preco);
    }*/

    while(1) {
        cabecalho();
        menu_principal();

        scanf("%d", &opt);
        while (opt > ENCERRAR) {
            printf("Opcao Invalida.\n");
            scanf("%d", &opt);
        }
        if (opt == CLIENTES) {
            opt_cli = 0;
            while (opt_cli != SAIR) {
                menu_clientes();
                scanf("%d", &opt_cli);
                if (opt_cli == CADASTRO) {
                    while (sai_cad != 2) {
                        printf("Digite o nome do cliente:\n");
                        scanf(" %[^\n]s", cad_nome);
                        printf("Digite o Telefone do cliente:\n");
                        scanf("%d", &cad_tel);

                        cadastro_cliente (cad, MAX_CADASTRO, id_cli, cad_nome, cad_tel);
                        id_cli++;
                        printf("A\n");
                        printf("Deseja Cadastrar mais um Cliente?\n");
                        printf("(1) Sim.\n");
                        printf("(2) Nao. \n");
                        printf("B\n");
                        scanf("%d", &sai_cad);
                        printf("C \n");
                    }

                } else if (opt_cli == PEDIDO) {
                        opt_ped = 0;
                        while (opt_ped != SAI_PED) {
                            menu_pedido();
                            scanf("%d", &opt_ped);
                            if (opt_ped == CARDAPIO) {
                                //So funciona se o arquivo bd_cardapio ja eseje criado
                                imprime_cardapio(card);
                            } else if (opt_ped == INSERE_PED) {
                                printf("Digite o Codigo do Cliente.\n");
                                scanf("%d", &cod_cli);
                                printf("Insira o item desejado.\n");
                                scanf(" %[^\n]s", pedido);

                                registra_pedido(card, cad, MAX_CARDAPIO, cod_cli, pedido);
                                printf("%d %.2f", cad[cod_cli].codigo, card[cod_cli].preco);
                            }
                         //   imprime_cardapio (card, MAX_CARDAPIO);
                        // 1. mostrar_cardapio();
                        // 2. Seleciona pedido
                        // 3. Atualiza o valor da conta
                        // 4. Verifica se deseja adicionar mais alguma coisa
                        }

                } else if (opt_cli == CONTA) {
                    printf("Digite o Codigo do Cliente. \n");

                    scanf("%d", &cod_cli_conta);
                    printf("%f\n", cad[cod_cli_conta].conta);
                    // 1. mostrar_conta();
                    // 2. Seleciona m�todo de pagamento
                    // 3. Efetua o pagamento
                    // 4. Deixa o valor da conta valendo -1, sinalizando que o cliente
                    //    saiu do restaurante. Logo, ele pode ser reescrito. (?)
                }
            }
        } else if (opt == FUNCIONARIOS) {
          // 2. Tabela de turnos
          // 3. Bater ponto
        } else if (opt == ADMINISTRATIVO) {
            opt_adm = 0;
            while (opt_adm != SAIR_ADM) {

                menu_adm();
                scanf("%d", &opt_adm);
                if (opt_adm == CAD_CARDAPIO) {
                    sai_card = 0;
                    while (sai_card != 2) {

                        printf("Digite o nome do item.\n");
                        scanf(" %[^\n]s", item_card);
                        printf("Digite o preco de venda.\n");
                        scanf("%f", &preco);
                        //cria_guarda_pos();
                       // printf("Posicao %d", guarda_posicao_card());

                        cadastra_cardapio(card, item_card, preco);

                        printf("Deseja cadastrar outro item?\n");
                        printf("(1) Sim.\n");
                        printf("(2) Nao.\n");
                        scanf("%d", &sai_card);
                    }

                } else if (opt_adm == ALTERA_FUNC) {
                    printf("DANDO\n");
                } else if (opt_adm == FATURAMENTO) {
                    printf("CERTO!!!\n");
                } else if (opt_adm == RESET) {
                     for (cont_senha = 1; cont_senha <= TENTAVITA_MAX; cont_senha++) {
                        printf("Digite a Senha do administrador:\n");
                        scanf("%d", &tenta_senha);
                        if (tenta_senha == senha) {
                            cont_senha = TENTAVITA_MAX;
                            opt_reset = 0;
                            while (opt_reset != SAI_RESET) {
                                menu_reset();
                                scanf("%d", &opt_reset);
                                if (opt_reset == ZERA_BD_CLIENTE) {
                                    printf("zera cliente\n");
                                    zera_bd_cliente();
                                } else if (opt_reset == ZERA_BD_FUNCIONARIO) {
                                    printf("zera func\n");
                                    zera_bd_funcionario();
                                } else if (opt_reset == ZERA_BD_CARDAPIO) {
                                    printf("zera carda\n");
                                    zera_bd_cardapio();
                                } else if (opt_reset == NOVA_SENHA) {
                                    printf("redefinir senha\n");
                                }
                            }

                        } else {
                            printf("Senha incorreta!\n");
                            printf("Tentativa %d de 3.", cont_senha);
                            printf("Tente novamente.\n");
                        }

                     }
            }
          // 1. Altera funcion�rios
          // 2. Cadastra item do card�pio
          // 3. Faturamento do dia
            }

        } else if (opt == ENCERRAR) {
            free(cad);
            free(card);
            return 0;
        }
    }
    return 1;
}

void cabecalho() {
    printf("Sistema Operacional 2.0\n");
    printf("Data :%s Hora:%s\n",__DATE__,__TIME__);
    printf("By: Tycoon Technology S/A.\n");
    printf("\n");
}

void menu_principal() {
    printf("Selecione uma Opcao.\n");
    printf("(1) Clientes.\n");
    printf("(2) Funcionarios.\n");
    printf("(3) Administrativo\n");
    printf("(4) Encerrar.\n");
}
