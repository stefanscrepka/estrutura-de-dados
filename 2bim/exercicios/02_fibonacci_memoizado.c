#include <stdio.h>
#include <stdlib.h>

static void pausar(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nPressione ENTER para sair...");
    fflush(stdout);
    getchar();
}

long fibonacci_ingenuo(int n, long *chamadas)
{
    (*chamadas)++;

    if (n <= 1)
    {
        return n;
    }
    return fibonacci_ingenuo(n - 1, chamadas) +
           fibonacci_ingenuo(n - 2, chamadas);
}

long fibonacci_memo(int n, long *cache, long *chamadas)
{
    (*chamadas)++;

    if (n <= 1)
    {
        return n;
    }

    if (cache[n] != -1)
    {
        return cache[n];
    }

    cache[n] = fibonacci_memo(n - 1, cache, chamadas) +
               fibonacci_memo(n - 2, cache, chamadas);
    return cache[n];
}

int main(void)
{
    int n;
    long chamadas_ingenuo = 0;
    long chamadas_memo = 0;

    printf("Fibonacci com Memoizacao\n\n");
    printf("Informe o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Entrada invalida. n deve ser inteiro nao negativo.\n");
        pausar();
        return 1;
    }

    if (n > 42)
    {
        printf("\nAtencao: para n > 42 a versao ingenua pode demorar muito.\n");
    }

    long *cache = (long *) malloc((size_t)(n + 1) * sizeof(long));
    if (cache == NULL)
    {
        printf("Falha na alocacao de memoria.\n");
        pausar();
        return 1;
    }
    for (int i = 0; i <= n; i++)
    {
        cache[i] = -1;
    }

    long resultado_memo     = fibonacci_memo(n, cache, &chamadas_memo);
    long resultado_ingenuo  = fibonacci_ingenuo(n, &chamadas_ingenuo);

    printf("\nfib(%d) = %ld\n\n", n, resultado_memo);
    printf("Chamadas (versao ingenua)   : %ld\n", chamadas_ingenuo);
    printf("Chamadas (versao memoizada) : %ld\n", chamadas_memo);

    if (chamadas_memo > 0)
    {
        printf("Reducao                     : %.2fx menos chamadas\n",
               (double) chamadas_ingenuo / (double) chamadas_memo);
    }

    printf("Resultados batem? %s\n",
           (resultado_memo == resultado_ingenuo) ? "Sim" : "Nao");

    free(cache);
    pausar();
    return 0;
}