/* ATIVIDADE AVALIATIVA 1 — Exercício 10
   Struct Aluno com nome e nota. Alocação dinâmica de n alunos.
   Função maiorNota retorna ponteiro para o aluno com maior nota.
   Restrições: sem variáveis globais, sem vetor estático,
   acesso apenas por ponteiros. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

Aluno *maiorNota(Aluno *alunos, int n) {
    Aluno *maior = alunos; 

    for (int i = 1; i < n; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = alunos + i;
        }
    }

    return maior;
}

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 10: Alocação Dinâmica com Struct\n\n");

    int n;

    printf("1. Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);
    printf("\n");

    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));

    if (alunos == NULL) {
        printf("   Erro ao alocar memória!\n");
        return 1;
    }

    printf("2. Cadastro dos alunos:\n\n");
    for (int i = 0; i < n; i++) {
        printf("   Aluno %d:\n", i + 1);
        printf("   Nome: ");
        scanf(" %[^\n]", (alunos + i)->nome);
        printf("   Nota: ");
        scanf("%f", &(alunos + i)->nota);
        printf("\n");
    }

    Aluno *destaque = maiorNota(alunos, n);

    printf("3. Aluno com maior nota:\n");
    printf("   Nome: %s\n", destaque->nome);
    printf("   Nota: %.2f\n\n", destaque->nota);

    free(alunos);
    alunos = NULL;
    printf("4. Memória liberada com sucesso.\n");

    system("pause");
    return 0;
}
