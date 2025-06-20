/*
** Função : Lista Encadeada de Estudantes
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Cabeçalho do TAD Lista
*/

#ifndef LISTA_H
#define LISTA_H

#include "ED-lista2-questao03-estudante.h"

typedef struct noLista {
    Estudante estudante;
    struct noLista *prox;
} NoLista;

// Funções
NoLista* criaLista();
NoLista* insereEstudante(NoLista *lista, Estudante e);
NoLista* removeEstudante(NoLista *lista, int matricula);
NoLista* buscaEstudante(NoLista *lista, int matricula);
void imprimeLista(NoLista *lista);
void liberaLista(NoLista *lista);

#endif
