#include "main.h"

/**
 * buffer - Save the character in a buffer
 * @a: Character
 * Return: 1
 **/

int buffer(char a)
{
	static char buffering[1024];
	static int i;

	if (a == -1 || i == 1024)
	{
		write(1, buffering, i);
		i = 0;
	}

	if (a != -1)
		buffering[i++] = a;

	return (1);
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
		i++;
	}

	return (i);
}
