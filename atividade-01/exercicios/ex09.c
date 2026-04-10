/* ATIVIDADE AVALIATIVA 1 — Exercício 9
   Lê 3 inteiros, ordena por referência (menor ao maior) e
   retorna 1 se os três forem iguais, 0 caso contrário */

#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ordenar(int *a, int *b, int *c) {
    if (*a > *b) trocar(a, b);
    if (*b > *c) trocar(b, c);
    if (*a > *b) trocar(a, b);

    if (*a == *b && *b == *c) {
        return 1;
    }
    return 0;
}

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 9: Ordenação por Referência\n\n");

    int x, y, z;

    printf("1. Digite três valores inteiros:\n");
    printf("   Valor 1: ");
    scanf("%d", &x);
    printf("   Valor 2: ");
    scanf("%d", &y);
    printf("   Valor 3: ");
    scanf("%d", &z);
    printf("\n");

    printf("2. Antes da ordenação: %d, %d, %d\n\n", x, y, z);

    int resultado = ordenar(&x, &y, &z);

    printf("3. Após a ordenação:\n");
    printf("   Primeira variável (menor): %d\n", x);
    printf("   Segunda variável (meio):   %d\n", y);
    printf("   Terceira variável (maior): %d\n\n", z);

    printf("4. Retorno da função: %d ", resultado);
    if (resultado == 1) {
        printf("(os três valores são iguais)\n");
    } else {
        printf("(existem valores diferentes)\n");
    }

    system("pause");
    return 0;
}
