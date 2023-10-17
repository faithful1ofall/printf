#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: the character for checking
 * Return: 1 if c is lowercase success, 0 otherwise or error
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * stou - Change the string to uppercase
 * @f: String
 * Return: String uppercase
 **/
char *stou(char *f)
{
	int i;

	for (i = 0; f[i] != '\0'; i++)
	{
		if (_islower(f[i]))
		{
			f[i] = f[i] - 32;
		}
	}

	return (f);
}
