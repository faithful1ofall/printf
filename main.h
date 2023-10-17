#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NO(f) (void)(f)


/* FLAG OPERATORS AND SPECIALS */
#define C_MINUS 2
#define C_PLUS 3
#define C_ZERO 4
#define C_HASH 5
#define C_SPACE 6

/* DIFFERENT SIZES  */
#define C_LONG 5
#define C_SHORT 3

/**
 * struct typ - Struct op
 * @typ: The format.
 * @fa: The function associated.
 */
struct typ
{
	char typ;
	int (*fa)();
};


/**
 * typedef struct typ typ_t - Struct op
 * @typ: The format.
 * @typ_t: The function associated.
 */
typedef struct typ typ_t;

int _printf(const char *format, ...);
int flag_handler1(const char *, int *, va_list, char[], int, int, int, int);

/* Funtions to print chars and strings */
int print_char(va_list, char[], int, int, int, int);
int print_string(va_list, char[], int, int, int, int);
int print_percent(va_list, char[], int, int, int, int);

/* Functions to print numbers */
int print_int(va_list, char[], int, int, int, int);
int print_binary(va_list, char[], int, int, int, int);
int print_unsigned(va_list, char[], int, int, int, int);
int print_octal(va_list, char[], int, int, int, int);
int print_hexadecimal(va_list, char[], int, int, int, int);
int print_hexa_upper(va_list, char[], int, int, int, int);
int print_hexa(va_list, char[], char[], int, char, int, int, int);

/* Function to print non printable characters */
int print_non_printable(va_list, char[], int, int, int, int);

/* Funcion to print memory address */
int print_pointer(va_list, char[], int, int, int, int);

/* Funciotns to handle other specifiers */
int get_flags(const char *, int *i);
int get_width(const char *, int *i, va_list);
int get_precision(const char *, int *, va_list);
int get_size(const char *, int *);

/*Function to print string in reverse*/
int print_reverse(va_list, char[], int, int, int, int);

/*Function to print a string in rot 13*/
int print_rot13string(va_list, char[], int, int, int, int);

/* special write handler */
int handle_write_char(char, char[], int, int, int, int);
int write_number(int, int, char[], int, int, int, int);
int write_num(int, char[], int, int, int, int, char, char);
int write_pointer(char lim[], int ind, int length, int, int, char, char, int);
int write_unsgnd(int, int, char[], int, int, int, int);

/* Other Special Functions */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int, int);
long int convert_size_unsgnd(unsigned long int, int);

#endif /* MAIN_H */
