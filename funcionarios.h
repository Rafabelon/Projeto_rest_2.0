#ifndef FUNCIONARIOS_C
#define FUNCIONARIOS_H
#include "clientes.h"
#include "administrativo.h"

// Numero maximo de funcionarios
#define MAX_FUNC 25

/*Opcao Funcionarios no menu_principal */
#define FUNCIONARIOS 2

/* Opcoes do menu_func */
#define LISTA_TURNO 1
#define BATE_PONTO 2
#define SAI_FUNC 3

/* Turnos */
#define T1_I 7
#define T1_F 15
#define T2_I 16
#define T2_F 23
#define TOLERANCIA 10

extern int id_func;

struct funcionarios {
    int codigo;
    char nome[CHAR_NOME_MAX];
    int turno;
    int ponto;
};

typedef struct funcionarios Funcionarios;

/* */
void menu_func();

/* */
Funcionarios* inicia_funcionario();

void cadastra_funcionario(Funcionarios *func, char *nome, int turno);

void imprime_lista_func (Funcionarios *func, int turno);

void bate_ponto (Funcionarios *func, int id);


#endif // FUNCIONARIOS_C
