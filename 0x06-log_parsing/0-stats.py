#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics:

- Input format:
    <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <size>
    (if the format is not this one, the line must be skipped)

- After every 10 lines and/or a keyboard interruption (CTRL + C),
    print these statistics from the beginning:

    - Total file size: File size: <total size>
    - Where <total size> is the sum of all previous <file size>
        (see input format above)

    - Number of lines by status code:
        - Possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
        - If a status code doesn't appear or is not an integer,
            don't print anything for this status code
        - Format: <status code>: <number>
        - status codes should be printed in ascending order
"""

import re
from sys import stdin


def print_logs(regist, total_size):
    """
    Print logs

    Args:
        regist: Dictionary with the count of the status code
        total_size: Sizes of the file
    """
    print("File size: {:d}".format(total_size))
    for k, v in regist.items():
        if v != 0:
            print("{:s}: {:d}".format(k, v))


def metrics():
    """
    Go through logs and print it
    """
    try:
        REGEX = re.compile((r'(\d{1,3}\.){3}\d{1,3} - '
                            r'\[\d{4}(-\d{2}){2}\ \d{2}(:\d{2}){2}\.\d{6}\] '
                            r'\"GET /projects/260 HTTP/1\.1\" '
                            r'(200|301|400|401|403|404|405|500) '
                            r'(\d{1,})'))
        regist = {
            '200': 0, '301': 0, '400': 0, '401': 0,
            '403': 0, '404': 0, '405': 0, '500': 0,
        }
        total_size = 0
        quantity = 0

        for line in stdin:
            regex_result = re.search(REGEX, line)

            if (regex_result):
                groups = regex_result.groups()
                regist[groups[-2]] += 1
                total_size += int(groups[-1])
                quantity += 1

                if (quantity % 10 == 0):
                    print_logs(regist, total_size)

    except KeyboardInterrupt as Error:
        print_logs(regist, total_size)


if (__name__ == '__main__'):
    metrics()
