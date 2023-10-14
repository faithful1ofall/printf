#include "main.h"

/**
 * num_length - Prints the length of a number
 * @num: the integer
 * Return: length of integer
 */

int num_length(int num)
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

void int_to_str(char *str, int num)
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
			chars_printed += print_integer(va_arg(args, int));
			break;
		case 'i':
			chars_printed += print_integer(va_arg(args, int));
			break;
		default:
			chars_printed += print_char('%');
			chars_printed += print_char(format);
			return (-1);
	}

	return (chars_printed);
}
