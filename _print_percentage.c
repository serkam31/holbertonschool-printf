#include "main.h"
#include <stdarg.h>
/**
 * _print_percentage - function that prints a percentage sign
 * @args: va_list (not used)
 *
 * Return: the caracter printed
 */
int _print_percentage(va_list args)
{
	(void)args; /* Unused parameter */
	return (_putchar('%'));

}
