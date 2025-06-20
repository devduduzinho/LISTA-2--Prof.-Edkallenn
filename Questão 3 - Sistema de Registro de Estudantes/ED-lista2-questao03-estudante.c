/*
** Função : Implementação do TAD Estudante
** Autor : Eduardo Costa
** Data : 20/06/2025
** Observações: Funções para imprimir e calcular média
*/

#include <stdio.h>
#include "ED-lista2-questao03-estudante.h"

void imprimeEstudante(Estudante e) {
    printf("Nome: %s | Matrícula: %d | Notas: %.2f, %.2f, %.2f | Média: %.2f\n",
           e.nome, e.matricula, e.notas[0], e.notas[1], e.notas[2], calculaMedia(e));
}

float calculaMedia(Estudante e) {
    return (e.notas[0] + e.notas[1] + e.notas[2]) / 3.0;
}
