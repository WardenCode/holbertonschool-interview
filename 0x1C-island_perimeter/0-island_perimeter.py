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
    if grid is None or type(grid) is not list or grid == []:
        return 0
    perimeter = 0
    max_row = len(grid)
    max_column = len(grid[0])
    for i in range(max_row):
        for j in range(max_column):
            if grid[i][j] == 1:
                if i + 1 == max_row:
                    perimeter += 1
                if j + 1 == max_column:
                    perimeter += 1
                if i == 0:
                    perimeter += 1
                if j == 0:
                    perimeter += 1
                continue
            if i > 0 and grid[i - 1][j] == 1:
                perimeter += 1
            if j > 0 and grid[i][j - 1] == 1:
                perimeter += 1
            if j + 1 != max_column and grid[i][j + 1] == 1:
                perimeter += 1
            if i + 1 != max_row and grid[i + 1][j] == 1:
                perimeter += 1
    return perimeter


# def island_perimeter(grid):
#     """
#     Get the island perimeter in a ocean grid

#     Args:
#         grid (list[list[int]]): Matrix with the water an earth surface

#     Returns:
#         int: Perimeter of the earth surface
#     """
#     perimeter = 0
#     grid_length = len(grid)

#     for y in range(0, grid_length):
#         for x in range(0, grid_length):
#             tmp = 4

#             if (grid[y][x] == 0):
#                 continue

#             if (((x + 1) < grid_length) and (grid[y][x + 1] == 1)):
#                 tmp -= 1

#             if (((x - 1) >= 0) and (grid[y][x - 1] == 1)):
#                 tmp -= 1

#             if (((y + 1) < grid_length) and (grid[y + 1][x] == 1)):
#                 tmp -= 1

#             if (((y - 1) >= 0) and (grid[y - 1][x] == 1)):
#                 tmp -= 1

#             perimeter += tmp

#     return perimeter
