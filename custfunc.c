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
 * handle_format_specifier - Format controller
 * @str: String format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int handle_format_specifier(const char *format, va_list args)
{
	int chars_printed = 0, i = 0, aux;
	
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			aux = flag_handler(str, args, &i);
			if (aux == -1)
				return (-1);

			size += aux;
			continue;
		}
		i++;

		_putchar(str[i]);
		chars_printed = chars_printed + 1;
	}


	return (chars_printed);
}

/**
 * handle_format_specifier - format handler
 * @format: format specifier
 * @args: argument to pick
 * Return: characters to print
 */

int handle_format_specifier_old(char format, va_list args)
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
			chars_printed += put_char('%');
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
