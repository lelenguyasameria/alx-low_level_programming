#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * rot13 - Encodes a string using the rot13 encryption.
 *
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
char *result = (char *) malloc(strlen(str) + 1);
char *src = str;
char *dst = result;
while (*src)
{
if ((*src >= 'A' && *src <= 'M') || (*src >= 'a' && *src <= 'm'))
{
*dst = *src + 13;
}
else if ((*src >= 'N' && *src <= 'Z') || (*src >= 'n' && *src <= 'z'))
{
*dst = *src - 13;
}
else
{
*dst = *src;
}
src++;
dst++;
}
*dst = '\0';
return (result);
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
char *encoded_string = rot13("Hello, World!");
printf("%s\n", encoded_string);
free(encoded_string);
return (0);
}
