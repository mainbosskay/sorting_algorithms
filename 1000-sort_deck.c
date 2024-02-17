#include "deck.h"

void swap_nd(deck_node_t *frst, deck_node_t *secnd);
int compr_order(const card_t *frst, const card_t *secnd);
void insertion_sort_list(deck_node_t **list);
void sort_deck(deck_node_t **deck);

/**
 * swap_nd - Swapping two nodes in a doubly linked list
 * @frst: pointer to the first node
 * @secnd: pointer to the second node
 * Return: it is void
 */

void swap_nd(deck_node_t *frst, deck_node_t *secnd)
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
 * compr_order - Comparing two playing cards for their order
 * @frst: pointer to the frist card
 * @secnd: pointer to the second card
 * Return: 1 if frst < secnd and 0 otherwise
 */

int compr_order(const card_t *frst, const card_t *secnd)
{
	char *stck1;
	char *stck2;
	char *rankval[] = {"King", "Queen", "Jack", "10", "9", "8", "7", "6",
		"5", "4", "3", "2", "Ace"};
	int frstv = 0;
	int secndv = 0;
	int s = 0;

	for (s = 0 ; s < 13 ; s++)
	{
		for (stck1 = (char *)frst->value, stck2 = rankval[s] ; *stck1 &&
				*stck1 == *stck2 ; ++stck1, ++stck2)
			;
		if (*stck1 == 0 && *stck2 == 0)
		{
			frstv = s;
			break;
		}
	}
	for (s = 0 ; s < 13 ; s++)
	{
		for (stck1 = (char *)secnd->value, stck2 = rankval[s] ; *stck1 &&
				*stck1 == *stck2 ; ++stck1, ++stck2)
			;
		if (*stck1 == 0 && *stck2 == 0)
		{
			secndv = s;
			break;
		}
	}
	if (frst->kind == secnd->kind)
		return (frstv < secndv);
	return (frst->kind > secnd->kind);
}

/**
 * insertion_sort_list - Sorting doubly linked list with insertion
 * @list: double pointer to the head
 * Return: it is void
 */

void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *currentnd, *innernd;

	if (!list || !*list || !(*list)->next)
		return;
	currentnd = (*list)->next;
	while (currentnd != NULL)
	{
		innernd = currentnd;
		currentnd = currentnd->next;
		while (innernd != NULL && innernd->prev != NULL)
		{
			if (compr_order(innernd->prev->card, innernd->card))
			{
				swap_nd(innernd->prev, innernd);
				if (!innernd->prev)
					*list = innernd;
			}
			else
				innernd = innernd->prev;
		}
	}
}

/**
 * sort_deck - Sorting deck of cards with insert sort
 * @deck: double pointer to the head
 * Return: it is void
 */

void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}
