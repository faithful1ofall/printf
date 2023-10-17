#include "main.h"

/**
 * print_r - Print a string in reverse
 * @args: List of arguments
 * Return: Length of the string
 **/
int print_r(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	int i, s;
	const char *fstr;

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
