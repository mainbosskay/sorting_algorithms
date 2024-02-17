#include "sort.h"

/**
 * selection_sort - Sorting array of ints with selection algorithm
 * @array: array of integers
 * @size: size of array
 * Return: it is void
 */

void selection_sort(int *array, size_t size)
{
	size_t k;
	size_t t;
	size_t j;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (k = 0 ; k < size - 1 ; k++)
	{
		for (t = size - 1, j = k + 1 ; t > k ; t--)
		{
			if (array[t] < array[j])
			{
				j = t;
			}
		}
		if (array[k] > array[j])
		{
			temp = array[k];
			array[k] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}
