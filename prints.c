#include <unistd.h>
#include "main.h"

/**
 * buffer - Save the character in a buffer
 * @c: Character
 *
 * Return: 1
 **/
int buffer(char c)
{
	static char buffering[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write(1, buffering, i);
		i = 0;
	}

	if (c != -1)
		buffering[i++] = c;

	return (1);
}

/**
 * put_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single character
 */

int put_char(char c)
{
	return (buffer(c));
}

/**
 * print_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single chracter
 */

int print_char(int c)
{
	put_char(c);
	return (1);
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

	chars_printed = put_string((str != NULL) ? str : "(null)");

	return (chars_printed);
}

/**
 * put_string - Prints a string of characters
 * @str: num of char
 * Return: the characters
 */

int put_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		put_char(str[i]);
		i++;
	}
	return (i);
}
