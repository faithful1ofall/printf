#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed;
/*	int len = _strlen(format);*/

/*	if (format == NULL)*/
/*		return (-1);*/

/*	len = _strlen(format);*/
/*	if (len <= 0)*/
/*		return (0);*/

	va_start(args, format);

	chars_printed = handle_format_specifier(format, args);

/*	put_char(-1);*/
	va_end(args);
	return (chars_printed);
}
