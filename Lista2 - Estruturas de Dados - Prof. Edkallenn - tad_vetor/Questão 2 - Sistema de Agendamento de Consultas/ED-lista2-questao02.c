/*
** Função : Sistema de Agendamento de Consultas com Fila Estática (Médico) e Fila Dinâmica (Enfermagem)
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Implementação da questão 2 da lista 2 de Estrutura de Dados
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ED-lista2-questao02.h"

// ===== Fila Estática (Médico) =====

void inicializaFilaEstatica(FilaEstatica *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int insereFilaEstatica(FilaEstatica *f, Paciente p) {
    if (f->total == MAX_MEDICO) {
        printf("Fila de Médico cheia.\n");
        return 0;
    }
    f->pacientes[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_MEDICO;
    f->total++;
    return 1;
}

int removeFilaEstatica(FilaEstatica *f, Paciente *p) {
    if (f->total == 0) {
        printf("Fila de Médico vazia.\n");
        return 0;
    }
    *p = f->pacientes[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_MEDICO;
    f->total--;
    return 1;
}

void imprimeFilaEstatica(FilaEstatica *f) {
    printf("Fila de Médico:\n");
    if (f->total == 0) {
        printf("  Vazia\n");
        return;
    }
    int i, idx = f->inicio;
    for (i = 0; i < f->total; i++) {
        printf("  Nome: %s | Idade: %d\n", f->pacientes[idx].nome, f->pacientes[idx].idade);
        idx = (idx + 1) % MAX_MEDICO;
    }
}

// ===== Fila Dinâmica (Enfermagem) =====

void inicializaFilaDinamica(FilaDinamica *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void insereFilaDinamica(FilaDinamica *f, Paciente p) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return;
    }
    novo->paciente = p;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int removeFilaDinamica(FilaDinamica *f, Paciente *p) {
    if (f->inicio == NULL) {
        printf("Fila de Enfermagem vazia.\n");
        return 0;
    }
    No *aux = f->inicio;
    *p = aux->paciente;
    f->inicio = aux->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return 1;
}

void imprimeFilaDinamica(FilaDinamica *f) {
    printf("Fila de Enfermagem:\n");
    if (f->inicio == NULL) {
        printf("  Vazia\n");
        return;
    }
    No *aux = f->inicio;
    while (aux != NULL) {
        printf("  Nome: %s | Idade: %d\n", aux->paciente.nome, aux->paciente.idade);
        aux = aux->prox;
    }
}

void liberaFilaDinamica(FilaDinamica *f) {
    No *aux = f->inicio;
    while (aux != NULL) {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

// ===== Programa Principal de Teste =====

int main() {
    FilaEstatica filaMedico;
    FilaDinamica filaEnfermagem;

    inicializaFilaEstatica(&filaMedico);
    inicializaFilaDinamica(&filaEnfermagem);

    // Pacientes exemplo
    Paciente p1 = {"Ana", 30};
    Paciente p2 = {"Bruno", 25};
    Paciente p3 = {"Carlos", 40};
    Paciente p4 = {"Diana", 35};
    Paciente p5 = {"Eduardo", 28};
    Paciente p6 = {"Fernanda", 50};

    // Inserção na fila do médico (limitada)
    insereFilaEstatica(&filaMedico, p1);
    insereFilaEstatica(&filaMedico, p2);
    insereFilaEstatica(&filaMedico, p3);
    insereFilaEstatica(&filaMedico, p4);
    insereFilaEstatica(&filaMedico, p5);
    insereFilaEstatica(&filaMedico, p6); // Deve mostrar "Fila cheia"

    imprimeFilaEstatica(&filaMedico);

    // Remoção da fila do médico
    Paciente atendido;
    removeFilaEstatica(&filaMedico, &atendido);
    printf("Atendido no Médico: %s\n", atendido.nome);
    imprimeFilaEstatica(&filaMedico);

    // Inserção na fila da enfermagem (sem limite)
    insereFilaDinamica(&filaEnfermagem, p1);
    insereFilaDinamica(&filaEnfermagem, p2);
    insereFilaDinamica(&filaEnfermagem, p3);
    insereFilaDinamica(&filaEnfermagem, p4);
    insereFilaDinamica(&filaEnfermagem, p5);
    insereFilaDinamica(&filaEnfermagem, p6);

    imprimeFilaDinamica(&filaEnfermagem);

    // Remoção da fila da enfermagem
    removeFilaDinamica(&filaEnfermagem, &atendido);
    printf("Atendido na Enfermagem: %s\n", atendido.nome);
    imprimeFilaDinamica(&filaEnfermagem);

    liberaFilaDinamica(&filaEnfermagem);

    return 0;
}
