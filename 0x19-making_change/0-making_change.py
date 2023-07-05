#!/usr/bin/python3

def makeChange(coins, total):
    """
    Determine the fewest number of coins needed
    to meet a given amount total

    Args:
        coins (list[int]): List of coins to use
        total (int): Total amount to reach with the coins or -1
        if is impossible to reach the amount with the coins

    Returns:
        int: Less quantity of coins needed to reach a given amount
    """
    if (total <= 0):
        return 0

    sortedCoins = sorted(coins, reverse=True)
    coinsQuantity = 0
    i = 0

    while (i < len(sortedCoins)):
        if (total - sortedCoins[i] >= 0):
            total -= sortedCoins[i]
            i -= 1
            coinsQuantity += 1
        i += 1

    if (total == 0):
        return coinsQuantity

    return -1
