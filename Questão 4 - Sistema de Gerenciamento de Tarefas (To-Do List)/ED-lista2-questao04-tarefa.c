/*
** Função : Implementação do TAD Tarefa
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Funções para imprimir e comparar datas
*/

#include <stdio.h>
#include "ED-lista2-questao04-tarefa.h"

void imprimeTarefa(Tarefa t) {
    printf("Descrição: %s | Prioridade: %d | Data de Vencimento: ", t.descricao, t.prioridade);
    if (t.dataVencimento == 0) {
        printf("Sem data\n");
    } else {
        int d = t.dataVencimento / 10000;
        int m = (t.dataVencimento / 100) % 100;
        int a = t.dataVencimento % 100;
        printf("%02d/%02d/%02d\n", d, m, a);
    }
}

int comparaData(int d1, int d2) {
    // Retorna:
    // -1 se d1 < d2
    //  0 se d1 == d2
    //  1 se d1 > d2
    if (d1 < d2) return -1;
    else if (d1 == d2) return 0;
    else return 1;
}
