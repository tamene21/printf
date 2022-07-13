#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_r(va_list r);
int print_R(va_list R);
int print_P(va_list P);


/**
 *struct print_format - Struct for printing various format
 *@sp: The specifiers
 *@f: The function associated
 */

typedef struct print_format

{

	char *sp;

	int (*f)(va_list);

} print_f;

#endif /*MAIN_H*/
