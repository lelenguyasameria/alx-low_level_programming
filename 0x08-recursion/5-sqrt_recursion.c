#include "main.h"
#include "math.h"

int sqrt_helper(int n, int start, int end);

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: the number to find the square root of
 *
 * Return: the natural square root of n, or -1 if n does not have a natural
 * square root
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
if (n == 0 || n == 1)
return (n);
return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - helper function for _sqrt_recursion
 *
 * @n: the number to find the square root of
 * @start: the starting value to search from
 * @end: the ending value to search to
 *
 * Return: the natural square root of n, or -1 if n does not have a natural
 * square root
 */
int sqrt_helper(int n, int start, int end)
{
int mid = (start + end) / 2;
if (mid * mid == n)
return (mid);
if (start >= end)
return (-1);
if (mid * mid > n)
return (sqrt_helper(n, start, mid - 1));
else
return (sqrt_helper(n, mid + 1, end));
}
