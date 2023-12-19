#include "sort.h"

/**
 * swap2 - function that swaos two numbers
 * @x: pointer to first number
 * @y: pointer to second number
*/

void swap2(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition_lomuto - function that actually performs
 * the partiioning n quick sort
 * @arr: array to be sorted
 * @low: the start of array
 * @high: the end of array
 * @size: size of array
 * Return: returns the pivot place
*/
int partition_lomuto(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap2(&arr[j], &arr[i]);
			if (i != j)
			{
				print_array(arr, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap2(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}
/**
 * quick_sort_recur - impelementation of quicksort with lomuto impl
 * @array: arrray to be sorted
 * @low: the start of array
 * @high: the end of array
 * @size: size of array
*/
void quick_sort_recur(int *array, int low, int high, size_t size)
{
	int j;

	if (low < high)
	{
		j = partition_lomuto(array, low, high, size);
		quick_sort_recur(array, low, j - 1, size);
		quick_sort_recur(array, j + 1, high, size);
	}
}
/**
 * quick_sort - impelementation of quicksort with lomuto impl
 * @array: arrray to be sorted
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	quick_sort_recur(array, 0, size - 1, size);
}
