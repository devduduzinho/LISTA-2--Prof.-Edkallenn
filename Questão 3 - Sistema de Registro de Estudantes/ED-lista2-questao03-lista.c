/*
** Função : Implementação da Lista Encadeada de Estudantes
** Autor : Eduardo Costa 
** Data : 20/06/2025
** Observações: Inserção, remoção e busca
*/

#include <stdio.h>
#include <stdlib.h>
#include "ED-lista2-questao03-lista.h"

NoLista* criaLista() {
    return NULL;
}

NoLista* insereEstudante(NoLista *lista, Estudante e) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
    if (novo == NULL) return lista;
    novo->estudante = e;
    novo->prox = lista;
    return novo;
}

NoLista* removeEstudante(NoLista *lista, int matricula) {
    NoLista *ant = NULL, *atual = lista;
    while (atual != NULL && atual->estudante.matricula != matricula) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Estudante %d não encontrado.\n", matricula);
        return lista;
    }
    if (ant == NULL) {
        lista = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
    return lista;
}

NoLista* buscaEstudante(NoLista *lista, int matricula) {
    while (lista != NULL) {
        if (lista->estudante.matricula == matricula) {
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

void imprimeLista(NoLista *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    while (lista != NULL) {
        imprimeEstudante(lista->estudante);
        lista = lista->prox;
    }
}

void liberaLista(NoLista *lista) {
    NoLista *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
