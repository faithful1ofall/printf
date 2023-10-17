#include "main.h"

/**
 * can_print - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int can_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code - Append ascci in hexadecimal code to lim
 * @lim: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 3
 */
int add_hexa_code(char ascii_code, char lim[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	lim[i++] = '\\';
	lim[i++] = 'x';

	lim[i++] = map_to[ascii_code / 16];
	lim[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_numb - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int conv_size_numb(long int num, int size)
{
	if (size == C_LONG)
		return (num);
	else if (size == C_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_size_un - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int conv_size_un(unsigned long int num, int size)
{
	if (size == C_LONG)
		return (num);
	else if (size == C_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
