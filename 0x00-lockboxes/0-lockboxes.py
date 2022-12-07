#!/usr/bin/python3
"""
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""

from typing import List

Box = List[int]
Boxes = List[Box]

def canUnlockAll(boxes: Boxes) -> bool:
    """
    Compute the boxes and verify if all can be unlocked.

    Keyword arguments:
    boxes: list[list[int]] each element is a box that contains natural numbers that represents a key, to open other boxes.

    Return: True if all the boxes can be unlocked False otherwise
    """

    number_boxes: int = len(boxes)
    unlocked_all: bool = False

    if (not number_boxes or not len(boxes[0])):
        return (False)

    keys: List[int] = [*boxes[0]]

    for key in keys:
        for i in range(0, len(boxes[key])):
            actual_key = boxes[key][i]
            if (actual_key not in keys and actual_key <= number_boxes - 1 and actual_key):
                keys.append(boxes[key][i])

    if (len(keys) == number_boxes - 1):
            unlocked_all = True

    return (unlocked_all)
