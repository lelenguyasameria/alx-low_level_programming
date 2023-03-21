#include <unistd.h>

/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line
 **/
void print_alphabet(void)
{
char letter = 'a';

while (letter <= 'z')
{
write(1, &letter, 1);
letter++;
}

write(1, "\n", 1);
}

/**
 * main - calls the print_alphabet function
 * Return: 0 if successful
 **/
int main(void)
{
print_alphabet();
return (0);
}
