/* ATIVIDADE AVALIATIVA 1 — Exercício 6
   Lê dados de 10 alunos usando struct e divide em aprovados e reprovados */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

void imprimir_aluno(Aluno a) {
    printf("   Nome: %-20s | Matrícula: %d | Média: %.2f\n",
           a.nome, a.matricula, a.media);
}

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 6: Aprovados e Reprovados\n\n");

    Aluno alunos[10];
    Aluno aprovados[10];
    Aluno reprovados[10];
    int qtd_aprovados = 0;
    int qtd_reprovados = 0;

    printf("1. Cadastro dos alunos:\n\n");
    for (int i = 0; i < 10; i++) {
        printf("   Aluno %d:\n", i + 1);
        printf("   Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("   Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("   Média Final: ");
        scanf("%f", &alunos[i].media);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        if (alunos[i].media >= 5.0) {
            aprovados[qtd_aprovados] = alunos[i];
            qtd_aprovados++;
        } else {
            reprovados[qtd_reprovados] = alunos[i];
            qtd_reprovados++;
        }
    }

    printf("2. Aprovados (%d aluno(s)):\n", qtd_aprovados);
    for (int i = 0; i < qtd_aprovados; i++) {
        imprimir_aluno(aprovados[i]);
    }
    printf("\n");

    printf("3. Reprovados (%d aluno(s)):\n", qtd_reprovados);
    for (int i = 0; i < qtd_reprovados; i++) {
        imprimir_aluno(reprovados[i]);
    }

    system("pause");
    return 0;
}
