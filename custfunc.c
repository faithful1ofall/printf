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
	
	for (;format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			au = flag_handler(format, args, &i);
			if (au == -1)
				return (-1);

			chars_printed += au;
			continue;
		}

		put_char(format[i]);
		chars_printed = chars_printed + 1;
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
