#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list.
 * @list: A pointer to the head of a doubly-linked list.
 * @tail: A pointer to the tail of the douby-linked list.
 * @node: A pointer to the node to the swapped.
 * @dir: A flag indicating the direction of swapping
 *		(1 for forward, -1 for backward).
 */
void swap_nodes(listint_t **list, listint_t **tail, listint_t **node, int dir)
{
	listint_t *current = *node;
	listint_t *next_node = (dir == 1) ? current->next : current->prev;

	if (dir == 1 ? (current->next != NULL) : (current->prev != NULL))
	next_node->prev =  current->prev;
	else
		*tail = current->prev;

	if (dir == 1 ? (current->prev != NULL) : (current->next != NULL))
		current->prev->next = next_node;
	else
		*list = next_node;

	current->next = next_node->next;
	if (next_node->next != NULL)
		next_node->next->prev = current;
	current->prev = next_node;
	next_node->next = current;

	*node = next_node;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers using
 *			the cocktail shaker sort algorithm
 * @list: A pointer to the head of a doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	int shaken = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken == 0)
	{
		shaken = 1;

		/* Traverse the list forward */
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &tail, &current, 1);
				print_list((const listint_t *)*list);
				shaken = 0;
			}
		}

		/* Traverse the list backward */
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &tail, &current, -1);
				print_list((const listint_t *)*list);
				shaken = 0;
			}
		}
	}
}
