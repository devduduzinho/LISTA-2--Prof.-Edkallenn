/*
** Função : Interface das Filas do Sistema de Agendamento de Consultas
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Arquivo de cabeçalho da questão 2 da lista 2 de Estrutura de Dados
*/
#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#define MAX_MEDICO 5

// Definição do paciente
typedef struct {
    char nome[50];
    int idade;
} Paciente;

// Fila Estática (Médico)
typedef struct {
    Paciente pacientes[MAX_MEDICO];
    int inicio, fim, total;
} FilaEstatica;

// Fila Dinâmica (Enfermagem)
typedef struct No {
    Paciente paciente;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaDinamica;

// Funções da Fila Estática
void inicializaFilaEstatica(FilaEstatica *f);
int insereFilaEstatica(FilaEstatica *f, Paciente p);
int removeFilaEstatica(FilaEstatica *f, Paciente *p);
void imprimeFilaEstatica(FilaEstatica *f);

// Funções da Fila Dinâmica
void inicializaFilaDinamica(FilaDinamica *f);
void insereFilaDinamica(FilaDinamica *f, Paciente p);
int removeFilaDinamica(FilaDinamica *f, Paciente *p);
void imprimeFilaDinamica(FilaDinamica *f);
void liberaFilaDinamica(FilaDinamica *f);

#endif
