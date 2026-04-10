/* ATIVIDADE AVALIATIVA 3 — Desafio 2
   Fila de impressão com prioridade: menor valor = maior prioridade.
   Em caso de empate, respeita a ordem de chegada (FIFO).
   Implementação com fila dinâmica, struct, malloc e ponteiros.
   Ordenação feita por inserção posicionada — sem qsort. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int paginas;
    int prioridade;
} Documento;

typedef struct elemento {
    Documento documento;
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

void enqueue(Fila *f, Documento documento) {
    if (f == NULL) {
        return;
    }

    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro: falta de memoria em enqueue.\n");
        return;
    }
    novo->documento = documento;
    novo->proximo = NULL;

    if (empty(f)) {
        f->cabeca = novo;
        f->fim = novo;
        f->tamanho = f->tamanho + 1;
        return;
    }

    Elemento *anterior = NULL;
    Elemento *atual = f->cabeca;

    while (atual != NULL && atual->documento.prioridade <= documento.prioridade) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = f->cabeca;
        f->cabeca = novo;

    } else {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;

        if (novo->proximo == NULL) {
            f->fim = novo;
        }
    }

    f->tamanho = f->tamanho + 1;
}

Documento dequeue(Fila *f) {
    Documento vazio = {-1, -1, -1};

    if (empty(f)) {
        printf("Fila vazia.\n");
        return vazio;
    }

    Elemento *e = f->cabeca;
    Documento documento = e->documento;

    f->cabeca = e->proximo;
    if (f->cabeca == NULL) {
        f->fim = NULL;
    }

    f->tamanho = f->tamanho - 1;
    free(e);
    e = NULL;

    return documento;
}

void imprimir(Fila *f) {
    printf("   cabeca -> ");
    for (Elemento *atual = f->cabeca; atual != NULL; atual = atual->proximo) {
        printf("[id:%d, %dpag, prio:%d] -> ",
               atual->documento.id,
               atual->documento.paginas,
               atual->documento.prioridade);
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
    printf("Desafio 2: Fila de Impressão com Prioridade\n\n");

    int n;

    printf("1. Quantos documentos deseja inserir? ");
    scanf("%d", &n);
    printf("\n");

    Fila *f = iniciar();
    if (f == NULL) {
        return 1;
    }

    printf("2. Cadastro dos documentos:\n");
    for (int i = 0; i < n; i++) {
        Documento d;
        printf("   Documento %d:\n", i + 1);
        printf("   ID: ");
        scanf("%d", &d.id);
        printf("   Número de páginas: ");
        scanf("%d", &d.paginas);
        printf("   Prioridade (menor = mais urgente): ");
        scanf("%d", &d.prioridade);
        enqueue(f, d);
        printf("\n");
    }

    printf("3. Fila ordenada por prioridade:\n");
    imprimir(f);
    printf("   size = %d\n\n", size(f));

    printf("4. Ordem de impressão:\n\n");
    printf("   %-10s %-10s %-10s\n", "ID", "Páginas", "Prioridade");
    printf("   --------------------------------\n");

    while (!empty(f)) {
        Documento d = dequeue(f);
        printf("   %-10d %-10d %d\n", d.id, d.paginas, d.prioridade);
    }

    liberar(f);
    system("pause");
    return 0;
}
