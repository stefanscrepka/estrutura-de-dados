/* ATIVIDADE AVALIATIVA 1 — Exercício 5
   Lê vetor 1x3 e matriz 3x3, multiplica o vetor pelas colunas da matriz */

#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz(int m[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("   ");
        for (int j = 0; j < 3; j++) {
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    system("chcp 65001 > nul");

    printf("Exercício 5: Vetor x Colunas da Matriz\n\n");

    int vetor[3];

    printf("1. Digite os 3 elementos do vetor:\n");
    for (int i = 0; i < 3; i++) {
        printf("   vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    int matriz[3][3];

    printf("2. Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");

    int resultado[3];

    for (int j = 0; j < 3; j++) {
        resultado[j] = 0;
        for (int i = 0; i < 3; i++) {
            resultado[j] += vetor[i] * matriz[i][j];
        }
    }

    printf("3. Vetor: [%d, %d, %d]\n\n", vetor[0], vetor[1], vetor[2]);

    printf("4. Matriz:\n");
    imprimir_matriz(matriz);
    printf("\n");

    printf("5. Resultado da multiplicação (vetor x colunas):\n");
    printf("   [%d, %d, %d]\n", resultado[0], resultado[1], resultado[2]);

    system("pause");
    return 0;
}
