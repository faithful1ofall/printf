#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single character
 */

int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int strcount = 0;

	while (s[strcount] != '\0')
	{
		strcount++;
	}

	return (strcount);
}

/**
 * print_string - Prints a string of characters
 * @str: Array of chars
 * Return: the characters
 */

int print_string(char *str)
{
	int chars_printed = 0;

	while (*str != '\0')
	{
		chars_printed += write(1, str, 1);
		str++;
	}
	return (chars_printed);
}
