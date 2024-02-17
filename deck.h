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
