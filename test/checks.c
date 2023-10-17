#include "main.h"


/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * check_flags - Calculates active flags
 * @cstr: Formatted string in which to print the arguments
 * @c: take a parameter.
 * Return: Flags:
 */
int check_flags(const char *cstr, int *c)
{
	/* - + 0 # ' ' */
	/* 2 3 4 5  6 */
	int j, cf_i = *c + 1, cf;

	const char CF_CH[] = {'-', '+', '0', '#', ' '};
	const int CF_ARR[] = {C_MINUS, C_PLUS, C_ZERO, C_HASH, C_SPACE};

	while (cstr[cf_i] != '\0')
	{
		j = 0;
		while (CF_CH[j] != '\0')
		{
			if (cstr[cf_i] == CF_CH[j])
			{
				cf |= CF_ARR[j];
				break;
			}
			j++;
		}
		cf_i++;

		if (CF_CH[j] == 0)
			break;
	}
	*c = cf_i - 1;

	return (cf);
}

/**
 * check_width - Calculates the width for printing
 * @cstr: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 * Return: width.
 */
int check_width(const char *cstr, int *i, va_list args)
{
	int cf_i, width = 0;

	for (cf_i = *i + 1; cstr[cf_i] != '\0'; cf_i++)
	{
		if (is_digit(cstr[cf_i]))
		{
			width *= 10;
			width += cstr[cf_i] - '0';
		}
		else if (cstr[cf_i] == '*')
		{
			cf_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = cf_i - 1;

	return (width);
}

/**
 * check_precision - Calculates the precision for printing
 * @cstr: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 * Return: Precision.
 */
int check_precision(const char *cstr, int *i, va_list args)
{
	int cf_i = *i + 1, precision = -1;

	if (cstr[cf_i] != '.')
		return (precision);

	precision = 0;

	for (cf_i += 1; cstr[cf_i] != '\0'; cf_i++)
	{
		if (is_digit(cstr[cf_i]))
		{
			precision *= 10;
			precision += cstr[cf_i] - '0';
		}
		else if (cstr[cf_i] == '*')
		{
			cf_i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = cf_i - 1;

	return (precision);
}

/**
 * check_size -Calculates the size to cast the argument
 * @cstr: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int check_size(const char *cstr, int *i)
{
	int cf_i = *i + 1;
	int size = 0;

	if (cstr[cf_i] == 'l')
		size = C_LONG;
	else if (cstr[cf_i] == 'h')
		size = C_SHORT;

	if (size == 0)
		*i = cf_i - 1;
	else
		*i = cf_i;

	return (size);
}
