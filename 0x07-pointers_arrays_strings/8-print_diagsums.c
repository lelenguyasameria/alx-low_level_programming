#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 *                  of integers.
 * @a: pointer to the first element of the matrix
 * @size: size of the square matrix
 *
 * Description: This function prints the sum of the two diagonals of a
 *              square matrix of integers, where the diagonal from the
 *              top-left to the bottom-right is considered the "primary"
 *              diagonal, and the diagonal from the top-right to the
 *              bottom-left is considered the "secondary" diagonal.
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
int row, col;
int primary_sum = 0, secondary_sum = 0;
for (row = 0; row < size; row++)
{
for (col = 0; col < size; col++)
{
if (row == col)
primary_sum += *(a + row * size + col);
if (row + col == size - 1)
secondary_sum += *(a + row * size + col);
}
}
printf("%d, %d\n", primary_sum, secondary_sum);
}
