#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list.
 * @list: A pointer to the head of a doubly-linked list.
 * @a: A pointer to the tail of the douby-linked list.
 * @b: A pointer to the node to the swapped.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next =  b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly-linked list of integers in ascending
 *			order using the Cocktail shaker sort algorithm
 * @list: A pointer to the head of a doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (curr = curr->prev; curr != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
