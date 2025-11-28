#include "main.h"
#include <stdarg.h>
/**
 * _print_char - function that prints a character
 * @args: va_list containing the character to print
 *
 * Return: the caracter printed
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}
