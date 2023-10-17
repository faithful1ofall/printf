#include "main.h"

/**
 * print_r - Print a string in reverse
 * @args: List of arguments
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * @lim: character array
 * Return: Length of the string
 **/
int print_r(va_list args, int flags, int width,
int precision, int size, char lim[])
{
	int i, s;
	const char *fstr;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	NO(lim);

	fstr = va_arg(args, const char *);

	s = _strlen(fstr);
	i = s - 1;

	while (i >= 0)
	{
		put_char(fstr[i]);
		i--;
	}
	return (s);
}
