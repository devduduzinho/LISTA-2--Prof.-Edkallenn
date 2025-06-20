/*
** Função : 
** Autor : Eduardo da costa silva
** Data :20//06/2025
** Observações:
*/
#include <stdio.h>
#include "vetor.h"

int main() {
    Vetor *v = criarVetor(5);

    inserirElemento(v, 10);
    inserirElemento(v, 20);
    inserirElemento(v, 30);
    inserirElemento(v, 40);
    inserirElemento(v, 50);
    inserirElemento(v, 60);

    imprimirVetor(v);

    removerElemento(v, 30);
    imprimirVetor(v);

    int elemento = consultarElemento(v, 2);
    if (elemento != -1) {
        printf("Elemento na posição 2: %d\n", elemento);
    }

    consultarElemento(v, 10);

    liberarVetor(v);

    return 0;
}