#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This function encodes a given string into 1337 by replacing certain
 * characters with digits.
 *
 * @param str The input string to encode.
 * @return A new string that represents the encoded input string.
 */
char* leet(char* str)
{
int len = strlen(str);
char* encoded = malloc(len + 1);
int i;
for (i = 0; i < len; i++)
{
char c = str[i];
if (c == 'a' || c == 'A')
{
encoded[i] = '4';
} else if (c == 'e' || c == 'E')
{
encoded[i] = '3';
}
else if (c == 'o' || c == 'O')
{
encoded[i] = '0';
}
else if (c == 't' || c == 'T')
{
encoded[i] = '7';
}
else if (c == 'l' || c == 'L')
{
encoded[i] = '1';
}
else
{
encoded[i] = c;
}
}
encoded[len] = '\0';
return (encoded);
}

/*
 * This is a sample main function that demonstrates how to use the leet() function.
 * It takes a single command line argument, which is the string to encode, and prints
 * the encoded string to the console.
 */
int main(int argc, char* argv[])
{
if (argc != 2) {
printf("Usage: %s <string>\n", argv[0]);
return (1);
}
char* encoded;
encoded = leet(argv[1]);
printf("%s\n", encoded);
free(encoded);
return (0);
}
