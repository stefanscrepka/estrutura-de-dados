# Atividade Avaliativa 2

Desafios com pilha dinâmica e manipulação de strings em C.

## Como compilar e executar

```bash
gcc -Wall exercicios/desafio1.c -o desafio1
./desafio1
```

```bash
gcc -Wall exercicios/desafio2.c -o desafio2
./desafio2
```

---

## Desafios

### Desafio 1 — Verificação de Balanceamento

**Enunciado:** Recebe uma string com `(`, `)`, `{`, `}`, `[` e `]` e verifica se a expressão está balanceada.

**Solução:** Utiliza uma pilha dinâmica implementada com `struct` e `malloc`. O algoritmo percorre cada caractere da expressão:

- Se for um **símbolo de abertura** (`(`, `{`, `[`), empilha com `push`.
- Se for um **símbolo de fechamento** (`)`, `}`, `]`), verifica:
  - Se a pilha está vazia → inválida (fechamento sem abertura).
  - Se o topo da pilha não corresponde → inválida (ordem incorreta).
  - Caso contrário, desempilha com `pop`.
- Ao final, se a pilha estiver vazia, a expressão é válida. Se ainda houver elementos, há aberturas sem fechamento.

**Estrutura da pilha:**
- `Elemento`: nó com `char valor` e ponteiro `proximo`.
- `Pilha`: cabeça com ponteiro `topo` e contador `tamanho`.
- Operações: `push`, `pop`, `top`, `empty`, `liberar`.

**Exemplos de entrada/saída:**

| Entrada | Saída |
|---|---|
| `({[]})` | VÁLIDA |
| `([)]` | INVÁLIDA |
| `((()` | INVÁLIDA |
| `{[()]}` | VÁLIDA |

**Arquivo:** `exercicios/desafio1.c`

---

### Desafio 2 — Inversão de String com Pilha

**Enunciado:** Recebe uma string e retorna a string invertida utilizando uma pilha.

**Solução:** Cada caractere da string de entrada é empilhado com `push`. Como a pilha segue o princípio LIFO (Last In, First Out), ao desempilhar todos os elementos com `pop`, os caracteres saem na ordem inversa. A string invertida é impressa diretamente durante o desempilhamento, sem utilizar nenhum vetor auxiliar.

**Estrutura da pilha:**
- Mesma implementação do Desafio 1: `Elemento` (nó encadeado) e `Pilha` (cabeça).
- Operações: `push`, `pop`, `empty`, `size`, `imprimir`, `liberar`.

**Restrições atendidas:**
- Sem funções prontas de inversão (como `strrev`)
- Sem vetor auxiliar para armazenar a string invertida
- Manipulação exclusivamente via operações da pilha

**Exemplo de entrada/saída:**

| Entrada | Saída |
|---|---|
| `estrutura` | `aruturse` |
| `pilha` | `ahlip` |

**Arquivo:** `exercicios/desafio2.c`
