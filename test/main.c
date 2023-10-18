#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2, len3, len4;

	len = _printf("%.6s", "Best School !\n");
	len2 = printf("%.6s", "Best School !\n");

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len3 = _printf("%.*s", 5, "Best School !\n");
	len4 = printf("%.*s", 6, "Best School !\n");
  
	fflush(stdout);
	if (len3 != len4)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
  }
  
	return (0);
}
