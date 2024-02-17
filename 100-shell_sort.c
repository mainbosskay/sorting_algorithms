#include "sort.h"

size_t knuthseq(size_t size);
void shell_sort(int *array, size_t size);

/**
 * knuthseq - Getting largest gap for knuth sequence
 * @size: size of the array
 * Return: calculated gap size
 */

size_t knuthseq(size_t size)
{
	size_t a;

	a = 1;
	while (a < size)
		a = a * 3 + 1;
	return ((a - 1) / 3);
}

/**
 * shell_sort - Sorting array of ints with shell sort
 * @array: array of integers
 * @size: size of array
 * Return: it is void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t k;
	size_t s;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (gap = knuthseq(size) ; gap ; gap = (gap - 1) / 3)
	{
		for (k = gap ; k < size ; k++)
		{
			temp = array[k];
			for (s = k ; s > gap - 1 && array[s - gap] > temp ; s -= gap)
			{
				array[s] = array[s - gap];
			}
			array[s] = temp;
		}
		print_array(array, size);
	}
}
