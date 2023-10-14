#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * num_length - Prints the length of a number
 * @num: the integer
 * Return: length of integer
 */

int num_length(long int num)
{
	int length = 1;

	if (num < 0)
	{
		length++;
		num = -num;
	}
	while (num >= 10)
	{
		length++;
		num /= 10;
	}
	return (length);
}

/**
 * int_to_str - Prints the contents
 * @str: Array of chars
 * @num: the number.
 */

void int_to_str(char *str, long int num)
{
	int i = 0, length, j;

	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}

	length = num_length(num);

	for (j = length - 1; j >= 0; j--)
	{
		str[i + j] = '0' + (num % 10);
		num /= 10;
	}
}

/**
 * print_integer - Prints the contents of the number
 * @num: Array of numbers
 * Return: the number as string
 */

int print_integer(long int num)
{
	char num_str[20];
	int length;

	int_to_str(num_str, num);
	length = num_length(num);
	return (write(1, num_str, length));
}

/**
 * handle_format_specifier - format handler
 * @format: format specifier
 * @args: argument to pick
 * Return: characters to print
 */

int handle_format_specifier(char format, va_list args)
{
	int chars_printed = 0;

	switch (format)
	{
		case 'c':
			chars_printed += print_char(va_arg(args, int));
			break;
		case 's':
			chars_printed += print_string(va_arg(args, char *));
			break;
		case '%':
			chars_printed += print_char('%');
			break;
		case 'd':
			chars_printed += print_integer(va_arg(args, long int));
			break;
		case 'i':
			chars_printed += print_integer(va_arg(args, long int));
			break;
		default:
			return (-1);
	}

	return (chars_printed);
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;

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
