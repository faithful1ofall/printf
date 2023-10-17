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