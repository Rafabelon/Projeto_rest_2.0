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
    int opt, opt_cli, opt_ped, opt_pag, opt_func, opt_adm;
    int cod_cli, cod_cli_conta;
    int senha, cont_senha, tenta_senha, nova_senha, opt_reset;
    int sai_cad, sai_card, cad_tel, sai_cad_func;
    int parcela;
    int turno, imp_turno, id_ponto;
    char cad_nome[CHAR_NOME_MAX], cad_func[CHAR_NOME_MAX];
    char item_card[CHAR_NOME_MAX];
    char pedido[CHAR_ITEM_MAX];
    float preco, troco_cli;


    Cadastro *cad = inicia_cadastro();

    Cardapio *card = inicia_cardapio();

    Funcionarios *func = inicia_funcionario();

    senha = inicia_senha();
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
                    sai_cad = 0;
                    while (sai_cad != 2) {
                        printf("Digite o nome do cliente:\n");
                        scanf(" %[^\n]s", cad_nome);
                        printf("Digite o Telefone do cliente:\n");
                        scanf("%d", &cad_tel);

                        cadastro_cliente (cad, cad_nome, cad_tel);

                        printf("Deseja Cadastrar mais um Cliente?\n");
                        printf("(1) Sim.\n");
                        printf("(2) Nao. \n");

                        scanf("%d", &sai_cad);

                    }

                } else if (opt_cli == PEDIDO) {
                        opt_ped = 0;
                        while (opt_ped != SAI_PED) {
                            menu_pedido();
                            scanf("%d", &opt_ped);
                            if (opt_ped == CARDAPIO) {
                                imprime_cardapio(card);
                            } else if (opt_ped == INSERE_PED) {
                                printf("Digite o Codigo do Cliente.\n");
                                scanf("%d", &cod_cli);
                                printf("Insira o item desejado.\n");
                                scanf(" %[^\n]s", pedido);

                                registra_pedido(card, cad, MAX_CARDAPIO, cod_cli, pedido);

                                printf("%d %.2f\n", cad[cod_cli].codigo, cad[cod_cli].conta);
                            }
                        }

                } else if (opt_cli == CONTA) {
                    printf("Digite o Codigo do Cliente. \n");
                    scanf("%d", &cod_cli_conta);
                    printf("A conta do(a) cliente %s eh de %.2f\n", cad[cod_cli_conta].nome, cad[cod_cli_conta].conta);
                    opt_pag = 0;
                    while (opt_pag != SAI_PAG) {
                        menu_pagamento();
                        scanf("%d", &opt_pag);
                        if (opt_pag == CARTAO) {
                            printf("Digite em quantas vezes o Cliente deseja Pagar.\n");
                            scanf("%d", &parcela);
                            while (parcela >= PARCELA_MAX) {
                                printf("Numero de Parcelas invalido\n");
                                scanf("%d", &parcela);
                            }
                            printf("O valor R$ %.2f sera pago em %d vezes de R$ %.2f\n", cad[cod_cli_conta].conta, parcela, pag_cartao(cad, cod_cli_conta, parcela));
                        } else if (opt_pag == DINHEIRO) {
                            printf("Troco para quanto?\n");
                            scanf("%f", &troco_cli);

                            troco(cad, cod_cli_conta, troco_cli);
                        }
                    }
                }
            }
        } else if (opt == FUNCIONARIOS) {
            opt_func = 0;
            while (opt_func != SAI_FUNC) {
                menu_func();
                scanf("%d", &opt_func);
                if (opt_func == LISTA_TURNO) {
                    printf("Digite o Turno que deseja.\n");
                    scanf("%d", &imp_turno);
                    imprime_lista_func (func, imp_turno);
                } else if (opt_func == BATE_PONTO) {
                    printf("Informe o seu Codigo de Funcionario.\n");
                    scanf("%d", &id_ponto);
                    bate_ponto(func, id_ponto);
                }
            }
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

                        cadastra_cardapio(card, item_card, preco);

                        printf("Deseja cadastrar outro item?\n");
                        printf("(1) Sim.\n");
                        printf("(2) Nao.\n");
                        scanf("%d", &sai_card);
                    }

                } else if (opt_adm == ALTERA_FUNC) {
                    sai_cad_func = 0;
                    while (sai_cad_func != 2) {
                        printf("Digite o turno do novo Funcionario.\n");
                        scanf("%d", &turno);
                        while (turno > 2) {
                            printf("Turno invalido.\n");
                            scanf("%d", &turno);
                        }
                        printf("Digite o nome do Funcionario.\n");
                        scanf(" %[^\n]s", cad_func);
                        cadastra_funcionario(func, cad_func, turno);
                        printf("Deseja cadastrar outro Funcionario?\n");
                        printf("(1) Sim.\n");
                        printf("(2) Nao.\n");
                        scanf("%d", &sai_cad_func);

                    }
                } else if (opt_adm == FATURAMENTO) {
                    printf("Faturamento do dia Foi de R$%.2f\n", fat_diario);
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
                                    printf("Banco de dados Deletado\n");
                                    zera_bd_cliente();
                                } else if (opt_reset == ZERA_BD_FUNCIONARIO) {
                                    printf("Banco de dados Deletado\n");
                                    zera_bd_funcionario();
                                } else if (opt_reset == ZERA_BD_CARDAPIO) {
                                    printf("Banco de dados Deletado\n");
                                    zera_bd_cardapio();
                                } else if (opt_reset == NOVA_SENHA) {
                                    printf("redefinir senha.\n");
                                    printf("Digite a nova senha.\n");
                                    scanf("%d", &nova_senha);
                                    senha = troca_senha(nova_senha);
                                    printf("Senha alterada com sucesso!\n");
                                }
                            }

                        } else {
                            printf("Senha incorreta!\n");
                            printf("Tentativa %d de 3.", cont_senha);
                            printf("Tente novamente.\n");
                        }

                     }
                }
            }

        } else if (opt == ENCERRAR) {
            free(cad);
            free(card);
            free(func);
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
