#include "sort.h"

/**
 * bubble_sort - Sorting array of integers using bubble sort
 * @array: array of integers
 * @size: size of array
 * Return: it is void
 */

void bubble_sort(int *array, size_t size)
{
	int tempvar;
	size_t adv;
	size_t k;

	if (array == NULL || size == 0)
		return;
	adv = 0;
	while (adv < size)
	{
		for (k = 0 ; k < size - 1 ; k++)
		{
			if (array[k] > array[k + 1])
			{
				tempvar = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tempvar;
				print_array(array, size);
			}
		}
		adv++;
	}
}
