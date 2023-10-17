#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0, i = 0, au, j = 0;
	int flags, width, precision, size;
	char limit[1024];

	if (format == NULL)
		return (-1);

	va_start(args, format);


	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			w_buffer(limit, &j);
			flags = check_flags(format, &i);
			width = check_width(format, &i, args);
			precision = check_precision(format, &i, args);
			size = check_size(format, &i);
			++i;
			au = flag_handler1(format, args, &i, limit, flags, width, precision, size);
/*			au = flag_handler(format, args, &i);*/
			if (au == -1)
				return (-1);
			chars_printed += au;
		}
		else
		{
			limit[j++] = format[i];
			if (j == 1024)
				w_buffer(limit, &j);
			chars_printed++;
/*			write(1, &format[i], 1);*/
/*			put_char(format[i]);*/
		}
	}

/*	chars_printed = handle_format_specifier(format, args, limit, j);*/

	w_buffer(limit, &j);
	va_end(args);
	return (chars_printed);
}
