#include "sort.h"

void swap_pst(listint_t *frst, listint_t *secnd);
listint_t *rev_traverse(listint_t *hdptr, listint_t *tlptr, listint_t *orptr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_pst - Swapping positions of two nodes in doubly linkd list
 * @frst: pointer to first node
 * @secnd: pointer to second node
 * Return: it is void
 */

void swap_pst(listint_t *frst, listint_t *secnd)
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
 * rev_traverse - Sorting a list in reverse order
 * @hdptr: pointer to the head
 * @tlptr: pointer to the tail
 * @orptr: pointer to the original list
 * Return: New head of list
 */

listint_t *rev_traverse(listint_t *hdptr, listint_t *tlptr, listint_t *orptr)
{
	while (tlptr && tlptr->prev)
	{
		if (tlptr->n < tlptr->prev->n)
		{
			swap_pst(tlptr->prev, tlptr);
			if (tlptr->prev == NULL)
				orptr = tlptr;
			print_list(orptr);
		}
		else
			tlptr = tlptr->prev;
		if (tlptr->prev == NULL)
			hdptr = tlptr;
	}
	return (hdptr);
}

/**
 * cocktail_sort_list - Sorting a doubly linkd list with cocktail shaker sort
 * @list: doubly linked list
 * Return: it is void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *currenthd;
	listint_t *currenttl;
	listint_t *lstlength;
	int k = 0, s = 0, swapnd = 1;

	if (list == NULL || *list == NULL)
		return;
	lstlength = *list;
	for (k = 0 ; lstlength ; k++)
	{
		lstlength = lstlength->next;
	}
	if (k < 2)
		return;
	currenthd = *list;
	while (s < k)
	{
		swapnd = 0;
		while (currenthd && currenthd->next)
		{
			if (currenthd->n > currenthd->next->n)
			{
				swap_pst(currenthd, currenthd->next);
				swapnd++;
				if (!currenthd->prev->prev)
					*list = currenthd->prev;
				print_list(*list);
			}
			else
				currenthd = currenthd->next;
			if (!currenthd->next)
				currenttl = currenthd;
		}
		currenthd = rev_traverse(currenthd, currenttl, *list);
		*list = currenthd;
		s++;
	}
}
