#include "sort.h"

/**
 * print_array_range - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: Number of elements in @array
 * @end: Number of elements in @array
 */
void print_array_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
}


/**
 * merge - funcion to merge elements
 * @array: copied array
 * @start: beginng of the arrya to copy from
 * @mid: middle
 * @end: ed of array to copy from
*/
void merge(int *array, int start, int mid, int end)
{
	int i, j, k, lenArr;
	int *temp;

	lenArr = end - start + 1;
	temp = malloc(sizeof(int) * lenArr);
	if (!temp)
	{
		return;
	}

	i = start;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = array[i++];
	}
	while (j <= end)
	{
		temp[k++] = array[j++];
	}
	for (k = 0; k < lenArr; k++)
	{
		array[start + k] = temp[k];
	}
	free(temp);
}

/**
 * merge_sort_recur - funcion to merge elements
 * @array: copied array
 * @start: beginng of the arrya to copy from
 * @end: ed of array to copy from
*/
void merge_sort_recur(int *array, int start, int end)
{
	int mid;

	if (start >= end)
	{
		return;
	}

	mid = (start + end) / 2;
	merge_sort_recur(array, start, mid);
	merge_sort_recur(array, mid + 1, end);
	merge(array, start, mid, end);
	printf("Merging...\n");
	printf("[left]: ");
	print_array_range(array, start, mid);
	printf("\n[right]: ");
	print_array_range(array, mid + 1, end);
	printf("\n[Done]: ");
	print_array_range(array, start, end);
	printf("\n");
}
/**
 * merge_sort - function to implement merge sort top
 * down approach
 * @array: array to be sorted
 * @size: size of such array
*/

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	merge_sort_recur(array, 0, size - 1);
}
