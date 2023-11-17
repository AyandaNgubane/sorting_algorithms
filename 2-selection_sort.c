#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest, temp;

	i = 0;

	while (i < size - 1)
	{
		lowest = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[lowest])
				lowest = j;
			j++;
		}
		if (lowest != i)
		{
			temp = array[i];
			array[i] = array[lowest];
			array[lowest] = temp;
			print_array(array, size);
		}
		i++;
	}
}
