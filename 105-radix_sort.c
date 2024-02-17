#include "sort.h"

int retr_digit(long n, int index);
int radix_pass(int *array, ssize_t size, int index, int *arraysrt);
void radix_sort(int *array, size_t size);

/**
 * retr_digit - Retrieving digit from given number specific index
 * @n: number to retrieve digit
 * @index: index of the digit to retrieve
 * Return: value of the digit
 */

int retr_digit(long n, int index)
{
	long k = 0L;
	long postmul = 1L;
	long digvalue;

	for (k = 0 ; k < index ; k++)
		postmul *= 10L;
	digvalue = ((n / postmul) % 10);
	return (digvalue);
}

/**
 * radix_pass - Executing single pass of LSD radix sort on an array
 * @array: array of integers
 * @size: size of the array
 * @index: index of the digit
 * @arraysrt: target array of the same size
 * Return: it will be 1 on code success
 */

int radix_pass(int *array, ssize_t size, int index, int *arraysrt)
{
	ssize_t s;
	int digitcnt[10] = {0};

	for (s = 0 ; s < size ; s++)
		digitcnt[retr_digit(array[s], index)]++;
	for (s = 1 ; s <= 9 ; s++)
		digitcnt[s] += digitcnt[s - 1];
	for (s = size - 1 ; s > -1 ; s--)
		arraysrt[digitcnt[retr_digit(array[s], index)]-- - 1] = array[s];
	return (1);
}

/**
 * radix_sort - Sorting array of integers with radix sort
 * @array: array of integers to be sorted
 * @size: size of the array
 * Return: it is void
 */

void radix_sort(int *array, size_t size)
{
	int *orarray;
	int *arraysrt;
	int *temptr;
	int *potr;
	int maxvalue = 0;
	size_t indx;
	size_t digitcnt = 1;

	if (array == NULL || size < 2)
		return;
	for (indx = 0 ; indx < size ; indx++)
		if (array[indx] > maxvalue)
			maxvalue = array[indx];
	while (maxvalue /= 10)
		digitcnt++;
	orarray = array;
	arraysrt = potr = malloc(sizeof(int) * size);
	if (arraysrt == NULL)
		return;
	for (indx = 0 ; indx < digitcnt ; indx++)
	{
		radix_pass(orarray, (ssize_t)size, indx, arraysrt);
		temptr = orarray;
		orarray = arraysrt;
		arraysrt = temptr;
		print_array(orarray, size);
	}
	for (indx = 0 ; indx < size ; indx++)
		array[indx] = orarray[indx];
	free(potr);
}
