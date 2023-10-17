#include "main.h"

/**
 * flag_handler - Controller for percent format
 * @str: String format
 * @args: List of arguments
 * @i: Iterator
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: Size of the numbers of elements printed
 **/

int flag_handler(const char *str, va_list args, int *i,
					int flags, int width, int precision, int size)
{
	int si, j, num_formats;
	form formats[] = {
		{'s', print_string, print_string}, {'c', print_char, print_char},
		{'d', print_integer, print_integer}, {'i', print_integer, print_integer},
		{'b', print_binary, print_binary}, {'u', print_u, print_u},
		{'o', print_o, print_o}, {'x', print_x, print_x},
		{'X', print_X, print_X}, {'p', print_p, print_p},
		{'S', print_S, print_S}, {'r', print_r, print_r},
		{'R', print_R, print_R}
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
		if (j == 2 || j == 3)
		{
			continue;
		}
		else if (j == 20)
		{
			
			si = formats[j].fa(args, flags, width, precision, size);
		}
		else
		{
			si = formats[j].fa(args);
			continue;
		}	
		if (str[*i] == formats[j].typ)
		{
			
			return (si);
		}
	}

	put_char('%'), put_char(str[*i]);

	return (2);
}
