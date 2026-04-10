/* ATIVIDADE AVALIATIVA 1 — Exercício 1
   Lê três palavras do teclado e imprime na ordem inversa */

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");

    printf("Exercício 1: Palavras na Ordem Inversa\n\n");

    char palavra1[50];
    char palavra2[50];
    char palavra3[50];

    printf("1. Digite as três palavras:\n");
    printf("   Palavra 1: ");
    scanf("%s", palavra1);
    printf("   Palavra 2: ");
    scanf("%s", palavra2);
    printf("   Palavra 3: ");
    scanf("%s", palavra3);
    printf("\n");

    printf("2. Palavras na ordem inversa:\n");
    printf("   %s\n", palavra3);
    printf("   %s\n", palavra2);
    printf("   %s\n", palavra1);

    system("pause");
    return 0;
}
