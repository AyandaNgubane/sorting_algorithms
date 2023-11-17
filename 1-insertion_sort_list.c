#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: pointer to list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *other;
	int check = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;

	while (temp->next)
	{
		if (temp->next->n > temp->n)
		{
			temp->next->next = temp->next;
			temp->next = temp;
		}
		else
		{
			temp->next->next = temp->next;
			temp->next = temp;
			temp = temp->next;
		}
	}
}
