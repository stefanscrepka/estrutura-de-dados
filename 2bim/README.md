# Atividade Avaliativa 1 — Recursividade em C

Trabalho da disciplina de **Estruturas de Dados** (ADSIS3S).
Implementação dos três exercícios propostos com foco em **recursividade pura** (sem variáveis globais e sem bibliotecas que resolvam o problema diretamente).

## Estrutura do repositório

| Arquivo | Exercício |
|---|---|
| `01_fibonacci_ingenuo.c` | Fibonacci recursivo sem otimização, contando as chamadas |
| `02_fibonacci_memoizado.c` | Fibonacci recursivo com memoização em cache alocado dinamicamente, comparando com a versão ingênua |
| `03_torres_hanoi.c` | Torres de Hanoi recursivo, listando movimentos e total |
| `README.md` | Este arquivo |

## Compilação

Todos os programas seguem o mesmo padrão dos exemplos da disciplina:

```bash
gcc -Wall -Wextra -std=c11 01_fibonacci_ingenuo.c   -o fib1
gcc -Wall -Wextra -std=c11 02_fibonacci_memoizado.c -o fib2
gcc -Wall -Wextra -std=c11 03_torres_hanoi.c        -o hanoi
```

## Execução

Cada programa pede a entrada pelo teclado:

```bash
./fib1
./fib2
./hanoi
```

---

## Exercício 1 — Fibonacci recursivo ingênuo

- **Caso base:** `fib(0) = 0` e `fib(1) = 1`.
- **Passo recursivo:** `fib(n) = fib(n-1) + fib(n-2)`, abrindo duas subárvores de chamadas a cada nível.
- **Custo:** exponencial, `O(2^n)`. É justamente isso que queremos evidenciar.

O contador de chamadas é passado **por ponteiro** (`long *chamadas`), evitando variável global. A cada invocação a função incrementa o contador antes de testar o caso base.

Exemplo de execução:

```
fib(10) = 55
Total de chamadas recursivas: 177
```

---

## Exercício 2 — Fibonacci com memoização dinâmica

A solução **preserva a recursão**: a função `fibonacci_memo` continua sendo recursiva, a memoização só **poda** ramos já calculados.

- **Cache alocado dinamicamente** com `malloc((n+1) * sizeof(long))`, inicializado com `-1` (sentinela de "não calculado").
- Antes de abrir as duas subárvores, consulta-se `cache[n]`. Se já tem valor, retorna direto.
- O resultado é guardado em `cache[n]` para evitar recalcular.
- Memória é liberada com `free` no final.

Reduz a complexidade de `O(2^n)` para `O(n)`.

O programa executa **as duas versões** para o mesmo `n` e imprime as duas contagens lado a lado, deixando a diferença explícita:

```
fib(20) = 6765

Chamadas (versao ingenua)   : 21891
Chamadas (versao memoizada) : 39
Reducao                     : 561.31x menos chamadas
Resultados batem? Sim
```

---

## Exercício 3 — Torres de Hanoi

- **Caso base:** `n == 1` — basta mover o disco diretamente da torre de origem para a torre de destino.
- **Passo recursivo:** para `n` discos, três fases:
  1. mover `n-1` discos de **origem → auxiliar** (usando *destino* como apoio);
  2. mover o disco maior (`n`) de **origem → destino**;
  3. mover `n-1` discos de **auxiliar → destino** (usando *origem* como apoio).

O contador de movimentos vai **por ponteiro**, sem global.

O programa imprime cada movimento numerado e ao final mostra o total e a verificação `2^n - 1`.

Exemplo com 3 discos:

```
Movimento 1: disco 1 de A -> C
Movimento 2: disco 2 de A -> B
Movimento 3: disco 1 de C -> B
Movimento 4: disco 3 de A -> C
Movimento 5: disco 1 de B -> A
Movimento 6: disco 2 de B -> C
Movimento 7: disco 1 de A -> C

Total de movimentos realizados : 7
Verificacao (2^3 - 1)          : 7
```

---

## Restrições atendidas

- [x] Núcleo da solução é recursivo nos três exercícios.
- [x] Nenhuma variável global (contadores passados por ponteiro).
- [x] Nenhuma biblioteca pronta resolve o problema diretamente — só `stdio.h` e `stdlib.h` (este último apenas para `malloc`/`free`).
- [x] Caso base claramente identificado e comentado em cada arquivo.
- [x] Versão memoizada usa memória **alocada dinamicamente**.
- [x] Diferença entre versão ingênua e otimizada é mostrada na própria saída do programa 2.

# Estruturas de Dados — Manipulação de Listas Encadeadas

Trabalho da disciplina de Estruturas de Dados (2º bimestre). O projeto implementa um
gerenciador de inteiros usando **lista simplesmente encadeada** (inserção em posição,
busca, inversão e divisão) e uma **playlist de músicas** usando **lista circular
duplamente encadeada**.

Todo o código usa apenas `stdio.h` e `stdlib.h`, sem vetores auxiliares, e foi
escrito em um único arquivo: `atividade_listas.c`.

## Como compilar e executar

```bash
gcc -std=c11 -Wall -Wextra 04_listas_encadeadas.c -o 04_listas_encadeadas.exe
```

O programa compila sem nenhum aviso com `-Wall -Wextra`. A função `main` serve como
demonstração: ela monta as listas, executa cada operação e imprime os resultados.

## As estruturas

O código define duas estruturas:

- `No` — nó da lista de inteiros, com um campo `valor` e o ponteiro `prox`.
- `NoMusica` — nó da playlist, com o nome da música e dois ponteiros, `prox` e `ant`
  (anterior), necessários para a navegação nos dois sentidos.

Elas têm nomes diferentes porque a linguagem C não permite duas estruturas chamadas
`No` no mesmo arquivo. Como tudo está em um único arquivo, a estrutura da playlist
recebeu o nome `NoMusica`.

A alocação de cada tipo de nó fica centralizada em `criarNo` e `criarMusica`, que
fazem o `malloc`, verificam falha e já inicializam os campos. Assim a checagem de
memória não precisa ser repetida em cada função de inserção.

## Parte 1 — Inserção em posição específica

`void inserirPosicao(No **head, int valor, int posicao);`

As posições começam em 0. A função trata todos os casos pedidos: lista vazia, início,
meio e fim. A posição é validada **antes** de qualquer alocação: se for negativa ou
maior que o tamanho da lista, a função exibe uma mensagem de erro e não cria nenhum nó.
Para posição 0 a inserção é feita no início; para as demais, percorre-se a lista até o
nó anterior à posição desejada e o novo nó é ligado ali.

Exemplo: em `10 -> 20 -> 30`, inserir 99 na posição 1 resulta em `10 -> 99 -> 20 -> 30`.

## Parte 2 — Busca por valor

`int buscarValor(No *head, int valor);`

Percorre a lista contando a posição e retorna o índice da primeira ocorrência do valor.
Se o valor não estiver na lista, retorna -1. A contagem é feita apenas com o ponteiro,
sem vetor.

Exemplo: buscar 20 em `10 -> 20 -> 30` retorna 1.

## Parte 3 — Inverter a lista

`void inverterLista(No **head);`

A inversão é feita no próprio lugar, apenas trocando ponteiros, sem criar uma nova
lista. Usa três ponteiros (`anterior`, `atual`, `proximo`): a cada passo guarda-se o
próximo nó, inverte-se a ligação do nó atual para apontar para o anterior e os três
ponteiros avançam. Ao final, o ponteiro `anterior` passa a ser o novo início.

Exemplo: `10 -> 20 -> 30` vira `30 -> 20 -> 10`.

## Parte 4 — Dividir a lista em duas

`void dividirLista(No *head, No **lista1, No **lista2);`

Usa a técnica do ponteiro rápido e lento, sem contar os elementos previamente. O
ponteiro rápido anda de dois em dois e o lento de um em um; quando o rápido chega ao
fim, o lento está no meio da lista. A lista é cortada nesse ponto. Quando o total de
elementos é ímpar, a primeira lista fica com um elemento a mais.

Exemplo: `10 -> 20 -> 30 -> 40 -> 50` é dividida em `10 -> 20 -> 30` e `40 -> 50`.

## Parte 5 — Playlist (lista circular duplamente encadeada)

A playlist mantém o último nó apontando para o primeiro e o primeiro apontando para o
último através do ponteiro `ant`, formando um ciclo navegável nos dois sentidos.

Funções:

- `adicionarMusica` — adiciona uma música ao final mantendo a circularidade. Como o
  `ant` do início já aponta para o último nó, conseguimos achar o fim da lista
  diretamente, sem percorrer tudo.
- `proximaMusica` / `musicaAnterior` — avançam ou voltam um nó. Por ser circular,
  depois da última música a navegação volta para a primeira (e vice-versa).
- `exibirPlaylist` — mostra todas as músicas, usando um laço `do...while` que para ao
  retornar ao início.
- `totalMusicas` — conta quantas músicas existem percorrendo o ciclo uma vez.
- `tocarPlaylistUmaVez` — toca cada música exatamente uma vez.

O nome da música é copiado manualmente pela função `copiarString`, já que não é
permitido usar `string.h` (que traria o `strcpy`).

### Controle de percurso (evitar loop infinito)

Como a lista é circular, percorrê-la sem um limite faria o programa rodar para sempre.
Por isso a função `tocarPlaylistUmaVez` usa o total de músicas como limite do laço,
garantindo que cada música seja tocada uma única vez e o percurso termine.

## Gerência de memória

Toda a memória alocada é liberada ao final:

- `liberarLista` e `liberarPlaylist` recebem o endereço do ponteiro (`**`) e, depois
  de liberar todos os nós, zeram o ponteiro do chamador para evitar uso de ponteiro
  inválido.
- Na playlist, a circularidade é quebrada (o `prox` do último nó vira `NULL`) antes de
  liberar, caso contrário o laço de liberação não teria fim.
- Após a divisão da lista, os nós passam a pertencer às duas metades; o programa libera
  cada metade separadamente, sem liberar o mesmo nó duas vezes.

O programa foi testado compilando com `-Wall -Wextra` (sem avisos) e executado sob o
AddressSanitizer (`-fsanitize=address`), que não acusou vazamentos nem erros de memória.

## Integrantes da equipe

| Nome completo | GitHub |
|---|---|
| Stefan Heinz Screpka | @stefanscrepka |

