#include "main.h"

/**
 * print_string - Prints a string of characters
 * @args: a list of arguments
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: the characters
 */

int print_string(va_list args, int flags, int width, int precision, int size)
{
	char *str;
	int chars_printed;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	str = va_arg(args, char *);

/*	len = _strlen(str);*/

	if (str == NULL)
	{
		str = "(null)";

		return (write(1, str, 6));
	}
	else
	{
/*		chars_printed = put_string(str);*/
		chars_printed = write(1, str, _strlen(str));
		return (chars_printed);
	}
}

/**
 * print_char - Prints the contents of the buffer if it exist
 * @args: a list or arguments
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: a single chracter
 */

int print_char(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	char f = va_arg(args, int), b[1024];

	return (write_c(b, f, flags, width, precision, size));
}
