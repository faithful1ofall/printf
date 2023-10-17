#include "main.h"

/**
 * conv_size_num - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int conv_size_num(long int n, int size)
{
	if (size == C_LONG)
		return (n);
	else if (size == C_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * conv_size_unsg - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */
long int conv_size_unsg(unsigned long int num, int size)
{
	if (size == C_LONG)
		return (num);
	else if (size == C_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
