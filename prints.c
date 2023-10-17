#include "main.h"

/**
 * w_buffer - Save the character in a buffer
 * @lim: Character array
 * @i: the index
 * Return: void
 **/

void w_buffer(char lim[], int *i)
{
	if (*i > 0)
		write(1, &lim[*i], *i);
	*i = 0;
}

/**
 * put_char - Prints the contents if it exist
 * @c: a single character or integer
 * Return: a single character
 */

int put_char(char c)
{
	return (write(1, &c, 1));
/*	return (buffer(c));*/
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
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
 * put_string - Prints a string of characters
 * @str: num of char
 * Return: the characters
 */

int put_string(char *str)
{
	int i = 0;

	while (str[i] != 0)
	{
		put_char(str[i]);
		++i;
	}

	return (i);
}
