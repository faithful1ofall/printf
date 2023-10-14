#include <stdlib.h>
#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0, len;

	if (format == NULL)
		return (-1);

	len = _strlen(format);
	if (len <= 0)
		return (0);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			chars_printed += print_char(*format);
		}
		else
		{
			format++;
			chars_printed += handle_format_specifier(*format, args);
		}
		format++;
	}

	va_end(args);
	return (chars_printed);
}
