#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * print_p - Print a number in hexadecimal format
 * @args: Number to print
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * @lim: character array
 * Return: Length of the number
 **/
int print_p(va_list args, int flags, int width,
int precision, int size, char lim[])
{
	char *f;
	int s;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	NO(lim);

	f = itac(va_arg(args, unsigned long int), 16);

	if (!_strcmp(f, "0"))
		return (put_string("(nil)"));

	s = put_string("0x");

	if (!_strcmp(f, "-1"))
		s += put_string("ffffffffffffffff");
	else
		s += put_string(f);

	return (s);
}
