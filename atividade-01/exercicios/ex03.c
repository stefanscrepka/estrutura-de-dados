/* ATIVIDADE AVALIATIVA 1 — Exercício 3
   Lê matriz 3x3, multiplica cada elemento por 5 e imprime o resultado */

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

    printf("Exercício 3: Matriz Multiplicada por 5\n\n");

    int matriz[3][3];

    printf("1. Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");

    printf("2. Matriz original:\n");
    imprimir_matriz(matriz);
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = matriz[i][j] * 5;
        }
    }

    printf("3. Matriz após multiplicar por 5:\n");
    imprimir_matriz(matriz);

    system("pause");
    return 0;
}
