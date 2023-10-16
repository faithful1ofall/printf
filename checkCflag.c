#include "main.h"

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
	int j, cf_i = *c + 1;;
	int cf = 0;
	const char CF_CH[] = {'-', '+', '0', '#', ' '};
	const int CF_ARR[] = {C_MIN, C_PLUS, C_ZERO, C_HASH, C_SPACE};

	while (format[cf_i] != '\0')
	{
		j = 0;
		while (CF_CH[j] != '\0')
		{
			if (format[cf_i] == CF_CH[j])
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
