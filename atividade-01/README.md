# Atividade Avaliativa 1

Lista de exercícios em C abordando vetores, matrizes, strings, structs, ponteiros e alocação dinâmica.

## Como compilar e executar

```bash
gcc -Wall exercicios/ex01.c -o ex01
./ex01
```

Repita o processo para cada exercício (`ex01.c` até `ex10.c`).

---

## Exercícios

### Exercício 1 — Palavras na Ordem Inversa

**Enunciado:** Lê três palavras do teclado e imprime na ordem inversa.

**Solução:** Três variáveis `char[]` armazenam as palavras lidas com `scanf`. A impressão é feita na ordem `palavra3`, `palavra2`, `palavra1`.

**Arquivo:** `exercicios/ex01.c`

---

### Exercício 2 — Vetor na Ordem Inversa

**Enunciado:** Cria um vetor com 5 inteiros, lê do teclado e imprime na ordem inversa.

**Solução:** Um vetor `int numeros[5]` é preenchido com `for` e `scanf`. Para imprimir na ordem inversa, o laço percorre de `i = 4` até `i = 0`.

**Arquivo:** `exercicios/ex02.c`

---

### Exercício 3 — Matriz Multiplicada por 5

**Enunciado:** Lê uma matriz 3×3 com `for`, multiplica cada elemento por 5 e imprime o resultado.

**Solução:** Dois laços `for` aninhados lêem a matriz. Após a leitura, os mesmos laços percorrem a matriz multiplicando cada posição por 5. Uma função auxiliar `imprimir_matriz` exibe a matriz formatada antes e depois da multiplicação.

**Arquivo:** `exercicios/ex03.c`

---

### Exercício 4 — Matriz Identidade

**Enunciado:** Imprime a matriz identidade de uma matriz 3×3 e prova que A × I = A.

**Solução:** A matriz identidade `I` é definida com `{1,0,0}, {0,1,0}, {0,0,1}`. A função `multiplicar_matrizes` implementa a multiplicação de matrizes com três laços `for` aninhados (algoritmo clássico O(n³)). O resultado de A × I é exibido, demonstrando ser igual à matriz A original.

**Arquivo:** `exercicios/ex04.c`

---

### Exercício 5 — Vetor × Colunas da Matriz

**Enunciado:** Lê um vetor de 3 elementos e uma matriz 3×3, e multiplica o vetor pelas colunas da matriz.

**Solução:** Para cada coluna `j` da matriz, o programa calcula `resultado[j] = Σ vetor[i] × matriz[i][j]` para `i` de 0 a 2. Isso corresponde à multiplicação de um vetor-linha (1×3) por uma matriz (3×3), resultando em um vetor (1×3).

**Arquivo:** `exercicios/ex05.c`

---

### Exercício 6 — Aprovados e Reprovados

**Enunciado:** Lê dados de 10 alunos (nome, matrícula, média) usando `struct`, separa em aprovados e reprovados (média mínima 5.0).

**Solução:** A `struct Aluno` armazena nome, matrícula e média final. Após a leitura dos 10 alunos, um laço verifica a média: se `>= 5.0`, copia para o vetor `aprovados[]`; caso contrário, para `reprovados[]`. Contadores separados (`qtd_aprovados`, `qtd_reprovados`) controlam o tamanho de cada vetor. Uma função `imprimir_aluno` exibe os dados formatados.

**Arquivo:** `exercicios/ex06.c`

---

### Exercício 7 — Busca de Livros

**Enunciado:** Lê dados de 5 livros (título, autor, ano) usando `struct` e busca por título.

**Solução:** A `struct Livro` armazena título (máx. 30), autor (máx. 15) e ano. A leitura usa `scanf(" %[^\n]")` para aceitar nomes com espaços. A busca percorre o vetor de livros comparando cada título com `strcmp`. Todos os livros com o título correspondente são exibidos.

**Arquivo:** `exercicios/ex07.c`

---

### Exercício 8 — Aritmética de Ponteiros

**Enunciado:** Lê um array de 5 inteiros e imprime o dobro de cada valor usando apenas aritmética de ponteiros.

**Solução:** Um ponteiro `int *ptr = array` aponta para o início do array. A leitura usa `scanf("%d", (ptr + i))` e a impressão usa `*(ptr + i)` para acessar cada elemento. Não é utilizada a notação `array[i]` em nenhum momento — todo acesso é feito via aritmética de ponteiros.

**Arquivo:** `exercicios/ex08.c`

---

### Exercício 9 — Ordenação por Referência

**Enunciado:** Lê 3 inteiros, ordena por referência (menor → maior) e retorna 1 se iguais, 0 se diferentes.

**Solução:** A função `ordenar` recebe três ponteiros `int*` (passagem por referência). A ordenação usa bubble sort com 3 comparações: `*a > *b`, `*b > *c`, e novamente `*a > *b`. Uma função auxiliar `trocar` faz a troca via ponteiros. Ao final, verifica se `*a == *b == *c` para retornar 1 ou 0.

**Arquivo:** `exercicios/ex09.c`

---

### Exercício 10 — Alocação Dinâmica com Struct

**Enunciado:** Define `struct Aluno` (nome, nota), aloca dinamicamente `n` alunos e retorna ponteiro para o de maior nota.

**Solução:** O programa lê `n` e aloca memória com `malloc(n * sizeof(Aluno))`. O acesso aos campos é feito exclusivamente via aritmética de ponteiros: `(alunos + i)->nome` e `(alunos + i)->nota`. A função `maiorNota` percorre o vetor comparando notas e retorna um `Aluno*` para o aluno de maior nota. A memória é liberada com `free()` ao final.

**Restrições atendidas:**
- Sem variáveis globais
- Sem vetor estático (usa `malloc`)
- Acesso apenas por ponteiros (`->` e aritmética)

**Arquivo:** `exercicios/ex10.c`
