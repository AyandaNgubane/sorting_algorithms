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

	for (i = 0; i < size - 1; i++)
	{
		lowest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lowest])
				lowest = j;
		}
		if (lowest != i)
		{
			temp = array[i];
			array[i] = array[lowest];
			array[lowest] = temp;
			print_array(array, size);
		}
	}
}
