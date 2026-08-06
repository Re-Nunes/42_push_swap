void 	merge(int *V, int inicio, int meio, int fim);
void 	embaralhar_vetor(int *V, int tamanho);
int		*copia_vetor(int *V, int tamanho);
void	print_vetor(int *V, int N);

#include <stdio.h>
#include <stdlib.h> 
#include "../struct.h"
#include "operations/operations.h"

// ########### O(n²) ###########

void bubbleSort (int *V, int N) // V = vetor
{
//	int *vetor = (int *) malloc(tamanho * sizeof(int));
//	vetor [23, 4, 67, -8, 90, 54, 21]

	int i;
	int continua;
	int aux;
	int fim = N; // N = tamanho do vetor

	continua = 1;

	while (continua != 0)
	{
		continua = 0;
		i = 0;

		while (i < fim - 1)
		{
			if (V[i] > V[i + 1])
			{
				aux = V[i];
				V[i] = V[i + 1];
				V[i + 1] = aux;
				continua = i;
			}
			i++;
		}
		fim--;// diminui o tamanho do vetor
	}
}


void insertionSort (int *V, int N)
{
// nessa ordenação todo mundo que for maior para a direita ->
//	vetor [23, 44, 672, -80, -90, 174, 21]
	int i, j, aux;

	i = 1;
	while (i < N)
	{
		aux = V[i];
		j = i;
		while (j > 0 && aux < V[j - 1])
		{
			V[j] = V[j - 1];
			j--;
		}
		V[j] = aux;
		i++;
	}
}


void selectionSort(int *V, int N)
{
	int i, j, menor, troca;

	i = 0;

	while (i < N - 1)
	{
		menor = i;
		j = i + 1;
		while (j < N) // procura o menor elemento em relação a "i"
		{
			if (V[j] < V[menor])
				menor = j;
			j++;
		}
		if (i != menor) //troca os valores da posição atual com o "menor"
		{
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
		i++;
	}
}



// ########### O(n√n) ###########

void bucketSort(int *V, int size, int exp) // exp (1$ para unidades, 10 para dezenas, 100 para centenas
{
	int	*buckets[10]; // inicializa os buckets base decimal
	int	bucket_size[10]; // contador para saber quantos elementso em casa balde
	int	i;
	int	j;
	int	digit;
	int	k;

	i = 0;
	while (i < 10) // alocação dinâmica de memória para os 10 baldes
	{
		buckets[i] = malloc(sizeof(int) * size); // reserva memoria exp = quandidade de digitos
		if (!buckets[i])
		{
			while (i > 0)
			{
				i--;
				free(buckets[i]);
			}
			return;
		}
		bucket_size[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		digit = (V[i] / exp) % 10; // pegar o digito

		buckets[digit][bucket_size[digit]] = V[i]; // bucket[4][] 
		bucket_size[digit]++;

		i++;
	}

	k = 0;
	i = 0;

	while (i < 10)
	{
		j = 0;
		while (j < bucket_size[i])
		{
			V[k] = buckets[i][j]; // devolver para o vetor original
			k++;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 10)
	{
		free(buckets[i]);
		i++;
	}
}


// ########### O(n log n) ###########



void radixSort(int *V, int size)
{
	int	max;
	int	exp;

	if (size <= 1)
		return;

	max = V[0];

	exp = 1;
	while (exp <= max) //  loop de Repetição por casas decimais
	{
		bucketSort(V, size, exp);

		exp *= 10;
	}
}

void	radix_sort_binario(t_stack *a, t_stack *b, int max_bits)
{
	int	bit;
	int	size;
	int	i;

	bit = 0;

	while (bit < max_bits)
	{
		size = a->size;
		i = 0;

		while (i < size)
		{
			if (((a->head->value >> bit) & 1) == 0)
			{
				//ft_pb(a, b, config);
				pb(a, b);
			}
			else
			{
				//ft_ra(a);
				ra(a);
			}

			i++;
		}

		while (b->size > 0)
		{
			//ft_pa(a, b, config);
			pa(a, b);
		}

		bit++;
	}
}

// ########### OUTROS ###########

void	mergeSort(int *V, int inicio, int fim)
{
	int meio;
	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		mergeSort(V, inicio, meio); // primeira metade ou left
		mergeSort(V, meio + 1, fim); // segunda metade ou right
		merge(V, inicio, meio, fim);
	}

}


void merge(int *V, int inicio, int meio, int fim)
{
	int *temp;
	int i;
	int j;
	int k;

	temp = malloc((fim - inicio + 1) * sizeof(int));

	if (temp == NULL)
		return;

	i = inicio;
	j = meio + 1;
	k = 0;

	while (i <= meio && j <= fim)
	{
		if (V[i] <= V[j])
		{
			temp[k] = V[i];
			i++;
		}
		else
		{
			temp[k] = V[j];
			j++;
		}

		k++;
	}

	while (i <= meio)
	{
		temp[k] = V[i];
		i++;
		k++;
	}

	while (j <= fim)
	{
		temp[k] = V[j];
		j++;
		k++;
	}

	k = 0;

	while (k < fim - inicio + 1)
	{
		V[inicio + k] = temp[k];
		k++;
	}

	free(temp);
}

void embaralhar_vetor(int *V, int tamanho) 
{
    for (int i = tamanho - 1; i > 0; i--) {
        
        int j = rand() % (i + 1);
        int temporario = V[i];
        V[i] = V[j];
        V[j] = temporario;
    }
}

int	*copia_vetor(int *V, int tamanho) 
{
    int *destino = malloc(tamanho * sizeof(int));
    
    if (destino == NULL) {
        return NULL; 
    }

    for (int i = 0; i < tamanho; i++) {
        destino[i] = V[i];
    }
	embaralhar_vetor(destino, tamanho);
    return destino;
}

void	print_vetor(int *V, int N)
{
	for (int i = 0; i < N; i++) 
        printf("%d ", V[i]);
}

int	main (void)
{

	int vetor_geral[5] = {5, 15, 2, 1, 2};
	int tamanho_vetor_geral= sizeof(vetor_geral) / sizeof(vetor_geral[0]);

// Bubble Sort
    printf("Bubble Sort\n");

	int i;
	int vetor_bubbleSort[7] = {23, 4, 67, -8, 90, 54, 21};
	int tamanho_v_bubbleSort = sizeof(vetor_bubbleSort) / sizeof(vetor_bubbleSort[0]);
	bubbleSort(vetor_bubbleSort, tamanho_v_bubbleSort);	
	bubbleSort(vetor_geral, tamanho_vetor_geral);	

	print_vetor(vetor_bubbleSort, tamanho_v_bubbleSort);
    printf("\n");
	print_vetor(vetor_geral, tamanho_vetor_geral);
	

    printf("\n");

// Insertion Sort
    printf("Insertion Sort\n");

	int vetor_insertionSort[7] = {23, 44, 672, -80, -90, 174, 21};
	int tamanho_v_insertionSort = sizeof(vetor_insertionSort) / sizeof(vetor_insertionSort[0]);
	insertionSort(vetor_insertionSort, tamanho_v_insertionSort);
	insertionSort(vetor_geral, tamanho_vetor_geral);

	print_vetor(vetor_insertionSort, tamanho_v_insertionSort);
    printf("\n");
	print_vetor(vetor_geral, tamanho_vetor_geral);

    printf("\n");

// Selection Sort
    printf("selectionSort\n");
	int *v_geral = copia_vetor(vetor_geral, 5);

	selectionSort(v_geral, tamanho_vetor_geral);
	print_vetor(v_geral, tamanho_vetor_geral);
    printf("\n");
	
// Merge Sort
    printf("mergeSort\n");
	int vetor_mergeSort[10] = {23, 44, 672, -80, -90, 174, 21, 22, 35, 33};
	int tamanho_v_mergeSort = sizeof(vetor_mergeSort) / sizeof(vetor_mergeSort[0]);

	mergeSort(vetor_mergeSort, 0, (tamanho_v_mergeSort - 1));
	print_vetor(vetor_mergeSort, tamanho_v_mergeSort);
    printf("\n");
	mergeSort(v_geral, 0, (tamanho_vetor_geral - 1));
	print_vetor(v_geral, tamanho_vetor_geral);
	


// Radix Sort
    printf("Radix Sort\n");

	int	vetor_radix[8] = {170, 45, 75, 90, 802, 24, 2, 66};
	int tamanho_v_radix = sizeof(vetor_radix) / sizeof(vetor_radix[0]);

	radixSort(vetor_radix, tamanho_v_radix);
	print_vetor(vetor_radix, tamanho_v_radix);

	/*
	Primeira passagem — exp = 1:
	Bucket 0: 170 90
	Bucket 1:
	Bucket 2: 802 2
	Bucket 3:
	Bucket 4: 24
	Bucket 5: 45 75
	Bucket 6: 66
	Bucket 7:
	Bucket 8:
	Bucket 9:
	170 90 802 2 24 45 75 66

	Segunda: exp = 10
	170 → 7
	90  → 9
	802 → 0
	2   → 0
	24  → 2
	45  → 4
	75  → 7
	66  → 6
	Bucket 0: 802 2
	Bucket 1:
	Bucket 2: 24
	Bucket 3:
	Bucket 4: 45
	Bucket 5: 
	Bucket 6: 66
	Bucket 7: 170 75
	Bucket 8:
	Bucket 9: 90
	802 2 24 45 66 170 75 90
	
	Terceira passagem — exp = 100:
	802 → 8
	2   → 0
	24  → 0
	45  → 0
	66  → 0
	170 → 1
	75  → 0
	90  → 0
	2 24 45 66 75 90 170 802
	*/




	return (0);

}