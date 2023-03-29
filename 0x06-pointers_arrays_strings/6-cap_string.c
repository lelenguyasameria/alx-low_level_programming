#include "main.h"
#include <string.h>
#include <ctype.h>

/**
 * cap_string - Capitalizes all words in a string.
 * @str: The string to be modified.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
int len = strlen(str);
int i;
int cap_next = 1;
for (i = 0; i < len; i++)
{
if (cap_next && isalpha(str[i]))
{
str[i] = toupper(str[i]);
cap_next = 0;
}
else if (strchr(" \t\n,;.!?\"(){}", str[i]))
{
cap_next = 1;
}
else
{
cap_next = 0;
}
}
return (str);
}
