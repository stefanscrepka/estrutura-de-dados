/* ATIVIDADE AVALIATIVA 3 — Desafio 1
   Simulação de atendimento de fila de clientes com fila dinâmica
   utilizando struct, malloc e ponteiros */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int tempoAtendimento;
} Cliente;

typedef struct elemento {
    Cliente cliente;
    struct elemento *proximo;
} Elemento;

typedef struct fila {
    Elemento *cabeca;
    Elemento *fim;
    int tamanho;
} Fila;

Fila *iniciar() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro: falta de memoria ao iniciar fila.\n");
        return NULL;
    }
    f->cabeca = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

int empty(Fila *f) {
    return f->tamanho == 0 || f->cabeca == NULL;
}

int size(Fila *f) {
    if (f == NULL) {
        return 0;
    }
    return f->tamanho;
}

void enqueue(Fila *f, Cliente cliente) {
    if (f == NULL) {
        return;
    }

    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    if (e == NULL) {
        printf("Erro: falta de memoria em enqueue.\n");
        return;
    }

    e->cliente = cliente;
    e->proximo = NULL;

    if (f->fim != NULL) {
        f->fim->proximo = e;
    } else {
        f->cabeca = e;
    }
    f->fim = e;
    f->tamanho = f->tamanho + 1;
}

Cliente dequeue(Fila *f) {
    Cliente vazio = {-1, -1};

    if (empty(f)) {
        printf("Fila vazia.\n");
        return vazio;
    }

    Elemento *e = f->cabeca;
    Cliente cliente = e->cliente;

    f->cabeca = e->proximo;
    if (f->cabeca == NULL) {
        f->fim = NULL;
    }

    f->tamanho = f->tamanho - 1;
    free(e);
    e = NULL;

    return cliente;
}

void imprimir(Fila *f) {
    printf("   cabeca -> ");
    for (Elemento *atual = f->cabeca; atual != NULL; atual = atual->proximo) {
        printf("[id:%d, %dmin] -> ", atual->cliente.id, atual->cliente.tempoAtendimento);
    }
    printf("NULL <- fim\n");
}

void liberar(Fila *f) {
    if (f == NULL) {
        return;
    }
    while (!empty(f)) {
        dequeue(f);
    }
    free(f);
}

int main() {
    system("chcp 65001 > nul");
    printf("Desafio 1: Simulação de Atendimento\n\n");

    int n;

    printf("1. Quantos clientes deseja cadastrar? ");
    scanf("%d", &n);
    printf("\n");

    Fila *f = iniciar();
    if (f == NULL) {
        return 1;
    }

    printf("2. Cadastro dos clientes (ordem de chegada):\n");
    for (int i = 0; i < n; i++) {
        Cliente c;
        printf("   Cliente %d:\n", i + 1);
        printf("   ID: ");
        scanf("%d", &c.id);
        printf("   Tempo de atendimento (min): ");
        scanf("%d", &c.tempoAtendimento);
        enqueue(f, c);
        printf("\n");
    }

    printf("3. Fila formada:\n");
    imprimir(f);
    printf("   size = %d\n\n", size(f));

    printf("4. Simulação do atendimento:\n\n");
    printf("   %-10s %-20s %-20s\n", "Cliente", "Tempo Atendimento", "Tempo de Espera");
    printf("   --------------------------------------------------\n");

    int tempoEspera = 0;

    while (!empty(f)) {
        Cliente c = dequeue(f);
        printf("   ID: %-7d %-20d %d min\n",
               c.id, c.tempoAtendimento, tempoEspera);
        tempoEspera = tempoEspera + c.tempoAtendimento;
    }

    liberar(f);
    system("pause");
    return 0;
}
