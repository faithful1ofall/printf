#include "main.h"

/**
 * rot13 - encodes a string in rot13
 * @s: string to be encoded
 * Return: the resulting string
 */
int rot13(char *s)
{
	unsigned int i = 0, j, c = 0;
	char *a, *b;

	a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	b = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (s[i] != '\0')
	{
		j = 0;

		while (a[j] != '\0')
		{
			if (s[i] == a[j])
			{
				put_char(b[j]);
				c++;
				break;
			}
			j++;
		}
		if (!b[j])
		{
			put_char(s[i]);
			c++;
		}
		i++;
	}
	return (c);
}

/**
 * print_R - Prints the rot13'ed string
 * @args: String to encoded
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * @lim: character array
 * Return: Length of the string encoded
 **/
int print_R(va_list args, int flags, int width,
int precision, int size, char lim[])
{
	char *f;
	int f_len;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	NO(lim);

	f = va_arg(args, char *);
	f_len = rot13((f != NULL) ? f : "(AHYY)");

	return (f_len);
}
