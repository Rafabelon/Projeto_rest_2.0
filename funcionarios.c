#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionarios.h"
#include "clientes.h"
#include "administrativo.h"

int id_func = 0;


void menu_func() {
    printf("(1) Lista de Funcionarios por Turno.\n");
    printf("(2) Bater Ponto.\n");
    printf("(3) Sair.\n");

}




Funcionarios* inicia_funcionario() {
    Funcionarios *func = malloc(MAX_FUNC * sizeof(Funcionarios));

    FILE* in = fopen("bd_funcionario.txt", "r");
    while (fscanf(in, "%d %s %d", &func[id_func].codigo, func[id_func].nome, &func[id_func].turno) != EOF)
        id_func++;

    fclose(in);
    return func;
}

void cadastra_funcionario(Funcionarios *func, char *nome, int turno){
    FILE* out = fopen("bd_funcionario.txt", "a");

    func[id_func].codigo = id_func;
    strcpy(func[id_func].nome, nome);
    func[id_func].turno = turno;

    fprintf(out, "%d %s %d\n", func[id_func].codigo, func[id_func].nome, func[id_func].turno);
    id_func++;
    fclose(out);
}

void imprime_lista_func (Funcionarios *func, int turno) {
    int i;
    for (i = 0; i < id_func; i++) {
        if (func[i].turno == turno)
            printf("%d %s\n", func[i].codigo, func[i].nome);
    }

}

void bate_ponto (Funcionarios *func, int id) {
    struct tm *tempo;
    time_t t;
    int hora_atual, min_atual;

    t = time (NULL);
    tempo = localtime(&t);

    hora_atual = tempo -> tm_hour;
    min_atual = tempo -> tm_min;

    printf("Hora atual: %d:%d\n", hora_atual, min_atual);

    if (hora_atual < T1_F) {
        if (hora_atual == T2_I && min_atual <= TOLERANCIA) {
            printf("Ponto registrado com sucesso.\n");
            func[id].ponto = 1;
        }
        else {
            printf("Fora do horario.\n");
            printf("Voce esta %d horas e %d min atrasado.\n", hora_atual - T2_I, min_atual - 10);
        }
    }
}
