#include "slide_line.h"
/**
 * slide_to_direction - Take a array and slide it to the given direction
 *
 * @line: Pointer to the array
 * @size: Size of the array
 * @direction: Direction to slide/merge
 *
 * Return: void
 */
void slide_to_direction(int *line, int size, int direction)
{
	int to_insert = 0, holder = 0, holder_idx = 0;
	int end = size, i = 0, step = 1;

	if (direction)
	{
		step = -1, to_insert = size - 1;
		i = size - 1, end = -1;
	}

	for (; i != end; i += step)
	{
		if (line[i] == 0)
			continue;

		if (holder == 0)
		{
			holder = line[i], holder_idx = i;

			if ((!direction && (i == size - 1)) || (direction && (i == 0)))
				line[i] = 0, line[to_insert] = holder;

			continue;
		}
		line[holder_idx] = 0;

		if (line[i] == holder)
		{
			line[i] = 0;
			line[to_insert] = holder * 2;
			holder = 0, holder_idx = 0;
		}
		else
		{
			line[to_insert] = holder;
			holder_idx = i, holder = line[i];
			if ((!direction && (i == size - 1)) || (direction && (i == 0)))
				line[i] = 0, line[to_insert + step] = holder;
		}
		to_insert += step;
	}
}

/**
 * slide_line - 2048 game
 *
 * @line: Pointer to an int array
 * @size: Size of line
 * @direction: Direction of the game
 *
 * Return: 1 if successful, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || !(direction >= 0 && direction <= 1) || !size)
		return (0);

	slide_to_direction(line, (int)size, direction);

	return (1);
}
