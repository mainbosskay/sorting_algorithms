#include "sort.h"

void swap_int(int *frst, int *secnd);
void cmp_swap(int ascd, int *array, size_t strtindx, size_t endindx);
void bit_merge(int ascd, int *array, size_t strtindx, size_t endindx);
void bitrec(int ascnd, int *array, size_t size, size_t strtidx, size_t endidx);
void bitonic_sort(int *array, size_t size);

/**
 * swap_int - Swapping value of two integers
 * @frst: pointer to the first value
 * @secnd: pointer to the second value
 * Return: it is void
 */

void swap_int(int *frst, int *secnd)
{
	if (*frst != *secnd)
	{
		*frst = *frst + *secnd;
		*secnd = *frst - *secnd;
		*frst = *frst - *secnd;
	}
}

/**
 * cmp_swap - Compares and swaps elements bitonically
 * @ascd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @strtindx: start index of the array
 * @endindx: end index of the array
 * Return: it is void
 */

void cmp_swap(int ascd, int *array, size_t strtindx, size_t endindx)
{
	size_t midindx = (endindx - strtindx + 1) / 2;
	size_t k;

	for (k = strtindx ; k < strtindx + midindx ; k++)
		if ((array[k] > array[k + midindx]) == ascd)
			swap_int(&array[k], &array[k + midindx]);
}

/**
 * bit_merge - Bitonically merge elements
 * @ascd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @strtindx: start index of the array
 * @endindx: end index of the array
 * Return: it is void
 */

void bit_merge(int ascd, int *array, size_t strtindx, size_t endindx)
{
	size_t midindx = (strtindx + endindx) / 2;

	if (endindx - strtindx < 1)
		return;
	cmp_swap(ascd, array, strtindx, endindx);
	bit_merge(ascd, array, strtindx, midindx);
	bit_merge(ascd, array, midindx + 1, endindx);
}

/**
 * bitrec - Bitonically recursively sorts elementts
 * @ascd: True for ascending order, false for descending order
 * @array: pointer to the array of integers
 * @size: size of the array of integers
 * @strtindx: start index of the array
 * @endindx: end index of the array
 * Return: it is void
 */

void bitrec(int ascd, int *array, size_t size, size_t strtindx, size_t endindx)
{
	size_t midindx = (strtindx + endindx) / 2;

	if (endindx - strtindx < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", endindx - strtindx + 1, size,
		ascd ? "UP" : "DOWN");
	print_array(array + strtindx, endindx - strtindx + 1);
	bitrec(1, array, size, strtindx, midindx);
	bitrec(0, array, size, midindx + 1, endindx);
	bit_merge(ascd, array, strtindx, endindx);
	printf("Result [%lu/%lu] (%s):\n", endindx - strtindx + 1, size,
		ascd ? "UP" : "DOWN");
	print_array(array + strtindx, endindx - strtindx + 1);
}

/**
 * bitonic_sort - Sorting an array of integers with bitonic sort
 * @array: pointer to the array of integers
 * @size: size of the array of integers
 * Return: it is void
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitrec(1, array, size, 0, size - 1);
}
