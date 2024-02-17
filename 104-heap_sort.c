#include "sort.h"

#define leftchildidx(x) (((x) * 2) + 1)
#define parentidx(x) (((x) - 1) / 2)

void swap_int_val(int *array, size_t size, int *frst, int *secnd);
void sift_down(int *array, size_t strtindx, size_t endindx, size_t size);
void convt_array(int *array, size_t size);
void heap_sort(int *array, size_t size);

/**
 * swap_int_val - Swapping two integer values
 * @array: array of integers
 * @size: size of the array
 * @frst: pointer to the first value
 * @secnd: pointer to the second value
 * Return: it is void
 */

void swap_int_val(int *array, size_t size, int *frst, int *secnd)
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
 * sift_down - Implementing the sift_down operation
 * @array: array of integers
 * @size: size of the array
 * @strtindx: starting index of the array
 * @endindx: ending index of the array
 * Return: it is void
 */

void sift_down(int *array, size_t strtindx, size_t endindx, size_t size)
{
	size_t current = strtindx;
	size_t swapindx;
	size_t child;

	while (leftchildidx(current) <= endindx)
	{
		child = leftchildidx(current);
		swapindx = current;
		if (array[swapindx] < array[child])
			swapindx = child;
		if (child + 1 <= endindx && array[swapindx] < array[child + 1])
			swapindx = child + 1;
		if (swapindx == current)
			return;
		swap_int_val(array, size, &array[current], &array[swapindx]);
		current = swapindx;
	}
}

/**
 * convt_array - Converting array into a heap in-place
 * @array: array of integer
 * @size: size of the array
 * Return: it is void
 */

void convt_array(int *array, size_t size)
{
	ssize_t strtindx;

	strtindx = parentidx(size - 1);
	while (strtindx >= 0)
	{
		sift_down(array, strtindx, size - 1, size);
		strtindx--;
	}
}

/**
 * heap_sort - Sorting an array of integers with heap sort
 * @array: array of integers
 * @size: size of the array
 * Return: it is void
 */

void heap_sort(int *array, size_t size)
{
	size_t endindx;

	if (array == NULL || size < 2)
		return;
	convt_array(array, size);
	endindx = size - 1;
	while (endindx > 0)
	{
		swap_int_val(array, size, &array[endindx], &array[0]);
		endindx--;
		sift_down(array, 0, endindx, size);
	}
}
