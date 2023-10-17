#include "main.h"

/**
 * flag_handler - Controller for percent format
 * @str: String format
 * @args: List of arguments
 * @i: Iterator
 * Return: Size of the numbers of elements printed
 **/

int flag_handler(const char *str, va_list args, int *i)
{
	int si, j, num_formats;
	form formats[] = {
		{'s', print_string}, {'c', print_char},
		{'b', print_binary}, {'u', print_u},
		{'o', print_o}, {'x', print_x},
		{'X', print_X}, {'p', print_p},
		{'S', print_S}, {'r', print_r},
		{'R', print_R}
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
			si = formats[j].fa(args);
				return (si);
		}
	}
		
	put_char('%'), put_char(str[*i]);

	return (2);
}

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
	form1 formats1[] = {
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

	num_formats = sizeof(formats1) / sizeof(formats1[0]);
	for (si = j = 0; j < num_formats; j++)
	{
		if (str[*i] == formats1[j].typ1)
		{
			si = formats1[j].fa1(args, flags, width, precision, size);
				return (si);
		}
	}
		
	put_char('%'), put_char(str[*i]);

	return (2);
}
