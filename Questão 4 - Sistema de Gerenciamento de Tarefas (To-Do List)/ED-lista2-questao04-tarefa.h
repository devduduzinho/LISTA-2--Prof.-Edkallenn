/*
** Função : Definição do TAD Tarefa
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Cabeçalho do TAD Tarefa
*/

#ifndef TAREFA_H
#define TAREFA_H

typedef struct {
    char descricao[100];
    int prioridade;      // 1 (baixa), 2 (média), 3 (alta)
    int dataVencimento;  // formato DDMMYYYY, 0 se não tem data
} Tarefa;

void imprimeTarefa(Tarefa t);
int comparaData(int d1, int d2);

#endif
