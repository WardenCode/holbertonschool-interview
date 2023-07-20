#include "sort.h"

#define MAX_SIZE 5000

/**
 * get_max - Get the maximum value of the int array
 *
 * @array: Int pointer to the array
 * @size: Array size
 *
 * Return: max value of the int array
 */
int get_max(int *array, size_t size)
{
	size_t i = 0;
	int max = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_sort - Realize the count sort algorithm for a given array
 *
 * @array: Int pointer to an array
 * @size: Size of the array
 * @exp: Exponent to get a specific digit of a number
 *
 * Return: Void
 */
void count_sort(int *array, int size, int exp)
{
	int i = 0, output[MAX_SIZE], count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *
 * @array: Pointer to array of integers
 * @size: Size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	size_t exp = 1;
	int max = 0;

	if (size < 2 || !array)
		return;

	max = get_max(array, size);

	for (; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
