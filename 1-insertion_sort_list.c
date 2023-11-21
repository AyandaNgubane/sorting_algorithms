#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: pointer to head of list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *right = NULL, *left = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	while (temp->next != NULL)
	{
		if (temp->n > temp->next->n)
		{
			right = temp->next;
			swap(temp, right);
			if (right->prev == NULL)
				*list = right;
			print_list((const listint_t *) *list);
			while (right->prev != NULL)
			{
				if (right->prev->n <= right->n)
					break;
				left = right->prev;
				swap(left, right);
				if (right->prev == NULL)
					*list = right;
				print_list((const listint_t *) *list);
			}
		}
		else
			temp = temp->next;
	}
}

/**
 * swap - swaps two nodes
 * @node: node to swap
 * @node2: node to swap
 * Return: void
 */
void swap(listint_t *node, listint_t *node2)
{
	if (node->prev != NULL)
		node->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node;
	node->next = node2->next;
	node2->prev = node->prev;
	node->prev = node2;
	node2->next = node;
}
