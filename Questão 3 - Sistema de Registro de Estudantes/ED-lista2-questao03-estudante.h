/*
** Função : TAD Estudante - Definição e operações básicas
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Cabeçalho do TAD Estudante
*/

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
} Estudante;

// Funções
void imprimeEstudante(Estudante e);
float calculaMedia(Estudante e);

#endif
