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

/* SIZES */
#define C_LONG 5
#define C_SHORT 3

/**
 * struct typ - Struct op
 *
 * @typ: The format.
 * @fa: The function associated.
 */
struct typ
{
	char typ;
	int (*fa)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct typ typ_t - Struct op
 *
 * @typ: The format.
 * @fm_t: The function associated.
 */
typedef struct typ typ_t;

int _printf(const char *format, ...);
int flag_handler1(const char *typ, int *i,
va_list fargs, char lim[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_c(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_s(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_percent(va_list , char lim[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_i_d(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_b(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_u(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_o(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_x(va_list , char lim[],
	int flags, int width, int precision, int size);
int print_X(va_list , char lim[],
	int flags, int width, int precision, int size);

int print_fhex(va_list , char map_to[],
char lim[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_S(va_list , char lim[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_p(va_list , char lim[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int check_flags(const char *format, int *i);
int check_width(const char *format, int *i, va_list fargs);
int check_precision(const char *format, int *i, va_list fargs);
int check_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_r(va_list , char lim[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_R(va_list , char lim[],
	int flags, int width, int precision, int size);

/* width handler */
int write_c(char c, char lim[],
	int flags, int width, int precision, int size);
int write_fnumb(int is_positive, int ind, char lim[],
	int flags, int width, int precision, int size);
int write_fnum(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_p(char lim[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_u(int negative, int ind,
char lim[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int can_print(char);
int add_hexa_code(char, char[], int);
int is_digit(char);

long int conv_size_numb(long int num, int size);
long int conv_size_un(unsigned long int num, int size);

#endif /* MAIN_H */
