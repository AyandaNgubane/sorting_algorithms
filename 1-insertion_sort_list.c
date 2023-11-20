#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: pointer to head of list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *unsorted = NULL, *sorted = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	while (temp->next != NULL)
	{
		if (temp->n > temp->next->n)
		{
			unsorted = temp->next;
			swap(temp, unsorted);
			if (unsorted->prev == NULL)
				*list = unsorted;
			print_list((const listint_t *) *list);
			while (unsorted->prev != NULL)
			{
				if (unsorted->n >= unsorted->prev->n)
					break;
				sorted = unsorted->prev;
				swap(sorted, unsorted);
				if (unsorted->prev == NULL)
					*list = unsorted;
				print_list((const listint_t *) *list);
			}
		}
		else
			temp = temp->next;
	}
}

/**
 * swap - swaps two nodes
 * @sorted: node on the left
 * @unsorted: node on the right
 * Return: void
 */
void swap(listint_t *sorted, listint_t *unsorted)
{
	if (sorted->prev != NULL)
		sorted->prev->next = unsorted;
	if (unsorted->next != NULL)
		unsorted->next->prev = sorted;
	sorted->next = unsorted->next;
	unsorted->prev = sorted->prev;
	sorted->prev = unsorted;
	unsorted->next = sorted;
}
