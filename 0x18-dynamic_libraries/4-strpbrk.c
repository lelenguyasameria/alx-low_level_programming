#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to search.
 * @accept: The set of bytes to search for.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
char *ptr1, *ptr2;
for (ptr1 = s; *ptr1 != '\0'; ptr1++)
{
for (ptr2 = accept; *ptr2 != '\0'; ptr2++)
{
if (*ptr1 == *ptr2)
{
return (ptr1);
}
}
}
return (NULL);
}
