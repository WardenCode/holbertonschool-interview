#!/usr/bin/python3
"""
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """
    Compute the boxes and verify if all can be unlocked.

    Keyword arguments:
    boxes: list[list[int]] each element is a box that contains
    natural numbers that represents a key, to open other boxes.

    Return: True if all the boxes can be unlocked False otherwise
    """

    number_boxes = len(boxes)
    unlocked_all = False

    if (not number_boxes or not len(boxes[0])):
        return (False)

    keys = [*boxes[0]]

    for key in keys:
        for i in range(0, len(boxes[key])):
            curr_key = boxes[key][i]
            if (curr_key and curr_key < number_boxes and curr_key not in keys):
                keys.append(boxes[key][i])

    if (len(keys) == number_boxes - 1):
        unlocked_all = True

    return (unlocked_all)
