#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The integer value of the string, or 0 if no number was found
 */
int _atoi(char *s)
{
int result = 0;
int sign = 1;
int digit;
while (*s != '\0')
{
if (*s == '-')
sign = -1;
else if (*s == '+')
sign = 1;
else if (*s >= '0' && *s <= '9')
{
digit = *s - '0';
result = result * 10 + digit;
}
else if (result > 0)
{
/*
* We've found a non-digit after finding at least one digit,
* so we can stop parsing the string
*/
break;
}
s++;
}
return (sign *result);
}
