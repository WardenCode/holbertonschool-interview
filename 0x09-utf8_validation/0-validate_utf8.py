#!/usr/bin/python3
"""
Validate utf-8 module
"""


def validUTF8(data):
    """
    Determines if the data set represents a valid UTF-8 encoding.

    Args:
        data (list[int]): List to validate if is UTF-8 valid
    Returns:
        bool: True if data is a valid UTF-8 encoding,
        else return False
    """
    count = 0

    for num in data:
        # if num is in the area of a subsequent byte
        if 128 <= num <= 191:

            # If there not a previous number bigger than 127
            # And the actual number is bigger than 127
            # Return False
            if not count:
                return False

            # One subsequent byte less
            count -= 1
        else:
            # One byte
            if num < 128:
                continue
            # Two bytes
            elif num < 224:
                count = 1
            # Three bytes
            elif num < 240:
                count = 2
            # Four bytes
            elif num < 248:
                count = 3
            # Five to more bytes (invalid)
            else:
                return False

    return True
