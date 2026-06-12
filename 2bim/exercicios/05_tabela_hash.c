#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PADRAO 11

typedef struct No
{
    char *palavra;
    char *definicao;
    struct No *prox;
} No;

typedef struct TabelaHash
{
    int tamanho;
    int quantidade;
    int colisoes;
    No **buckets;
} TabelaHash;

char *duplicarString(const char *str)
{
    size_t len = strlen(str) + 1;
    char *copia = malloc(len);
    if (copia == NULL)
    {
        fprintf(stderr, "Erro: malloc falhou\n");
        exit(EXIT_FAILURE);
    }
    strcpy(copia, str);
    return copia;
}

int hashPalavra(TabelaHash *tabela, const char *palavra)
{
    unsigned long hash = 5381;
    const unsigned char *str = (const unsigned char *)palavra;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + (unsigned long)c;
    return (int)(hash % (unsigned long)tabela->tamanho);
}

No *criarNo(const char *palavra, const char *definicao)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: malloc falhou\n");
        exit(EXIT_FAILURE);
    }
    novo->palavra = duplicarString(palavra);
    novo->definicao = duplicarString(definicao);
    novo->prox = NULL;
    return novo;
}

TabelaHash *criarTabela(int tamanho)
{
    TabelaHash *tabela = malloc(sizeof(TabelaHash));
    if (tabela == NULL)
    {
        fprintf(stderr, "Erro: malloc falhou\n");
        exit(EXIT_FAILURE);
    }
    tabela->tamanho = tamanho;
    tabela->quantidade = 0;
    tabela->colisoes = 0;
    tabela->buckets = calloc((size_t)tamanho, sizeof(No *));
    if (tabela->buckets == NULL)
    {
        fprintf(stderr, "Erro: calloc falhou\n");
        free(tabela);
        exit(EXIT_FAILURE);
    }
    return tabela;
}

void inserir(TabelaHash *tabela, const char *palavra, const char *definicao)
{
    int indice = hashPalavra(tabela, palavra);
    No *atual = tabela->buckets[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra) == 0)
        {
            free(atual->definicao);
            atual->definicao = duplicarString(definicao);
            printf("Definicao de \"%s\" atualizada com sucesso.\n", palavra);
            return;
        }
        atual = atual->prox;
    }

    if (tabela->buckets[indice] != NULL)
        tabela->colisoes++;

    No *novo = criarNo(palavra, definicao);
    novo->prox = tabela->buckets[indice];
    tabela->buckets[indice] = novo;
    tabela->quantidade++;
    printf("Palavra \"%s\" inserida com sucesso.\n", palavra);
}

No *buscar(TabelaHash *tabela, const char *palavra)
{
    int indice = hashPalavra(tabela, palavra);
    No *atual = tabela->buckets[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra) == 0)
            return atual;
        atual = atual->prox;
    }

    return NULL;
}

int remover(TabelaHash *tabela, const char *palavra)
{
    int indice = hashPalavra(tabela, palavra);
    No *atual = tabela->buckets[indice];
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->palavra, palavra) == 0)
        {
            if (anterior == NULL)
                tabela->buckets[indice] = atual->prox;
            else
                anterior->prox = atual->prox;

            free(atual->palavra);
            free(atual->definicao);
            free(atual);
            tabela->quantidade--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

void imprimirTabela(TabelaHash *tabela)
{
    printf("\n=== Tabela Hash - Dicionario ===\n");
    for (int i = 0; i < tabela->tamanho; i++)
    {
        printf("[%2d] -> ", i);
        No *atual = tabela->buckets[i];

        if (atual == NULL)
        {
            printf("(vazio)");
        }
        else
        {
            while (atual != NULL)
            {
                printf("[\"%s\"]", atual->palavra);
                if (atual->prox != NULL)
                    printf(" -> ");
                atual = atual->prox;
            }
        }
        printf("\n");
    }
}

void exibirEstatisticas(TabelaHash *tabela)
{
    int maiorLista = 0;
    int bucketsOcupados = 0;

    for (int i = 0; i < tabela->tamanho; i++)
    {
        int tamanhoLista = 0;
        No *atual = tabela->buckets[i];
        while (atual != NULL)
        {
            tamanhoLista++;
            atual = atual->prox;
        }
        if (tamanhoLista > 0)
            bucketsOcupados++;
        if (tamanhoLista > maiorLista)
            maiorLista = tamanhoLista;
    }

    double fatorCarga = (double)tabela->quantidade / tabela->tamanho;

    printf("\n=== Estatisticas da Tabela Hash ===\n");
    printf("  Tamanho da tabela : %d buckets\n", tabela->tamanho);
    printf("  Quantidade        : %d elemento(s)\n", tabela->quantidade);
    printf("  Buckets ocupados  : %d\n", bucketsOcupados);
    printf("  Buckets vazios    : %d\n", tabela->tamanho - bucketsOcupados);
    printf("  Colisoes          : %d\n", tabela->colisoes);
    printf("  Maior lista       : %d elemento(s)\n", maiorLista);
    printf("  Fator de carga    : %.4f\n", fatorCarga);
}

void liberarTabela(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->tamanho; i++)
    {
        No *atual = tabela->buckets[i];
        while (atual != NULL)
        {
            No *prox = atual->prox;
            free(atual->palavra);
            free(atual->definicao);
            free(atual);
            atual = prox;
        }
    }
    free(tabela->buckets);
    free(tabela);
}

void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu(void)
{
    printf("\n=================================\n");
    printf("    DICIONARIO - TABELA HASH     \n");
    printf("=================================\n");
    printf(" 1. Inserir palavra\n");
    printf(" 2. Buscar palavra\n");
    printf(" 3. Remover palavra\n");
    printf(" 4. Exibir tabela\n");
    printf(" 5. Exibir estatisticas\n");
    printf(" 0. Sair\n");
    printf("---------------------------------\n");
    printf(" Opcao: ");
}

int main(void)
{
    TabelaHash *tabela = criarTabela(TAMANHO_PADRAO);
    int opcao;
    char palavra[256];
    char definicao[1024];
    char linha[256];

    printf("Dicionario com Tabela Hash iniciado (%d buckets).\n", TAMANHO_PADRAO);

    do
    {
        exibirMenu();

        if (scanf("%d", &opcao) != 1)
        {
            printf("Opcao invalida.\n");
            limparBuffer();
            opcao = -1;
            continue;
        }
        limparBuffer();

        switch (opcao)
        {
            case 1:
                printf("Palavra   : ");
                if (fgets(linha, sizeof(linha), stdin) == NULL) break;
                linha[strcspn(linha, "\r\n")] = '\0';
                if (strlen(linha) == 0) { printf("Erro: palavra nao pode ser vazia.\n"); break; }
                strncpy(palavra, linha, 255);
                palavra[255] = '\0';
                printf("Definicao : ");
                if (fgets(definicao, sizeof(definicao), stdin) == NULL) break;
                definicao[strcspn(definicao, "\r\n")] = '\0';
                if (strlen(definicao) == 0) { printf("Erro: a definicao nao pode ser vazia.\n"); break; }
                inserir(tabela, palavra, definicao);
                break;

            case 2:
            {
                printf("Palavra: ");
                if (fgets(linha, sizeof(linha), stdin) == NULL) break;
                linha[strcspn(linha, "\r\n")] = '\0';
                if (strlen(linha) == 0) { printf("Erro: palavra nao pode ser vazia.\n"); break; }
                No *resultado = buscar(tabela, linha);
                if (resultado != NULL)
                    printf("-> %s: %s\n", resultado->palavra, resultado->definicao);
                else
                    printf("Palavra \"%s\" nao encontrada no dicionario.\n", linha);
                break;
            }

            case 3:
                printf("Palavra: ");
                if (fgets(linha, sizeof(linha), stdin) == NULL) break;
                linha[strcspn(linha, "\r\n")] = '\0';
                if (strlen(linha) == 0) { printf("Erro: palavra nao pode ser vazia.\n"); break; }
                if (remover(tabela, linha))
                    printf("Palavra \"%s\" removida com sucesso.\n", linha);
                else
                    printf("Palavra \"%s\" nao encontrada no dicionario.\n", linha);
                break;

            case 4:
                imprimirTabela(tabela);
                break;

            case 5:
                exibirEstatisticas(tabela);
                break;

            case 0:
                printf("Encerrando o programa. Ate mais!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    liberarTabela(tabela);
    return 0;
}
