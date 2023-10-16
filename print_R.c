#include "main.h"

/**
 * rot13 - encodes a string in rot13
 * @s: string to be encoded
 * Return: the resulting string
 */
int rot13(char *s)
{
	int i = 0, j;
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
				s[i] = b[j];
				put_char(b[j]);
				break;
			}
			j++;
		}
		if (!b[j])
			put_char(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_R - Prints the rot13'ed string
 * @args: String to encoded
 * Return: Length of the string encoded
 **/
int print_R(va_list args)
{
	char *f;
	int f_len;

	f = va_arg(args, char *);
	f_len = rot13((f != NULL) ? f : "(ahyy)");

	return (f_len);
}
