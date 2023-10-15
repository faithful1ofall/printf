#include "main.h"

/**
 * put_char - Prints the contents if it exist
 * @c: a single character or integer
 * Return: a single character
 */

int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints the contents of the buffer if it exist
 * @args: a list or arguments 
 * Return: a single chracter
 */

int print_char(va_list args)
{
	put_char(va_arg(args, int));
	return (1);
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
 * print_string - Prints a string of characters
 * @args: a list of arguments 
 * Return: the characters
 */

int print_string(va_list args)
{
	char *str;
	int chars_printed;

	str = va_arg(args, char*);

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
		++i;
	}
	return (i);
}
