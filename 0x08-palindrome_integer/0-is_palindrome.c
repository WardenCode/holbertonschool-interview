#include "palindrome.h"

/**
 * get_digits - Compute the quantity of digits of a number
 *
 * @n: number to be computed
 *
 * Return: Cuantity of digits
 */
unsigned int get_digits(unsigned long n)
{
	unsigned int digits = 0;

	while (n != 0)
	{
		n /= 10;
		digits++;
	}

	return (digits);
}

/**
 * is_palindrome - Validate if a number is palindrome
 *
 * @n: mumber to validate
 *
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int sum = 0;
	unsigned int digits = get_digits(n), i = 0;

	for (; n != 0; n /= 10, i++)
	{
		if ((digits % 2) && (i == digits / 2))
			continue;

		if (i >= (digits / 2))
			sum -= n % 10;
		else
			sum += n % 10;
	}

	return (sum == 0);
}
