#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: A pointer to the head of a doubly-linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current_node = (*list)->next; current_node != NULL; current_node = temp)
	{
		temp = current_node->next;
		insert = current_node->prev;
		while (insert != NULL && current_node->n < insert->n)
		{
			swap_nodes(list, &insert, current_node);
			print_list((const listint_t *)*list);
		}
	}
}
