#include "main.h"

/**
 * print_string - Prints a string of characters
 * @args: a list of arguments
 * Return: the characters
 */

int print_string(va_list args)
{
	char *str;
	int chars_printed, len;

	str = va_arg(args, char *);

	len = _strlen(str);

	if (str == NULL)
	{
		str = "(null)";
	}
/*	chars_printed = put_string(str);*/
	chars_printed = write(1, str, len);
	return (chars_printed);
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
