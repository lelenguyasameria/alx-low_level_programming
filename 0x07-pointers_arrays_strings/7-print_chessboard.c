#include "main.h"

/**
 * print_chessboard - prints the chessboard.
 *
 * @a: pointer to an array of 8 arrays, each of which contains 8 characters.
 *
 * Description: This function prints the chessboard on the standard output
 *              character by character, row by row.
 *
 * Return: void.
 */
void print_chessboard(char (*a)[8])
{
int row, col;

for (row = 0; row < 8; row++)
{
for (col = 0; col < 8; col++)
{
_putchar(a[row][col]);
}
_putchar('\n');
}
}
