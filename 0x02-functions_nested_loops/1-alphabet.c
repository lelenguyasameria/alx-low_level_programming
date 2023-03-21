#include <stdio.h> // add this header file

/**
 * _putchar - Writes a character to stdout.
 *
 * @c: The character to be written.
 *
 * Return: 1 on success or -1 on error.
 */
int _putchar(char c) // add the function prototype
{
return putchar(c);
}

/**
 * print_alphabet - Prints the English alphabet in lowercase.
 */
void print_alphabet(void)
{
char letter = 'a';

while (letter <= 'z')
{
_putchar(letter);
letter++;
}

_putchar('\n');
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
print_alphabet();
return (0);
}
