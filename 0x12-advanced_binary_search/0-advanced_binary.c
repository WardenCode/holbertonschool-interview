#include "search_algos.h"
/**
 * print_array - Print an array
 *
 * @array: Int pointer to an array
 * @size: Size of the array
 * @start: Index of the first element to print
 * @end: Index of the last element to print
 *
 * Return: void
 */
void print_array(int *array, size_t start, size_t end)
{
	if (!array || end == 0)
		return;

	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		printf("%d", array[start]);
		if (start != end)
			printf(", ");
	}
	putchar('\n');
}

/**
 * binary_search - Recursive binary search
 *
 * @array: Int pointer to the array
 * @start: Index of the first element
 * @end: Index of the last element
 * @value: Value to search
 *
 * Return: Index of the first occurrence or -1 if no such occurrence
*/
int binary_search(int *array, size_t start, size_t end, int value)
{
	int middle = (start + end) / 2;


	print_array(array, start, end);

	if (start == end)
		return (-1);

	if ((start > end) && (value == array[start]))
		return (start);

	if ((array[middle] == value) && ((start + 1) == end))
		return (middle);

	if (array[middle] >= value)
		return (binary_search(array, start, middle, value));

	if (array[middle] < value)
		return (binary_search(array, middle + 1, end, value));

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 *
 * @array: Pointer to an array of integers
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: The index where value is located or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
