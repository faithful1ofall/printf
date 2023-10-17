#include "main.h"

/**
 * handle_format_specifier - Format controller
 * @format: String format
 * @args: List of arguments
 * Return: Total size of arguments with the total size of the base string
 **/
int handle_format_specifier(const char *format, va_list args)
{
	int chars_printed = 0, i = 0, au;
	int flags, width, precision, size;

	for (; format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			flags = check_flags(format, &i);
			width = check_width(format, &i, args);
			precision = check_precision(format, &i, args);
			size = check_size(format, &i);
			w_buffer(-1);
			au = flag_handler(format, args, &i);
			if (au == -1)
			{
				au = flag_handler1(format, args, &i, flags,
						width, precision, size);
				if (au == -1)
					return (-1);
			}

			chars_printed += au;
			continue;
		}
		else
		{
			w_buffer(format[i]);
/*			put_char(format[i]);*/
		}
		chars_printed++;
	}
	return (chars_printed);
}

/**
 * itac - integer to ascii
 * @num: num
 * @base: base
 * Return: char
 **/
char *itac(long int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
