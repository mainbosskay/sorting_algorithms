#include "sort.h"

void swap_node(listint_t *frst, listint_t *secnd);
void insertion_sort_list(listint_t **list);

/**
 * swap_node - Swapping two nodes in a doubly linked list
 * @frst: first nodes pointer
 * @secnd: second nodes pointer
 * Return: it is void
 */

void swap_node(listint_t *frst, listint_t *secnd)
{
	if (frst->prev)
		frst->prev->next = secnd;
	if (secnd->next)
		secnd->next->prev = frst;
	frst->next = secnd->next;
	secnd->prev = frst->prev;
	frst->prev = secnd;
	secnd->next = frst;
}

/**
 * insertion_sort_list - Sorting a doubly linked list with insertion
 * @list: double pointer of the head
 * Return: it is void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentnd;
	listint_t *innernd;

	if (!list || !*list || !(*list)->next)
		return;
	currentnd = (*list)->next;
	while (currentnd != NULL)
	{
		innernd = currentnd;
		currentnd = currentnd->next;
		while (innernd != NULL && innernd->prev != NULL)
		{
			if (innernd->prev->n > innernd->n)
			{
				swap_node(innernd->prev, innernd);
				if (!innernd->prev)
					*list = innernd;
				print_list((const listint_t *)*list);
			}
			else
				innernd = innernd->prev;
		}
	}
}
