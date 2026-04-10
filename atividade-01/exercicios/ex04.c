/* ATIVIDADE AVALIATIVA 1 — Exercício 4
   Imprime a matriz identidade e prova que A * I = A */

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

void multiplicar_matrizes(int A[3][3], int B[3][3], int resultado[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    system("chcp 65001 > nul");

    printf("Exercício 4: Matriz Identidade\n\n");

    int A[3][3];

    printf("1. Digite os elementos da matriz A (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");

    int I[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    printf("2. Matriz A:\n");
    imprimir_matriz(A);
    printf("\n");

    printf("3. Matriz Identidade (I):\n");
    imprimir_matriz(I);
    printf("\n");

    int resultado[3][3];
    multiplicar_matrizes(A, I, resultado);

    printf("4. Resultado de A * I (deve ser igual a A):\n");
    imprimir_matriz(resultado);

    system("pause");
    return 0;
}
