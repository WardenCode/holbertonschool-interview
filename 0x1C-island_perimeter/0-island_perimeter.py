#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    Get the island perimeter in a ocean grid

    Args:
        grid (list[list[int]]): Matrix with the water an earth surface

    Returns:
        int: Perimeter of the earth surface
    """
    perimeter = 0

    for y in range(0, len(grid)):
        for x in range(0, len(grid)):
            tmp = 4

            if (grid[y][x] == 0):
                continue

            if (((x + 1) < len(grid)) and (grid[y][x + 1] == 1)):
                tmp -= 1

            if (((x - 1) >= 0) and (grid[y][x - 1] == 1)):
                tmp -= 1

            if (((y + 1) < len(grid)) and (grid[y + 1][x] == 1)):
                tmp -= 1

            if (((y - 1) >= 0) and (grid[y - 1][x] == 1)):
                tmp -= 1

            perimeter += tmp

    return perimeter
