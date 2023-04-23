#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls
with unit width 1, as if viewing the cross-section of a relief map,
calculate how many square units of water will be retained after it rains.
"""


def trim_int_list(collection: list) -> tuple:
    """
    Get the indexes of the first and the last elements of the list
    with value

    Args:
        collection (List[int]): List of natural integers

    Returns:
        Tuple[int, int]: Index of the first and last element with value
    """
    start: int = 0
    end: int = len(collection) - 1

    for i in range(len(collection)):
        if (collection[i] != 0):
            start = i
            break

    for i in range(len(collection) - 1, 0, -1):
        if (collection[i] != 0):
            end = i
            break

    return (start, end)


def rain(walls: list) -> int:
    """
    Retrieve the mount of water units retained

    Args:
        walls (List[int]): List of integers representing the heights of walls

    Returns:
        int: Total amount of rainwater retained.
    """
    rainwater_amount: int = 0
    left: dict = {
        "value": 0,
        "index": 0
    }
    right: dict = {
        "value": 0,
        "index": len(walls) - 1
    }
    step: int = 1

    if len(walls) < 3:
        return 0

    (start, end) = trim_int_list(walls)

    left["index"] = start
    left["value"] = walls[start]
    right["index"] = end
    right["value"] = walls[end]

    if walls[start] > walls[end]:
        step = -1
        start, end = end - 1, start
    else:
        start += 1

    for i in range(start, end, step):
        wall = walls[i]
        water_level = min(left["value"], right["value"])

        if water_level > wall:
            rainwater_amount += water_level - wall

        if start < end:
            left["index"] = i
            left["value"] = wall

        if start > end:
            right["index"] = i
            right["value"] = wall

    return rainwater_amount
