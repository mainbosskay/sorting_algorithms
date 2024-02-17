#include "sort.h"

void swap_int(int *array, size_t size, int *frst, int *secnd);
size_t part_hoare(int *array, ssize_t size, ssize_t lwindx, ssize_t hgindx);
void qsort_hoare(int *array, size_t size, ssize_t lwindx, ssize_t hgindx);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_int - Swapping two integer values
 * @array: array of integers
 * @size: size of the array
 * @frst: pointer to the first value to swap
 * @secnd: pointer to the second value to swap
 * Return: it is void
 */

void swap_int(int *array, size_t size, int *frst, int *secnd)
{
	if (*frst != *secnd)
	{
		*frst = *frst + *secnd;
		*secnd = *frst - *secnd;
		*frst = *frst - *secnd;
	}
	print_array((const int *)array, size);
}

/**
 * part_hoare - Partitions an array with the hoare scheme
 * @array: array of integers
 * @size: size of the the array
 * @lwindx: low index of the partition range
 * @hgindx: high index of the partition range
 * Return: index of the pivot element
 */

size_t part_hoare(int *array, ssize_t size, ssize_t lwindx, ssize_t hgindx)
{
	ssize_t k = lwindx - 1;
	ssize_t s = hgindx + 1;
	int pvt = array[hgindx];

	while (k < size)
	{
		while (array[++k] < pvt)
			;
		while (array[--s] > pvt)
			;
		if (k < s)
			swap_int(array, size, &array[k], &array[s]);
		else if (k >= s)
			break;
	}
	return (k);
}

/**
 * qsort_hoare - Quicksort algorithm with hoare partition
 * @array: array of integers
 * @size: size of the the array
 * @lwindx: low index of the partition range
 * @hgindx: high index of the partition range
 * Return: it is void
 */

void qsort_hoare(int *array, size_t size, ssize_t lwindx, ssize_t hgindx)
{
	if (lwindx < hgindx)
	{
		size_t pvtindx = part_hoare(array, size, lwindx, hgindx);

		qsort_hoare(array, size, lwindx, pvtindx - 1);
		qsort_hoare(array, size, pvtindx, hgindx);
	}
}

/**
 * quick_sort_hoare - Sorting an array of ints with quick sort
 * @array: array of integers
 * @size: size of the array
 * Return: it is void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort_hoare(array, size, 0, size - 1);
}
