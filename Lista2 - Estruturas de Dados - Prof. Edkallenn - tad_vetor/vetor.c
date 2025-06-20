/*
** Função : 
** Autor : Eduardo da costa silva
** Data :20//06/2025
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Vetor* criarVetor(int capacidade) {
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));
    v->dados = (int*) malloc(capacidade * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidade;
    return v;
}

void inserirElemento(Vetor *v, int elemento) {
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (int*) realloc(v->dados, v->capacidade * sizeof(int));
    }
    v->dados[v->tamanho] = elemento;
    v->tamanho++;
}

void removerElemento(Vetor *v, int elemento) {
    int i, j, encontrado = 0;
    for (i = 0; i < v->tamanho; i++) {
        if (v->dados[i] == elemento) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        for (j = i; j < v->tamanho - 1; j++) {
            v->dados[j] = v->dados[j + 1];
        }
        v->tamanho--;
    } else {
        printf("Elemento %d não encontrado.\n", elemento);
    }
}

int consultarElemento(Vetor *v, int posicao) {
    if (posicao >= 0 && posicao < v->tamanho) {
        return v->dados[posicao];
    } else {
        printf("Posição inválida.\n");
        return -1;
    }
}

void imprimirVetor(Vetor *v) {
    printf("Vetor: ");
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

void liberarVetor(Vetor *v) {
    free(v->dados);
    free(v);
}