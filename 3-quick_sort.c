#include "sort.h"

/**
* swap_ints - Swaps two integers in an array.
* @a: Pointer to the first integer to swap.
* @b: Pointer to the second integer to swap.
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* lomuto_partition - Partitions a subset of an array using the
* Lomuto partition scheme.
* @array: The array of integers.
* @size: Size of the array.
* @left: The starting index of the subset to partition.
* @right: The ending index of the subset to partition.
*
* Return: The final partition index.
*
* Description:
*    This function performs partitioning using the Lomuto partition scheme.
*   It selects the last element as the pivot
* and rearranges elements in the array
* such that elements less than the pivot are to the left, and
* elements greater
* than the pivot are to the right. It returns the final position of
* the pivot.
*    Prints the array after each swap operation.
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				/*Print the array after each swap.*/
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		/*Print the array after swapping the pivot.*/
		print_array(array, size);
	}

	return (above);
}

/**
* lomuto_sort - Recursively implements the quicksort algorithm.
* @array: An array of integers to sort.
* @size: The size of the array.
* @left: The starting index of the array partition to sort.
* @right: The ending index of the array partition to sort.
*
* Description:
*    This function recursively applies the quicksort algorithm using the Lomuto
*    partition scheme. It partitions the array, then recursively sorts the
*    left and right subarrays. Prints the array after each swap operation.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (right - left > 0)
	{
		partition_index = lomuto_partition(array, size, left, right);
		/*Recursively sort the subarrays.*/
		lomuto_sort(array, size, left, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, right);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using quicksort.
* @array: Pointer to the array of integers.
* @size: Size of the array.
*
* Description:
* This function sorts the given array in ascending order
* using the quicksort algorithm.
* It employs the Lomuto partition scheme and prints
* the array after each swap of two elements.
*/
void quick_sort(int *array, size_t size)
{
	/*Check for NULL pointer or array size less than 2.*/
	if (array == NULL || size < 2)
		return;

	/*Begin the quicksort process.*/
	lomuto_sort(array, size, 0, size - 1);
}
