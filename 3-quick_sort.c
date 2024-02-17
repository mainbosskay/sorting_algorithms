#include "sort.h"

void swap_int(int *array, size_t size, int *frst, int *secnd);
size_t part_lmt(int *array, size_t size, ssize_t lwidx, ssize_t hgidx);
void qsort_lmt(int *array, size_t size, ssize_t lwidx, ssize_t hgidx);
void quick_sort(int *array, size_t size);

/**
 * swap_int - Swapping two ints values in an array
 * @array: array of integers
 * @size: size of the array
 * @frst: first value pointer
 * @secnd: second value pointer
 * Return: it is void
 */

void swap_int(int *array, size_t size, int *frst, int *secnd)
{
	if (*frst != *secnd)
	{
		*frst = *frst + *secnd;
		*secnd = *frst - *secnd;
		*frst = *frst - *secnd;
		print_array((const int *)array, size);
	}
}

/**
 * part_lmt - Partition array with the lomuto scheme
 * @array: array of integers
 * @size: size of the array
 * @lwidx: low index of the partition range
 * @hgidx: high index of the partition range
 * Return: index of the pivot element after partitioning
 */

size_t part_lmt(int *array, size_t size, ssize_t lwidx, ssize_t hgidx)
{
	int k;
	int s;
	int pvt = array[hgidx];

	for (k = s = lwidx ; s < hgidx ; s++)
		if (array[s] < pvt)
			swap_int(array, size, &array[s], &array[k++]);
	swap_int(array, size, &array[k], &array[hgidx]);
	return (k);
}

/**
 * qsort_lmt- Quicksort algorithm with lomuto partition
 * @array: array of integers
 * @size: size of the array
 * @lwidx: low index of the partition range
 * @hgidx: high index of the partition range
 * Return: it is void
 */

void qsort_lmt(int *array, size_t size, ssize_t lwidx, ssize_t hgidx)
{
	if (lwidx < hgidx)
	{
		size_t pvtindx = part_lmt(array, size, lwidx, hgidx);

		qsort_lmt(array, size, lwidx, pvtindx - 1);
		qsort_lmt(array, size, pvtindx + 1, hgidx);
	}
}

/**
 * quick_sort - Sorting an array of ints with quick sort
 * @array: array of integers
 * @size: size of the array
 * Return: it is void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort_lmt(array, size, 0, size - 1);
}

