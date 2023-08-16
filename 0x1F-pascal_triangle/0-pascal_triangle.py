#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers
    representing the Pascal's triangle

    Args:
        n (int): number of rows of the triangle

    Returns:
        list[int]: list  of integers
        representing a Pascal's triangle

    Yields:
        list[int]: List of integers representing
        the actual level of the Pascal's triangle
    """
    if n <= 0:
        return []

    prev_row = []
    for i in range(n):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = prev_row[j - 1] + prev_row[j]
        yield row
        prev_row = row
