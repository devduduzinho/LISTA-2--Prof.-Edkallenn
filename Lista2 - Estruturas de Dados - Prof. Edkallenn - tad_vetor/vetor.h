/*
** Função : 
** Autor : Eduardo da costa silva
** Data :20//06/2025
** Observações:
*/
#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Vetor;

Vetor* criarVetor(int capacidade);
void inserirElemento(Vetor *v, int elemento);
void removerElemento(Vetor *v, int elemento);
int consultarElemento(Vetor *v, int posicao);
void imprimirVetor(Vetor *v);
void liberarVetor(Vetor *v);

#endif