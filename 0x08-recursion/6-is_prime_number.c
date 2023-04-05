#include "main.h"
#include <math.h>

int is_prime_helper(int n, int divisor);

/**
 * is_prime_number - checks if a number is prime
 *
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
if (n < 2)
return (0);
return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - helper function for is_prime_number
 *
 * @n: the number to check
 * @divisor: the current divisor to test
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
if (n % divisor == 0)
return (0);
if (divisor * divisor > n)
return (1);
return (is_prime_helper(n, divisor + 1));
}
