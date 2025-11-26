#include "main.h"
#include <stdarg.h>

/**
 * print_number - Prints an unsigned integer recursively
 * @num: the number to print
 *
 * Return: the integer to print
 */
int print_number(unsigned int num)
{
	int written = 0;

	if (num >= 10)
	{
		written += print_number(num / 10);
	}

	written += _putchar((num % 10) + '0');

	return (written);
}

/**
 * _print_integer - function that prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int _print_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-n);
	}
	else
	{
		num = n;
	}

	count += print_number(num);

	return (count);
}
