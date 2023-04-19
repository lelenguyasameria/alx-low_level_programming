#include <stdio.h>
#include <stdlib.h>

#define MAX_BYTES 1000

/**
 * main - prints the opcodes of its own main function
 *
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments passed to the program
 *
 * Return: 0 if successful, 1 if incorrect number of arguments, 2 if negative number of bytes
 */
int main(int argc, char *argv[])
{
int i, num_bytes;
if (argc != 2)
{
printf("Error\n");
return (1);
}
num_bytes = atoi(argv[1]);
if (num_bytes < 0)
{
printf("Error\n");
return (2);
}
char *ptr = (char *)main;
for (i = 0; i < num_bytes && i < MAX_BYTES; i++)
{
printf("%02x", ptr[i] & 0xff);
}
printf("\n");

return (0);
}
