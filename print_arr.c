#include "sort.h"
/**
 * print_arr - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_arr(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
		{
			_putchar(',');
			_putchar(' ');
		}

		_putNum(array[i]);
		++i;
	}
	_putchar('\n');
}
