#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
    t_node  *tail;
    int     size;
}   t_stack; 



int main(void)
{
    t_stack *my_stack = malloc(sizeof(t_stack));
    my_stack->head = NULL;
    my_stack->tail = NULL;
    my_stack->size = 0;

    // Criando um novo nó
    t_node *new_node = malloc(sizeof(t_node));
    new_node->value = 42;
    new_node->next = NULL;
    new_node->prev = NULL;

    my_stack->head = new_node;
    my_stack->tail = new_node;
    my_stack->size = 1;

    printf("Valor na pilha: %d\n", my_stack->head->value);
    printf("Tamanho da pilha: %d\n", my_stack->size);

    // Boa prática: liberar a memória alocada depois do uso
    free(new_node);
    free(my_stack);

    return (0);
}

/*
1. O que é uma struct?
Uma struct (estrutura) em C permite agrupar diferentes variáveis (de tipos iguais ou diferentes) sob um mesmo nome. É o nosso "bloco de construção" personalizado.

2. O que faz o typedef?
O typedef serve para criar um apelido (um novo nome) para um tipo de dado.

Sem o typedef, toda vez que você fosse declarar uma variável do tipo struct s_node, teria que escrever a palavra struct antes: struct s_node meu_no;.

Com o typedef, você pode criar a variável direto usando o seu apelido: t_node meu_no;.


3. Analisando o Primeiro Bloco: t_node

Esta estrutura representa um nó (um elemento individual) de uma lista duplamente encadeada.

int value;: Armazena o dado real que você quer guardar dentro desse nó (por exemplo, um número inteiro).

struct s_node *next;: É um ponteiro que aponta para o próximo nó da lista.

Nota importante: Note que usamos struct s_node e não t_node aqui dentro. Isso acontece porque, no momento em que o compilador está lendo a linha do value, o apelido t_node ainda não terminou de ser criado, mas o nome da struct (s_node) já é conhecido.

struct s_node *prev;: É um ponteiro que aponta para o nó anterior (previous) da lista.

t_node;: É o apelido definitivo que demos para essa estrutura no final.

4. Analisando o Segundo Bloco: t_stack

sta estrutura representa a Pilha (ou o gerenciador da lista como um todo). Ela não guarda os valores diretamente, mas sim controla a estrutura.

t_node *head;: Um ponteiro para a cabeça (o primeiro elemento) da pilha/lista.

t_node *tail;: Um ponteiro para a cauda (o último elemento) da pilha/lista.

int size;: Um contador que guarda quantos elementos existem atualmente na pilha. Isso é ótimo para não precisar contar os nós um por um toda vez.

t_stack;: É o apelido dado para essa estrutura de controle.


5. Onde colocar as definições? (Arquivo .h)
As definições de typedef struct devem ficar em um arquivo de cabeçalho (geralmente chamado de struct.h).
Esse arquivo serve para declarar tipos, constantes e protótipos de funções para que outros arquivos possam enxergá-los.



// struct.h
#ifndef STRUCT_H
# define STRUCT_H

[ESTRTURAS]
[METODOS DE INICIALIZAÇÃO]

#endif

Para usa-las em arquivo .C
*/