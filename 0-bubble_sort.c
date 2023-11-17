#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: array
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int check, temp;

	for (i = 0; i < size - 1; i++)
	{
		check = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				check = 1;
				print_array(array, size);
			}
		}
		if (check == 0)
			break;
	}
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
