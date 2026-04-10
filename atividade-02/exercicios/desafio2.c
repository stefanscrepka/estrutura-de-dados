/* ATIVIDADE AVALIATIVA 2 — Desafio 2
   Inverte uma string utilizando pilha dinâmica com struct
   e alocação dinâmica — sem vetor auxiliar, sem funções prontas */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char valor;
    struct elemento *proximo;
} Elemento;

typedef struct pilha {
    Elemento *topo;
    int tamanho;
} Pilha;

Pilha *iniciar() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: falta de memoria ao iniciar pilha.\n");
        return NULL;
    }
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

int empty(Pilha *p) {
    return p == NULL || p->topo == NULL;
}

int size(Pilha *p) {
    if (p == NULL) {
        return 0;
    }
    return p->tamanho;
}

void push(Pilha *p, char valor) {
    if (p == NULL) {
        return;
    }

    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    if (e == NULL) {
        printf("Erro: falta de memoria em push.\n");
        return;
    }

    e->valor = valor;
    e->proximo = p->topo;
    p->topo = e;
    p->tamanho = p->tamanho + 1;
}

char pop(Pilha *p) {
    Elemento *e;
    char valor;

    if (!empty(p)) {
        e = p->topo;
        valor = e->valor;
        p->topo = p->topo->proximo;
        p->tamanho = p->tamanho - 1;
        free(e);
        e = NULL;
        return valor;
    }

    return '\0';
}

void imprimir(Pilha *p) {
    printf("   Topo -> ");
    for (Elemento *atual = p->topo; atual != NULL; atual = atual->proximo) {
        printf("'%c' -> ", atual->valor);
    }
    printf("NULL\n");
}

void liberar(Pilha *p) {
    if (p == NULL) {
        return;
    }
    while (!empty(p)) {
        pop(p);
    }
    free(p);
}

int main() {
    system("chcp 65001 > nul");
    printf("===== Desafio 2: Inversão de String com Pilha =====\n\n");

    char entrada[100];

    printf("1. Digite a string a ser invertida:\n");
    printf("   String: ");
    scanf("%s", entrada);
    printf("\n");

    Pilha *p = iniciar();
    if (p == NULL) {
        return 1;
    }

    printf("2. Empilhando cada caractere:\n");
    for (int i = 0; entrada[i] != '\0'; i++) {
        push(p, entrada[i]);
    }
    imprimir(p);
    printf("   size = %d\n\n", size(p));

    printf("3. Desempilhando (LIFO) — string invertida:\n");
    printf("   ");
    while (!empty(p)) {
        printf("%c", pop(p));
    }
    printf("\n\n");

    printf("4. String original:  %s\n", entrada);

    liberar(p);
    system("pause");
    return 0;
}