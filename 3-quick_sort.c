#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (array == NULL || size < 2)
		return;

	l_sort(array, start, end, size);
}

/**
 * l_sort - lomuto sort algorithm
 * @arr: array to be sorted
 * @start: starting point of array
 * @end: end point of array
 * @size: size of array
 * Return: void
 */
void l_sort(int arr[], int start, int end, size_t size)
{
	if (start < end)
	{
		int pivot = partition(arr, start, end, size);

		l_sort(arr, start, pivot - 1, size);
		l_sort(arr, pivot + 1, end, size);
	}
}

/**
 * partition - partitions the array
 * @arr: array to be partitioned
 * @start: starting point of array
 * @end: end point of array
 * @size: size of array
 * Return: position of pivot
 */
size_t partition(int arr[], int start, int end, size_t size)
{
	int pivot = arr[end], i = start, j, temp, temp2;

	for (j = start; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			if (temp != arr[i])
				print_array(arr, size);

			i++;
		}
	}

	temp2 = arr[i];
	arr[i] = arr[end];
	arr[end] = temp2;

	if (temp2 != arr[i])
		print_array(arr, size);

	return (i);
}
