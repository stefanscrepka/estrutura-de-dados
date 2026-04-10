/* ATIVIDADE AVALIATIVA 1 — Exercício 7
   Lê dados de 5 livros e busca por título usando strcmp */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char titulo[30];
    char autor[15];
    int ano;
} Livro;

void imprimir_livro(Livro l) {
    printf("   Título: %s\n", l.titulo);
    printf("   Autor:  %s\n", l.autor);
    printf("   Ano:    %d\n", l.ano);
}

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 7: Busca de Livros\n\n");

    Livro livros[5];

    printf("1. Cadastro dos livros:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("   Livro %d:\n", i + 1);
        printf("   Título (max 30): ");
        scanf(" %[^\n]", livros[i].titulo);
        printf("   Autor (max 15):  ");
        scanf(" %[^\n]", livros[i].autor);
        printf("   Ano: ");
        scanf("%d", &livros[i].ano);
        printf("\n");
    }

    /* 2. Busca por título */
    char busca[30];
    int encontrado = 0;

    printf("2. Digite o título que deseja buscar:\n");
    printf("   Título: ");
    scanf(" %[^\n]", busca);
    printf("\n");

    /* 3. Exibição dos resultados */
    printf("3. Resultados para \"%s\":\n\n", busca);
    for (int i = 0; i < 5; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            imprimir_livro(livros[i]);
            printf("\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("   Nenhum livro encontrado com esse título.\n");
    }

    system("pause");
    return 0;
}
