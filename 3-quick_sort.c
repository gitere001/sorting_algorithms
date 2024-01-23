#include "sort.h"

void swap_ints(int *a, int *b);

int lomuto_partition(int *array, size_t size, int low, int high);

void lomuto_sort(int *array, size_t size, int low, int high);

void quick_sort(int *array, size_t size);

/**
* swap_ints - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme for quicksort.
* @array: The array to partition.
* @size: The size of the array.
* @low: The low index of the partition.
* @high: The high index of the partition.
*
* Return: The final partition index.
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];

	int j,  i = low - 1;

	for (j = low; j <= high - 1; j++)

	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
* lomuto_sort - Recursive function to perform quicksort.
* @array: The array to sort.
* @size: The size of the array.
* @low: The low index of the partition.
* @high: The high index of the partition.
*/
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, pi - 1);
		lomuto_sort(array, size, pi + 1, high);
	}
}

/**
* quick_sort - Sort an array of integers using quicksort.
* @array: The array to sort.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
