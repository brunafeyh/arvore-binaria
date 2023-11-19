# arvore-binaria
programa que em c que faz diversas funções usando arvore binária de busca

O código faz várias operações em uma árvore binária. As operações são:

* Inserção de um nó na árvore
* Remoção de um nó da árvore
* Percursos da árvore em ordem in-ordem, pré-ordem e pós-ordem
* Cálculo da altura da árvore
* Cálculo da soma dos valores dos nós da árvore
* Verificação se a árvore é cheia
* Verificação se a árvore é estritamente binária
* Cálculo do número de nós da árvore
* Contagem dos nós com valor maior que um determinado valor
* Contagem dos nós pares
* Impressão dos valores dos nós em um intervalo
* Busca da chave seguinte a uma determinada chave
* Busca da chave anterior a uma determinada chave
* Cálculo do número de nós com um filho único
* Cálculo do número de nós internos
* Cálculo do número de folhas
* Verificação se a árvore é uma árvore de busca
* Espelhamento da árvore
* Cálculo da soma dos valores dos nós em um intervalo

O código começa criando uma árvore vazia. Em seguida, insere vários nós na árvore, incluindo dois nós com o mesmo valor (10).

A seguir, o código imprime a árvore em ordem in-ordem. A saída é:

```
2 7 8 10 10 14 15 26
```

O código também calcula a soma dos valores dos nós da árvore, que é 106.

Em seguida, o código remove o nó com valor 1 da árvore. A saída é:

```
2 7 8 10 14 15 26
```

O código também imprime a árvore em ordem in-ordem, pré-ordem e pós-ordem. As saídas são:

```
in_ordem: 2 7 8 10 14 15 26
pre_ordem: 10 7 2 8 14 15 26
pos_ordem: 2 8 7 14 15 26 10
```

O código também calcula a altura da árvore, que é 5.

O código também verifica se a árvore é cheia e se é estritamente binária. A saída é:

```
é cheia: 0
é eh_estritamente_binaria: 0
```

O código também calcula o número de nós da árvore, que é 8.

O código também conta os nós com valor maior que 25. A saída é:

```
maior que 25: 2
```

O código também conta os nós pares. A saída é:

```
num pares: 4
```

O código também imprime os valores dos nós em um intervalo, de 6 a 27. A saída é:

```
intervalo a b: 7 8 10 10 14 15 26
```

O código também busca a chave seguinte a 10. A saída é:

```
chave seguinte: 14
```

O código também busca a chave anterior a 10. A saída é:

```
chave anterior: 8
```

O código também calcula o número de nós com um filho único. A saída é:

```
qde nos filho unico: 3
```

O código também calcula o número de nós internos. A saída é:

```
qde nos internos: 4
```

O código também calcula o número de folhas. A saída é:

```
qde folhas: 3
```

O código também verifica se a árvore é uma árvore de busca. A saída é:

```
é arvore de busca: 1
```

O código também espelha a árvore. A saída é:

```
Arvore binaria espelhada:
26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
```

O código também calcula a soma dos valores dos nós em um intervalo, de 10 a 25. A saída é:

```
Soma intervalo: 96
```

Em seguida, o código libera a memória alocada para a árvore.

O código está bem estruturado e é fácil de entender. Ele usa funções para cada
