#include "sort.h"
#include <stdio.h>

/**
 * print_array_with_range - Print a part of the array
 *
 * @array: Array to print
 *
 * @start: Start index of array
 *
 * @right: End index of array
 *
 * Return: Nothing
 */
void print_array_with_range(int *array, int start, int end)
{
	int i = 0;

	if (!array)
		return;

	for (i = start; i < end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
	}
	putchar('\n');
}

/**
 * copy_array - copy an array to another
 *
 * @src: Source array
 *
 * @start: Array index to start copying
 *
 * @end: Array index to end copying
 *
 * @dest: Destination array
 *
 * Return: Void
 */
void copy_array(int *src, size_t start, size_t end, int *dest)
{
	for (; src && dest && start < end; start++)
		dest[start] = src[start];
}

/**
 * top_down_merge - Top down merge method
 *
 * @A: Primary Array
 *
 * @start: Array index to start
 *
 * @mid: Array index to middle
 *
 * @end: Array index to end
 *
 * @B: Secondary Array
 *
 * Return: Void
 */
void top_down_merge(int *A, size_t start, size_t mid, size_t end, int *B)
{
	size_t i = start, j = mid, k = start;

	if (!A || !B)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_with_range(A, start, mid);
	printf("[right]: ");
	print_array_with_range(A, mid, end);

	for (; k < end; k++)
	{
		if (i < mid && (j >= end || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array_with_range(B, start, end);
}

/**
 * top_down_split_merge -Top down split method
 *
 * @B: Secondary Array
 *
 * @start: Array index to start
 *
 * @end: Array index to end
 *
 * @A: Primary Array
 *
 * Return: Void
 */
void top_down_split_merge(int *B, size_t start, size_t end, int *A)
{
	size_t mid = (start + end) / 2;

	if (!A || !B || (end - start) <= 1)
		return;

	top_down_split_merge(A, start, mid, B);
	top_down_split_merge(A, mid, end, B);

	top_down_merge(B, start, mid, end, A);
}

/**
 * merge_sort - Merge and sort two arrays
 *
 * @array: Int pointer to the array
 *
 * @size: Size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *array2 = NULL;

	if (!array || size < 2)
		return;

	array2 = malloc(sizeof(int) * size);
	if (!array2)
		return;

	copy_array(array, 0, size, array2);
	top_down_split_merge(array2, 0, size, array);
	free(array2);
}
