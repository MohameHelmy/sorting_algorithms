#include "sort.h"
/**
 * selection_sort - function to implement insertion sort with arrays
 * @array: array to sort
 * @size: size of arr
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int idx;
	int tmp;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				idx = j;
			}
		}
		if (array[i] != tmp)
		{
			array[idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
