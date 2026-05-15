#include <stdio.h>

static void pausar(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nPressione ENTER para sair...");
    fflush(stdout);
    getchar();
}

void hanoi(int n, char origem, char destino, char auxiliar, long *movimentos)
{
    if (n == 1)
    {
        (*movimentos)++;
        printf("Movimento %ld: disco 1 de %c -> %c\n",
               *movimentos, origem, destino);
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino, movimentos);

    (*movimentos)++;
    printf("Movimento %ld: disco %d de %c -> %c\n",
           *movimentos, n, origem, destino);

    hanoi(n - 1, auxiliar, destino, origem, movimentos);
}

int main(void)
{
    int n;
    long movimentos = 0;

    printf("Torres de Hanoi\n\n");
    printf("Informe a quantidade de discos: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Entrada invalida. n deve ser inteiro positivo.\n");
        pausar();
        return 1;
    }

    printf("\nSequencia de movimentos (A = origem, C = destino, B = auxiliar):\n\n");
    hanoi(n, 'A', 'C', 'B', &movimentos);

    printf("\nTotal de movimentos realizados : %ld\n", movimentos);
    printf("Verificacao (2^%d - 1)         : %ld\n", n, (1L << n) - 1);

    pausar();
    return 0;
}