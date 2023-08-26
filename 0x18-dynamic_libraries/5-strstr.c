#include "main.h"
#include <stddef.h>

/**
 * _strstr - finds the first occurrence of the substring needle in the
 *           string haystack.
 * @haystack: the string to search in.
 * @needle: the substring to search for.
 *
 * Return: pointer to the beginning of the located substring or NULL if not
 *         found.
 */

char *_strstr(char *haystack, char *needle)
{
int i, j, k;

for (i = 0; haystack[i] != '\0'; i++)
{
j = i;
k = 0;

while (needle[k] != '\0' && haystack[j] == needle[k])
{
j++;
k++;
}

if (needle[k] == '\0')
return (haystack + i);
}

return (NULL);
}
