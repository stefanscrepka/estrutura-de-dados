#include <stdio.h>

static void pausar(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nPressione ENTER para sair...");
    fflush(stdout);
    getchar();
}

long fibonacci(int n, long *chamadas)
{
    (*chamadas)++;

    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1, chamadas) + fibonacci(n - 2, chamadas);
}

int main(void)
{
    int n;
    long chamadas = 0;

    printf("Fibonacci Recursivo Ingenuo\n\n");
    printf("Informe o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Entrada invalida. n deve ser inteiro nao negativo.\n");
        pausar();
        return 1;
    }

    long resultado = fibonacci(n, &chamadas);

    printf("\nfib(%d) = %ld\n", n, resultado);
    printf("Total de chamadas recursivas: %ld\n", chamadas);

    pausar();
    return 0;
}