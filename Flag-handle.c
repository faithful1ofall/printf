#include "main.h"

/**
 * flag_handler1 - Controller for percent format
 * @str: String format
 * @args: List of arguments
 * @i: Iterator
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: Size of the numbers of elements printed
 **/

int flag_handler1(const char *str, va_list args, int *i,
					int flags, int width, int precision, int size)
{
	int si, j, num_formats;
	form1 formats[] = {
			{'d', print_integer}, {'i', print_integer}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		put_char('%');
		return (1);
	}

	num_formats = sizeof(formats) / sizeof(formats[0]);
	for (si = j = 0; j < num_formats; j++)
	{
		if (str[*i] == formats[j].typ)
		{
			si = formats[j].fa(args, flags, width, precision, size);
				return (si);
		}
	}
		
	put_char('%'), put_char(str[*i]);

	return (2);
}
