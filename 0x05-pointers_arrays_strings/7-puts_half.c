#include "main.h"
#include <stdio.h>

/**
 * puts_half - prints half of a string
 * @str: input string
 *
 * Return: void
 */
void puts_half(char *str)
{
int len = 0;
int start;

while (*(str + len) != '\0')
len++;

start = len % 2 == 0 ? len / 2 : (len + 1) / 2;

while (*(str + start) != '\0')
{
putchar(*(str + start));
start++;
}
putchar('\n');
}
