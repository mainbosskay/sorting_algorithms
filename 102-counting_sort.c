#include "sort.h"

int countint(int *array, size_t size, int goal);
void counting_sort(int *array, size_t size);

/**
 * countint - Counting number of times a specific int occurs
 * @array: array of integers
 * @size: size of the array
 * @goal: integer to count
 * Return: number of occurences
 */

int countint(int *array, size_t size, int goal)
{
	int instances;
	size_t k;

	instances = 0;
	for (k = 0 ; k < size ; k++)
	{
		if (array[k] == goal)
			instances++;
	}
	return (instances);
}

/**
 * counting_sort - Sorting array of ints with counting sort
 * @array: array of integers
 * @size: size of the array
 * Return: it is void
 */

void counting_sort(int *array, size_t size)
{
	int k = 0;
	int cmsum = 0;
	int goal = 0;
	int *arraysum;
	int *arraysrt;
	size_t s;
	size_t sum;

	if (array == NULL || size < 2)
		return;
	for (s = 0 ; s < size ; s++)
	{
		if (array[s] > k)
		{
			k = array[s];
		}
	}
	arraysum = malloc(sizeof(int) * (k + 1));
	if (arraysum == NULL)
		return;
	for (sum = 0 ; sum < ((size_t)k + 1) ; sum++)
	{
		if (sum == 0)
			arraysum[sum] = countint(array, size, goal);
		else
		{
			cmsum = arraysum[sum - 1] + countint(array, size, goal);
			arraysum[sum] = cmsum;
		}
		goal++;
	}
	print_array(arraysum, (k + 1));
	arraysrt = malloc(sizeof(int) * size);
	if (arraysrt == NULL)
	{
		free(arraysum);
		return;
	}
	for (s = 0 ; s < size ; s++)
		arraysrt[arraysum[array[s]]-- - 1] = array[s];
	for (s = 0 ; s < size ; s++)
		array[s] = arraysrt[s];
	free(arraysrt);
	free(arraysum);
}
