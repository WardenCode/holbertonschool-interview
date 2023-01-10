#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid.
 * @grid: 3x3 grid.
 *
 * Return: Void
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Check is a sandpile is unstable.
 *
 * @sandpile: Matrix 3x3 that represents a sandpile.
 *
 * Return: 1 if is unstable and 0 otherwise.
 */
char is_unstable(int sandpile[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (sandpile[i][j] > 3)
				return (1);

	return (0);
}

/**
 * only_sum - Sum two sandpiles and saves the sum on the first one.
 *
 * @sandpile1: Matrix 3x3 that represents a sandpile.
 *
 * @sandpile2: Matrix 3x3 that represents a sandpile.
 *
 * Return: Void.
 */
void only_sum(int sandpile1[3][3], int sandpile2[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sandpile1[i][j] += sandpile2[i][j];
}

/**
 * topple - Traverse an unstable sandpile and topples the cells.
 *
 * @sandpile: Matrix 3x3 that represents a sandpile.
 *
 * Return: Void.
 */
void topple(int sandpile[3][3])
{
	int i = 0, j = 0;

	int toppled_sandpile[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (sandpile[i][j] <= 3)
				continue;

			sandpile[i][j] -= 4;

			if (i + 1 < 3)
				toppled_sandpile[i + 1][j] += 1;
			if (i - 1 >= 0)
				toppled_sandpile[i - 1][j] += 1;
			if (j + 1 < 3)
				toppled_sandpile[i][j + 1] += 1;
			if (j - 1 >= 0)
				toppled_sandpile[i][j - 1] += 1;
		}

	only_sum(sandpile, toppled_sandpile);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 *
 * @grid1: Matrix 3x3 that represents a sandpile.
 *
 * @grid2: Matrix 3x3 that represents a sandpile.
 *
 * Return: Void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	only_sum(grid1, grid2);
	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
