/* ATIVIDADE AVALIATIVA 1 — Exercício 2
   Cria vetor com 5 inteiros, lê do teclado e imprime na ordem inversa */

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 2: Vetor na Ordem Inversa\n\n");

    
    int numeros[5];

    printf("1. Digite 5 números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("   numeros[%d]: ", i);
        scanf("%d", &numeros[i]);
    }
    printf("\n");
 
    printf("2. Vetor na ordem original:\n");
    printf("   [");
    for (int i = 0; i < 5; i++) {
        printf("%d%s", numeros[i], i < 4 ? ", " : "");
    }
    printf("]\n\n");

    printf("3. Vetor na ordem inversa:\n");
    printf("   [");
    for (int i = 4; i >= 0; i--) {
        printf("%d%s", numeros[i], i > 0 ? ", " : "");
    }
    printf("]\n");

    system("pause");
    return 0;
}
