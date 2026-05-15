# Atividade Avaliativa 3

Desafios com fila dinâmica, simulação de atendimento e priorização em C.

## Como compilar e executar

```bash
gcc -Wall exercicios/desafio3_1.c -o desafio3_1
./desafio3_1
```

```bash
gcc -Wall exercicios/desafio3_2.c -o desafio3_2
./desafio3_2
```

---

## Desafios

### Desafio 1 — Simulação de Atendimento

**Enunciado:** Simular o atendimento de uma fila de clientes, onde cada cliente possui `id` e `tempoAtendimento`. Exibir o tempo de espera de cada cliente.

**Solução:** Utiliza uma fila dinâmica (FIFO) implementada com `struct` e `malloc`. Os clientes são inseridos na fila na ordem de chegada com `enqueue`. O atendimento é feito com `dequeue`, removendo sempre o primeiro da fila.

O tempo de espera de cada cliente é calculado como a soma acumulada dos tempos de atendimento de todos os clientes atendidos antes dele:

- Cliente 1: espera = 0 min (é o primeiro)
- Cliente 2: espera = tempo do cliente 1
- Cliente 3: espera = tempo do cliente 1 + tempo do cliente 2
- E assim por diante...

**Estrutura da fila:**
- `Cliente`: struct com `id` (int) e `tempoAtendimento` (int).
- `Elemento`: nó encadeado contendo um `Cliente` e ponteiro `proximo`.
- `Fila`: cabeça com ponteiros `cabeca`, `fim` e contador `tamanho`.
- Operações: `enqueue`, `dequeue`, `empty`, `size`, `imprimir`, `liberar`.

**Restrições atendidas:**
- Sem vetores para simular a fila
- Sem bibliotecas prontas
- Toda a estrutura é dinâmica (`malloc`/`free`)

**Arquivo:** `exercicios/desafio3_1.c`

---

### Desafio 2 — Fila de Impressão com Prioridade

**Enunciado:** Sistema de fila de impressão onde cada documento possui `id`, número de `paginas` e `prioridade`. O documento de maior prioridade (menor valor) é atendido primeiro. Em caso de empate, respeita a ordem de chegada.

**Solução:** Utiliza uma fila com inserção posicionada — ao inserir um novo documento, o `enqueue` percorre a fila e posiciona o elemento no local correto de acordo com sua prioridade. Isso garante que a fila esteja sempre ordenada, e o `dequeue` simplesmente remove o primeiro elemento (o de maior prioridade).

A ordenação por inserção funciona assim:
1. Percorre a fila enquanto `prioridade_atual <= prioridade_novo` (o `<=` garante que em caso de empate, o novo vai depois dos existentes, respeitando FIFO).
2. Insere o novo elemento na posição encontrada.
3. Atualiza os ponteiros `cabeca` e `fim` conforme necessário.

**Estrutura da fila:**
- `Documento`: struct com `id` (int), `paginas` (int) e `prioridade` (int).
- `Elemento`: nó encadeado contendo um `Documento` e ponteiro `proximo`.
- `Fila`: cabeça com ponteiros `cabeca`, `fim` e contador `tamanho`.
- Operações: `enqueue` (com inserção ordenada), `dequeue`, `empty`, `size`, `imprimir`, `liberar`.

**Restrições atendidas:**
- Sem estruturas prontas
- Sem funções externas de ordenação (`qsort`)
- Ordenação feita manualmente por inserção posicionada

**Arquivo:** `exercicios/desafio3_2.c`
