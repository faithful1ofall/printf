#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int put_char(char c);
int print_char(int c);
int _strlen(const char *s);
int print_string(char *str);
int put_string(char *str);
int num_length(int num);
void int_to_str(char *str, int num);
int print_integer(int num);
int handle_format_specifier(char format, va_list args);

#endif /* MAIN_H */
