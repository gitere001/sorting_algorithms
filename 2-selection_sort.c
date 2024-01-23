#include "sort.h"

/**
* swap_int - swap elements
* @a: first element
* @b: second element
* Return: none
*/
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* selection_sort - a function to sort based on selection algorithm
* @array: the array to be sorted
* @size: size of the arrray
* Return: none
*/
void selection_sort(int *array, size_t size)
{
	int *min;

	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_int(array + i, min);
			print_array(array, size);
		}
	}
}
