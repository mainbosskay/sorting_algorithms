#include "sort.h"

void cmp_merge(int *array, size_t startidx, size_t stopidx, int *output);
void top_down_rec(int *array, size_t startidx, size_t stopidx, int *output);
void merge_sort(int *array, size_t size);

/**
 * cmp_merge - Compares and merges two halves of an array
 * @array: array of integer
 * @startidx: start index of the array
 * @stopidx: stop index of the array
 * @output: output array
 * Return: it is void
 */

void cmp_merge(int *array, size_t startidx, size_t stopidx, int *output)
{
	size_t k;
	size_t s;
	size_t a;
	size_t midindx;

	k = startidx;
	s = midindx = (startidx + stopidx) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + startidx, midindx - startidx);
	printf("[right]: ");
	print_array(array + midindx, stopidx - midindx);
	for (a = startidx ; a < stopidx ; a++)
	{
		if (k < midindx && (s >= stopidx || array[k] <= array[s]))
		{
			output[a] = array[k++];
		}
		else
		{
			output[a] = array[s++];
		}
	}
	printf("[Done]: ");
	print_array(output + startidx, stopidx - startidx);
}

/**
 * top_down_rec - Sorting array of ints with top-down recursive
 * @array: array of integers
 * @startidx: start index of the array
 * @stopidx: stop index of the array
 * @output: output array
 * Return: it is void
 */

void top_down_rec(int *array, size_t startidx, size_t stopidx, int *output)
{
	size_t midindx;

	midindx = (startidx + stopidx) / 2;
	if (stopidx - startidx < 2)
	{
		return;
	}
	top_down_rec(output, startidx, midindx, array);
	top_down_rec(output, midindx, stopidx, array);
	cmp_merge(output, startidx, stopidx, array);
}

/**
 * merge_sort - Sorting array of ints with merge sort
 * @array: array of intgers
 * @size: size of the array
 * Return: it is void
 */

void merge_sort(int *array, size_t size)
{
	int *newarray;
	size_t k;

	if (array == NULL || size < 2)
		return;
	newarray = malloc(sizeof(int) * size);
	if (newarray == NULL)
		return;
	for (k = 0 ; k < size ; k++)
		newarray[k] = array[k];
	top_down_rec(array, 0, size, newarray);
	free(newarray);
}
