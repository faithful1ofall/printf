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
	int si, j, num_formats = 13, unlen = 0;
	form formats[] = {
		{'s', print_string}, {'c', print_char}, {'d', print_integer},
		{'i', print_integer}, {'b', print_binary}, {'u', print_u},
		{'o', print_o}, {'x', print_x}, {'X', print_X}, {'p', print_p},
		{'S', print_S}, {'r', print_r}, {'R', print_R}
	};
	if (str[*i] == '%')
	{
		put_char('%');
		return (1);
	}
	for (si = j = 0; j < num_formats; j++)
	{
		if (str[*i] == formats[j].typ)
		{
			si = formats[j].fa(args, flags, width, precision, size);
				return (si);
		}
	}
	if (formats[j].typ == '\0')
	{
		if (str[*i] == '\0')
			return (-1);
		unlen += write(1, "%%", 1);
		if (str[*i - 1] == ' ')
			unlen += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (str[*i] != ' ' && str[*i] != '%')
				--(*i);
			if (str[*i] == ' ')
				--(*i);
			return (1);
		}
		unlen += write(1, &str[*i], 1);
		return (unlen);
	}
	return (-1);
}
