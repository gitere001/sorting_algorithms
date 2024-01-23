#include "sort.h"

/**
* swap - swap elements
* @a: first element
* @b: second element
* Return: none
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - a function to sort based on selection algorithm
 * @array: the array to be sorted
 * @size: size of the arrray
 * Return: none
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
		}
		for (k = 0; k < size; k++)
		{
			if (k < size - 1)
			{
				printf("%d, ", array[k]);
			}
			else
				printf("%d", array[k]);
		}
		printf("\n");

	}
}
