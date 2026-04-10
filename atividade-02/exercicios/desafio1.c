/* ATIVIDADE AVALIATIVA 2 — Desafio 1
   Verifica se uma expressão com (), {} e [] está balanceada
   utilizando pilha dinâmica com struct e alocação dinâmica */

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

char top(Pilha *p) {
    if (empty(p)) {
        return '\0';
    }
    return p->topo->valor;
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

void liberar(Pilha *p) {
    if (p == NULL) {
        return;
    }
    while (!empty(p)) {
        pop(p);
    }
    free(p);
}

int correspondente(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')') return 1;
    if (abertura == '{' && fechamento == '}') return 1;
    if (abertura == '[' && fechamento == ']') return 1;
    return 0;
}

int verificar_balanceamento(char *expressao) {
    Pilha *p = iniciar();
    if (p == NULL) {
        return -1;
    }

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '(' || c == '{' || c == '[') {
            push(p, c);

        } else if (c == ')' || c == '}' || c == ']') {

            if (empty(p)) {
                liberar(p);
                return 0;
            }

            if (!correspondente(top(p), c)) {
                liberar(p);
                return 0;
            }

            pop(p);
        }
    }

    int resultado = empty(p);
    liberar(p);
    return resultado;
}


int main() {
    system("chcp 65001 > nul");
    printf("Desafio 1: Verificação de Balanceamento\n\n");

    char expressao[100];

    printf("1. Digite a expressão a ser verificada:\n");
    printf("   Expressão: ");
    scanf("%s", expressao);
    printf("\n");

    printf("2. Processando: %s\n\n", expressao);

    int resultado = verificar_balanceamento(expressao);

    printf("3. Resultado:\n");
    if (resultado == 1) {
        printf("   Expressão VÁLIDA: todos os símbolos estão balanceados.\n");
    } else {
        printf("   Expressão INVÁLIDA: símbolos não balanceados.\n");
    }

    system("pause");
    return 0;
}
