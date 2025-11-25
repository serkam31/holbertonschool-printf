#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_specifier - Structure for format specifiers
 * @type: The conversion specifier character
 * @func: Function pointer to handle the specifier
 *
 * Description: Associates a format specifier with its handler function
 */
typedef struct check
{
	char *type;
	int (*func)(va_list);
}check_t;

/*Prototype of the functions*/
int _printf(const char *format, ...);
int _putchar(char c);

/* Helper functions */
int _print_char(va_list args);
int _print_string(va_list args);
int _print_percentage(va_list args);

#endif
