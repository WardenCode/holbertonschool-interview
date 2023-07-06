#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed
    to meet a given amount total

    Args:
        coins (list[int]): List of coins to use
        total (int): Total amount to reach with the coins or -1
        if it's impossible to reach the amount with the coins

    Returns:
        int: The minimum number of coins needed to reach the given amount
    """
    if total <= 0:
        return 0

    # Crear una lista para almacenar los resultados intermedios
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    if dp[total] == float('inf'):
        return -1

    return dp[total]
