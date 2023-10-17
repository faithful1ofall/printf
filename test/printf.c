#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int chars_printed = 0, i, au = 0, j = 0;
	int flags, width, precision, size;
	va_list args;
	char limit[1024];

	if (format == NULL)
		return (-1);

	va_start(args, format);


	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			limit[j++] = format[i];
			if (j == 1024)
				w_buffer(limit, &j);
			chars_printed++;
		}
		else
		{
			w_buffer(limit, &j);
			flags = check_flags(format, &i);
			width = check_width(format, &i, args);
			precision = check_precision(format, &i, args);
			size = check_size(format, &i);
			au = flag_handler1(format, args, &i, limit, flags, width, precision, size);
/*			au = flag_handler(format, args, &i);*/
			if (au == -1)
				return (-1);
			chars_printed += au;
/*			write(1, &format[i], 1);*/
/*			put_char(format[i]);*/
		}
	}

/*	chars_printed = handle_format_specifier(format, args, limit, j);*/

	w_buffer(limit, &j);
	va_end(args);
	return (chars_printed);
}
