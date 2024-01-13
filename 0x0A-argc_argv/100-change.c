#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    int cents, num_coins, count, i;

    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    cents = atoi(argv[1]);

    if (cents < 0)
    {
        printf("0\n");
        return 0;
    }

    int coins[] = {25, 10, 5, 2, 1};
    num_coins = sizeof(coins) / sizeof(coins[0]);
    count = 0;

    for (i = 0; i < num_coins; i++)
    {
        while (cents >= coins[i])
        {
            cents -= coins[i];
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

