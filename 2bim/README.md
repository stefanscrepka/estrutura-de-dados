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

## Integrantes da equipe

| Nome completo | GitHub |
|---|---|
| Stefan Heinz Screpka | @stefanscrepka |

