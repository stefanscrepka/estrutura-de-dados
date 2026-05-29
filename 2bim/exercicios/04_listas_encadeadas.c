#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;

No *criarNo(int valor)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: malloc falhou\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirFim(No **head, int valor)
{
    No *novo = criarNo(valor);
    if (*head == NULL)
    {
        *head = novo;
        return;
    }
    No *aux = *head;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;
}

void inserirPosicao(No **head, int valor, int posicao)
{
    if (posicao < 0)
    {
        printf("Erro: posicao invalida (%d)\n", posicao);
        return;
    }

    if (posicao == 0)
    {
        No *novo = criarNo(valor);
        novo->prox = *head;
        *head = novo;
        return;
    }

    No *aux = *head;
    int i = 0;
    while (aux != NULL && i < posicao - 1)
    {
        aux = aux->prox;
        i++;
    }

    if (aux == NULL)
    {
        printf("Erro: posicao invalida (%d)\n", posicao);
        return;
    }

    No *novo = criarNo(valor);
    novo->prox = aux->prox;
    aux->prox = novo;
}

int buscarValor(No *head, int valor)
{
    int posicao = 0;
    while (head != NULL)
    {
        if (head->valor == valor)
            return posicao;
        head = head->prox;
        posicao++;
    }
    return -1;
}

void inverterLista(No **head)
{
    No *anterior = NULL;
    No *atual = *head;
    while (atual != NULL)
    {
        No *proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    *head = anterior;
}

void dividirLista(No *head, No **lista1, No **lista2)
{
    if (head == NULL)
    {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head;
    while (rapido->prox != NULL && rapido->prox->prox != NULL)
    {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;
    lento->prox = NULL;
}

void exibirLista(No *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
}

void liberarLista(No **head)
{
    No *atual = *head;
    while (atual != NULL)
    {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}

typedef struct NoMusica
{
    char musica[100];
    struct NoMusica *prox;
    struct NoMusica *ant;
} NoMusica;

void copiarString(char *destino, char *origem, int limite)
{
    int i = 0;
    while (origem[i] != '\0' && i < limite - 1)
    {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

NoMusica *criarMusica(char *nome)
{
    NoMusica *novo = malloc(sizeof(NoMusica));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: malloc falhou\n");
        exit(EXIT_FAILURE);
    }
    copiarString(novo->musica, nome, 100);
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void adicionarMusica(NoMusica **head, char *nome)
{
    NoMusica *novo = criarMusica(nome);
    if (*head == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }
    NoMusica *ultimo = (*head)->ant;
    novo->prox = *head;
    novo->ant = ultimo;
    ultimo->prox = novo;
    (*head)->ant = novo;
}

void proximaMusica(NoMusica **atual)
{
    if (*atual != NULL)
        *atual = (*atual)->prox;
}

void musicaAnterior(NoMusica **atual)
{
    if (*atual != NULL)
        *atual = (*atual)->ant;
}

void exibirPlaylist(NoMusica *head)
{
    if (head == NULL)
    {
        printf("Playlist vazia\n");
        return;
    }
    NoMusica *atual = head;
    do
    {
        printf("[%s] <-> ", atual->musica);
        atual = atual->prox;
    } while (atual != head);
    printf("(volta ao inicio)\n");
}

int totalMusicas(NoMusica *head)
{
    if (head == NULL)
        return 0;
    int total = 0;
    NoMusica *atual = head;
    do
    {
        total++;
        atual = atual->prox;
    } while (atual != head);
    return total;
}

void tocarPlaylistUmaVez(NoMusica *head)
{
    if (head == NULL)
    {
        printf("Nao ha musicas para tocar\n");
        return;
    }
    int total = totalMusicas(head);
    NoMusica *atual = head;
    for (int i = 0; i < total; i++)
    {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    }
}

void liberarPlaylist(NoMusica **head)
{
    if (*head == NULL)
        return;

    NoMusica *ultimo = (*head)->ant;
    ultimo->prox = NULL;

    NoMusica *atual = *head;
    while (atual != NULL)
    {
        NoMusica *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}

int main(void)
{
    No *lista = NULL;

    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    printf("Lista inicial:       ");
    exibirLista(lista);

    inserirPosicao(&lista, 5, 0);
    inserirPosicao(&lista, 99, 2);
    inserirPosicao(&lista, 40, 5);
    inserirPosicao(&lista, 1, 50); 
    printf("Apos inserirPosicao: ");
    exibirLista(lista);

    printf("Posicao do 99:  %d\n", buscarValor(lista, 99));
    printf("Posicao do 123: %d\n", buscarValor(lista, 123));

    inverterLista(&lista);
    printf("Lista invertida:     ");
    exibirLista(lista);

    No *lista1 = NULL;
    No *lista2 = NULL;
    dividirLista(lista, &lista1, &lista2);
    lista = NULL; 
    printf("Metade 1:            ");
    exibirLista(lista1);
    printf("Metade 2:            ");
    exibirLista(lista2);

    liberarLista(&lista1);
    liberarLista(&lista2);

    NoMusica *playlist = NULL;
    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    printf("\nPlaylist:            ");
    exibirPlaylist(playlist);
    printf("Total de musicas: %d\n", totalMusicas(playlist));

    NoMusica *atual = playlist;
    printf("Inicio:        %s\n", atual->musica);
    proximaMusica(&atual);
    proximaMusica(&atual);
    proximaMusica(&atual); 
    printf("+3 (circular): %s\n", atual->musica);
    musicaAnterior(&atual); 
    printf("-1 (circular): %s\n", atual->musica);

    printf("\n");
    tocarPlaylistUmaVez(playlist);

    liberarPlaylist(&playlist);
    return 0;
}