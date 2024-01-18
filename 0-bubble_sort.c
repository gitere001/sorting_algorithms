#include "sort.h"

/**
* bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int array[], size_t size)
{

	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		int flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*printf("Swap: ");*/
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

				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}
