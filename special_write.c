#include "main.h"

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */
int write_nu(int ind, char num[], int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == 1022 && num[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == 1022 && num[ind] == '0')
		num[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		num[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			num[i] = padd;
		num[i] = '\0';
		if (flags & C_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				num[--ind] = extra_c;
			return (write(1, &num[ind], length) + write(1, &num[1], i - 1));
		}
		else if (!(flags & C_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				num[--ind] = extra_c;
			return (write(1, &num[1], i - 1) + write(1, &num[ind], length));
		}
		else if (!(flags & C_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				num[--padd_start] = extra_c;
			return (write(1, &num[padd_start], i - padd_start) +
				write(1, &num[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		num[--ind] = extra_c;
	return (write(1, &num[ind], length));
}

/**
 * write_numb - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @num: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int write_numb(int is_negative, int ind, char num[],
	int flags, int width, int precision)
{
	int length = 1023 - ind;
	char padd = ' ', extra_ch = 0;

	if ((flags & C_ZERO) && !(flags & C_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & C_PLUS)
		extra_ch = '+';
	else if (flags & C_SPACE)
		extra_ch = ' ';

	return (write_nu(ind, num, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int ind,
	char buffer[],
	int flags, int width, int precision)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = 1023 - ind, i = 0;
	char padd = ' ';


	if (precision == 0 && ind == 1022 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & C_ZERO) && !(flags & C_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & C_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & C_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & C_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & C_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], 1023 - ind));
}
