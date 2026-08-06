#include "struct.h"

double compute_disorder(t_stack *a)
{
    t_stack *current;
    t_stack *runner;
    int     mistakes;
    int     total_pairs;
    double  size;

    if (!a || !a->next)
        return (0.0); // Pilha vazia ou com 1 elemento tem desordem 0

    mistakes = 0;
    total_pairs = 0;
    current = a;

    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            total_pairs++;
            if (current->value > runner->value)
            {
                mistakes++;
            }
            runner = runner->next;
        }
        current = current->next;
    }

    if (total_pairs == 0)
        return (0.0);

    // Faz o cast para double para a divisão não truncar
    return ((double)mistakes / total_pairs);
}

