#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "main.h"
/**
 * search_function - a function that finds printf formats
 * @format: format types
 * Return: NULL or other formats
 */

int (*search_function(const char *format))(va_list)
{
	unsigned int i = 0;

	print_f find_f[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"r", print_r},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"R", print_R},
		{"%", print_P}
		{NULL, NULL}

	};
	while (find_f[i].sp)
	{
		if (find_f[i].sp[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);

}


/**
 * _printf - function to stdout a specified format
 * @format: format of the output
 * Return: out put text
 */


int _printf(const char *format, ...)
{
	va_list ap;

	int (*f)(va_list);
	unsigned int i = 0;
	unsigned int cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = search_function(&format[i + 1]);
		if (f != NUll)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;

	}
	va_end(ap);
	return (cprint);

}


