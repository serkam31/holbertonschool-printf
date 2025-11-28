#include "main.h"
#include <stdarg.h>

/**
 * _print_string - function that prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
