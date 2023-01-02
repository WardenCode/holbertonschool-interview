#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file: Copy All and Paste.
Given a number n, write a method that calculates the fewest number of operations needed
to result in exactly n H characters in the file.

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0

Example:

    n = 9

    H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

    Number of operations: 6

"""


def getPrimeFactors(n):
    """Get the prime factors of a number

    Args:
        n (int): Number to get prime factors

    Returns:
        List[int]: Return a list of the prime factors
    """

    i = 2
    prime_factors = []
    while (i * i <= n):
        if (n % i == 0):
            prime_factors.append(i)
            n //= i
        else:
            i += 1

    if (n > 1):
        prime_factors.append(n)

    return (prime_factors)


def minOperations(n):
    """Find the minimum quantity of operations to get 'n' times 'H' on a file
    with only 'Copy All' and 'Paste' operations

    Args:
        n (int): Number of 'H'

    Returns:
        int: Quantity of operations to get 'n' times 'H' on a file
    """
    operations_number = 0

    if (n <= 1):
        return (operations_number)

    for i in getPrimeFactors(n):
        operations_number += i

    return (operations_number)
