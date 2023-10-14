#include <unistd.h>
#include "main.h"

/**
 * put_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single character
 */

int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single chracter
 */

int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
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

/**
 * put_string - Prints a string of characters
 * @str: num of char
 * Return: the characters
 */

int put_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		put_char(str[i]);

	return (i);
}
