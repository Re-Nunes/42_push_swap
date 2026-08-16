*This project has been created as part of the 42 curriculum by renatanu, jonathfe*

## Descrição

O **Push Swap** é um projeto de ordenação cujo objetivo é ordenar uma pilha de números inteiros utilizando um conjunto limitado de operações em duas pilhas, minimizando ao mesmo tempo o número de movimentos. O desafio não é apenas realizar a ordenação corretamente, mas fazê-lo de forma eficiente o suficiente para atender às exigências do currículo da 42.

O projeto é implementado em C e utiliza uma lista duplamente encadeada personalizada como estrutura de dados subjacente para as pilhas. O programa recebe uma lista de números inteiros como entrada, organiza-os na pilha A e, em seguida, move elementos entre a pilha A e a pilha B utilizando apenas operações como sa, sb, pa, pb, ra, rb, rra, rrb e suas variantes combinadas.

### Objetivos do projeto
O objetivo principal é alcançar um estado final no qual a pilha A contenha os números em ordem crescente e a pilha B esteja vazia.

- Ordenar números inteiros com o menor número possível de operações de pilha
- Utilizar apenas um conjunto restrito de instruções
- Implementar código em C eficiente e legível
- Respeitar restrições de memória e desempenho
- Fornecer uma seleção de algoritmos funcional, com base no tamanho da entrada e no nível de desordem

## Instruções
#### Requisitos

- Um ambiente do tipo Unix
- make
- Um compilador C, como o cc

### Compilação
A partir da raiz do projeto:

``` C
make
```
Isso compila o projeto e gera o executável chamado push_swap.

**Execução**

``` C
./push_swap 3 2 1 5 4
```

Você também pode forçar um modo de algoritmo específico:

``` C
./push_swap --simple 3 2 1
./push_swap --medium 8 7 6 5 4 3 2 1
./push_swap --complex 10 9 8 7 6 5 4 3 2 1
```

Se nenhum modo for especificado, o programa escolhe automaticamente uma abordagem com base no nível de desordem e no tamanho da pilha.

#### Tratamento de erros
O programa exibe:

``` C
Error
```
quando a entrada é inválida — por exemplo, se um número estiver mal formatado ou houver duplicatas.

### Seleção e Justificativa de Algoritmos

Este projeto inclui várias estratégias para lidar com diferentes tamanhos de entrada e níveis de desordem. O objetivo é escolher o método mais eficiente de acordo com a situação, em vez de usar um único algoritmo para tudo.

#### 1. Estratégia para pilhas pequenas
Para pilhas muito pequenas — especialmente com 2 ou 3 elementos —, o programa utiliza uma lógica de ordenação manual direta e altamente otimizada. Essa é a abordagem mais eficiente, pois esses casos são pequenos demais para se beneficiarem de manipulações de pilha mais complexas.

A lógica verifica as possíveis disposições de 2 ou 3 elementos e aplica o mínimo necessário de operações de troca ou rotação. Essa abordagem reduz a sobrecarga (*overhead*) e mantém o número total de instruções extremamente baixo para casos triviais.

#### 2. Estratégia intermediária
Para entradas de tamanho médio, este projeto utiliza uma abordagem intermediária baseada em uma lógica de particionamento de pilha estilo *radix sort*. A ideia é reduzir o problema de ordenação a partes menores e mais gerenciáveis, movendo valores para a pilha B de acordo com seus padrões de bits e, em seguida, restaurando-os para a pilha A na ordem correta.

Essa abordagem é atraente porque:

- evita comparações repetidas de toda a sequência,
- funciona bem com classificação de inteiros e operações bit a bit (*bitwise*)
- é mais fácil de implementar de forma eficiente em um domínio de inteiros de tamanho fixo
- oferece um bom equilíbrio entre velocidade e complexidade do código.

Neste projeto, a opção `--medium` é direcionada para a mesma lógica orientada a *radix* usada para a reorganização eficiente da pilha, mantendo ao mesmo tempo a estratégia alternativa para pilhas pequenas em casos triviais.

#### 3. Estratégia complexa / *radix* completo
Para entradas maiores e mais desordenadas, o projeto utiliza um método de ordenação baseado em *radix* mais robusto. O *radix sort* é muito adequado aqui porque não exige comparações custosas entre todos os elementos da pilha; em vez disso, organiza os números bit a bit, com base em sua representação binária.

Isso é especialmente útil para um projeto como o Push Swap porque:

- já se sabe que os números são inteiros
- a restrição de ordenação baseia-se em um conjunto limitado de instruções
- uma abordagem bit a bit pode reduzir drasticamente o número de operações de movimentação para entradas grandes.

A principal compensação (*trade-off*) é que o algoritmo é mais especializado do que uma ordenação geral baseada em comparações, mas é altamente eficiente para este problema específico.

#### Por que essa combinação de métodos?

O projeto foi concebido para ser prático e eficiente:

- entradas muito pequenas são processadas por lógica personalizada direta
- entradas de tamanho médio utilizam uma estratégia equilibrada
- pilhas grandes ou altamente desordenadas utilizam organização baseada em *radix*.
  
Essa é uma estratégia comum na otimização de algoritmos: utilizar o método mais simples e de menor custo para as entradas menores, e empregar métodos mais estruturados apenas quando estes proporcionam benefícios mensuráveis.

## Estrutura do Projeto
-  ` main.c ` — análise de argumentos da CLI e orquestração
-  ` push_swap.h ` — estruturas compartilhadas e protótipos de funções
-  ` dl_list_utils.c ` — operações com listas duplamente encadeadas
-  ` push_swap_utils.c ` a push_swap_utils_4.c — funções utilitárias, classificação (ranking) e auxiliares de ordenação
-  ` sorting_manual.c ` — lógica de ordenação simples e manual
-  ` sorting_medium_algo.c ` — implementação de ordenação para o modo médio
-  ` sorting_complex_algo.c ` — lógica de ordenação complexa/baseada em Radix Sort
-  ` Makefile ` — instruções de compilação
## AJUSTAR: ft_index_stack_utils.c, parsing_utils.c, parsing.c, stack_utils.c, ###############

### Recursos
#### Material de referência
- Enunciado do projeto Push Swap da 42
- Wikipedia: Radix Sort
- GeeksforGeeks: Radix Sort
- Referências sobre algoritmos de ordenação e explicações sobre ordenação bitwise
- Notas sobre ordenação baseada em pilha e complexidade algorítmica

### Fluxo de trabalho assistido por IA
IA utilizada na elaboração deste arquivo README.md

### Exemplo de uso

``` C
make
```
```
./push_swap --medium 7 3 1 8 2 6 4 5
```

Isso exibe a sequência de operações de pilha necessárias para ordenar a entrada. A saída exata depende do algoritmo escolhido e da ordem dos dados de entrada.

### Conclusão
O **Push Swap** é um projeto que combina manipulação de estruturas de dados, raciocínio algorítmico e otimização. O desafio consiste em transformar uma lista aleatória em uma pilha ordenada utilizando operações bastante restritas, minimizando o número de movimentos e escrevendo código em C limpo e de fácil manutenção.

Esta implementação busca manter a legibilidade e a eficiência ao selecionar a melhor estratégia para cada tamanho de entrada, equilibrando simplicidade, correção e desempenho.