#include <stdio.h>
#include <string.h>



// Definindo constantes para os algoritmos (opcional, mas limpo)
#define ALGO_DEFAULT  0
#define ALGO_SIMPLE   1
#define ALGO_MEDIUM   2
#define ALGO_COMPLEX  3
#define ALGO_ADAPTIVE 4

typedef enum e_strategy
{
    STRAT_SIMPLE,
    STRAT_MEDIUM,
    STRAT_COMPLEX,
    STRAT_ADAPTIVE
}

int main(int argc, char **argv)
{
    int algorithm_type = e_strategy->STRAT_ADAPTIVE;
    int start_index = 1; // De onde começam os números

    // Se argc for menor que o start_index, significa que não há números suficientes
    if (argc <= start_index)
    {
        printf("Erro: Nenhum número fornecido.\n");
        return (1);
    }

    // 1. Verifica se há argumentos suficientes para conter uma flag
    if (argc > 1)
    {
        if (strcmp(argv[1], "--simple") == 0)
        {
            algorithm_type = ALGO_SIMPLE;
            start_index = 2; // Os números começam a partir do argv[2]
        }
        else if (strcmp(argv[1], "--medium") == 0)
        {
            algorithm_type = ALGO_MEDIUM;
            start_index = 2;
        }
        else if (strcmp(argv[1], "--complex") == 0)
        {
            algorithm_type = ALGO_COMPLEX;
            start_index = 2;
        }
        else if (strcmp(argv[1], "--adaptive") == 0)
        {
            algorithm_type = ALGO_ADAPTIVE;
            start_index = 2;
        }
    }

    // 2. Direcionando o fluxo do programa com base na escolha
    if (algorithm_type == ALGO_ADAPTIVE)
    {
        printf("Fluxo escolhido: Algoritmo Adaptativo\n");
        // Chamar sua função adaptativa aqui...
    }
    else if (algorithm_type == ALGO_SIMPLE)
    {
        printf("Fluxo escolhido: Algoritmo Simples\n");
        // Chamar sua função simples aqui...
    }
    else
    {
        printf("Fluxo escolhido: Padrão\n");
        // Chamar o algoritmo padrão aqui...
    }

    // 3. Loop para processar os números a partir do índice correto
    printf("Numeros recebidos:\n");
    for (int i = start_index; i < argc; i++)
    {
        printf(" -> %s\n", argv[i]); // Lembre-se: aqui ainda é string, precisará converter com atoi ou ft_atoi
    }

    return (0);
}

/*

1. O que são argc e argv?
Eles são os parâmetros tradicionais da função int main(int argc, char **argv):

argc (Argument Count): É um número inteiro (int) que representa a quantidade total de argumentos passados para o programa. O nome do próprio executável conta como o primeiro argumento.

argv (Argument Vector): É um vetor de strings (char ** ou char *[]), onde cada posição guarda um dos argumentos digitados no terminal em formato de texto.


```Bash

gcc argc_argv.c 
./argc_argv --adaptive 2 1 3

```

O C organiza isso na memória da seguinte forma:

Índice (argv)	Valor armazenado	Descrição
argv[0]	        "./argc_argv"	    O nome do executável
argv[1]	        "--adaptive"	    O seletor escolhido
argv[2]     	"2"	                O primeiro número (em formato de texto)
argv[3]	        "1"	                O segundo número
argv[4]	        "3"	                O terceiro número


E o argc será 5 (contando o executável + 4 elementos).

2. Como capturar o seletor e definir fluxos diferentes
Para verificar se o usuário passou uma flag (como --simple, --medium, --complex, --adaptive) ou se passou direto os números, usamos a função strcmp da biblioteca <string.h>, que compara duas strings.

Veja um exemplo prático de como estruturar essa lógica no seu main:

*/