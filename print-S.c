#include "main.h"

/**
 * add_hexa_code - Append ascci in hexadecimal code to buffer
 * @str: Array of chars.
 * @i: Index at which to start appending.
 * @asc: ASSCI CODE.
 * Return: Always 3
 */
int add_hexa_code(char asc, char str[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asc < 0)
		asc *= -1;

	str[i++] = '\\';
	str[i++] = 'x';

	str[i++] = map_to[asc / 16];
	str[i] = map_to[asc % 16];

	return (3);
}

/**
 * print_S - Prints ascii codes in hexa of non printable chars
 * @args: List of arguments
 * Return: Number of chars printed
 */
int print_S(va_list args, int flags, int width, int precision, int size)
{
	int i = 0, j = 0;
	char *fstr = va_arg(args, char *), str[1024];

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	if (fstr == NULL)
		return (write(1, "(null)", 6));

	while (fstr[i] != '\0')
	{
		if (can_print(fstr[i]))
			str[i + j] = fstr[i];
		else
			j += add_hexa_code(fstr[i], str, i + j);
		i++;
	}
	str[i + j] = '\0';
	return (write(1, str, i + j));
}
