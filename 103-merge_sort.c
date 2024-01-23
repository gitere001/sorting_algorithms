#include "sort.h"

/**
* merge_subarray - Merge two subarrays into a single sorted subarray.
* @original_array: The original array containing the subarrays to merge.
* @buffer: A temporary buffer to store the merged subarray.
* @start_index: The start index of the subarray to be merged.
* @mid_index: The middle index of the subarray.
* @end_index: The end index of the subarray.
*/
void merge_subarray(int *original_array, int *buffer, size_t start_index, size_t mid_index, size_t end_index)
{
	size_t left_index, right_index, buffer_index = 0;

	printf("Merging...\n[Left Subarray]: ");
	print_array(original_array + start_index, mid_index - start_index);

	printf("[Right Subarray]: ");
	print_array(original_array + mid_index, end_index - mid_index);

	for (left_index = start_index, right_index = mid_index; left_index < mid_index && right_index < end_index; buffer_index++)
		buffer[buffer_index] = (original_array[left_index] < original_array[right_index]) ? original_array[left_index++] : original_array[right_index++];

	for (; left_index < mid_index; left_index++)
		buffer[buffer_index++] = original_array[left_index];

	for (; right_index < end_index; right_index++)
		buffer[buffer_index++] = original_array[right_index];

	for (left_index = start_index, buffer_index = 0; left_index < end_index; left_index++)
		original_array[left_index] = buffer[buffer_index++];

	printf("[Done Merging]: ");
	print_array(original_array + start_index, end_index - start_index);
}

/**
* merge_sort_recursive - Recursively apply merge sort to a subarray.
* @subarray: The array containing the subarrays to sort.
* @buffer: A temporary buffer to store sorted results.
* @start_index: The start index of the subarray.
* @end_index: The end index of the subarray.
*/
void merge_sort_recursive(int *subarray, int *buffer, size_t start_index, size_t end_index)
{
	size_t mid_index;

	if (end_index - start_index > 1)
	{
		mid_index = start_index + (end_index - start_index) / 2;
		merge_sort_recursive(subarray, buffer, start_index, mid_index);
		merge_sort_recursive(subarray, buffer, mid_index, end_index);
		merge_subarray(subarray, buffer, start_index, mid_index, end_index);
	}
}

/**
* merge_sort - Sort an array of integers in ascending order using merge sort.
* @array: The array of integers to be sorted.
* @size: The size of the array.
*
* Description: Implements the top-down merge sort algorithm.
*/
void merge_sort(int *array, size_t size)
{
	int *sorting_buffer;

	if (array == NULL || size < 2)
		return;

	sorting_buffer = malloc(sizeof(int) * size);
	if (sorting_buffer == NULL)
		return;

	merge_sort_recursive(array, sorting_buffer, 0, size);

	free(sorting_buffer);
}
