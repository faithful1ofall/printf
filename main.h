#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct _format - Typedef struct
 *
 * @type: Format
 * @f: The function associated
 **/
typedef struct _form
{
	char typ;
	int (*fa)(va_list);
} form;

int _printf(const char *format, ...);
char *itac(long int num, int base);
int put_char(char c);
int print_char(va_list);
int _strlen(const char *s);
int print_string(va_list);
int put_string(char *str);
int num_length(int num);
void int_to_str(char *str, int num);
int print_integer(va_list);
int handle_format_specifier(const char *format, va_list);
int flag_handler(const char *str, va_list, int *i);

#endif /* MAIN_H */
