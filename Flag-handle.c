#include "main.h"

/**
 * percent_handler - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 * Return: Size of the numbers of elements printed
 **/

int flag_handler(const char *str, va_list args, int *i)
{
	int size = 0, j = 0, num_formats;
	form formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
	};

	*i += 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		put_char('%');
		return (1);
	}

	num_formats = sizeof(formats) / sizeof(formats[0]);
	while (j < num_formats)
	{
		if (str[*i] == formats[j].typ)
		{
			size = formats[j].fa(args);
			return (size);
		}
		j++;
	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}
