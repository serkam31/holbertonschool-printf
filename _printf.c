#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Print text and values
 * @format: Format string containing text and specifiers
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{

	int length = 0; /*count the total number of characters printed */
	int i = 0;		/*index that traverses the string*/
	int j;			/*index that traverses the structure*/

	va_list args; /*variable that will allow us to access all the arguments*/

	check_t specifier[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percentage},
		{"i", _print_integer},
		{"d", _print_integer},
		{NULL, NULL}};

	if (format == NULL) /* Return error if format is NULL */
		return (-1);

	va_start(args, format); /* we indicate from when to look for the argument*/

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0') /* If % is the last character, return -1 */
			{
				va_end(args);
				return (-1);
			}

			else
			{
				j = 0;

				while (specifier[j].type != NULL)
				{
					if (format[i] == *(specifier[j].type))
					{
						length = length + specifier[j].func(args);
						break;
					}
					j++;
				}
				if (specifier[j].type == NULL)
				{
					_putchar('%');
					_putchar(format[i]);
					length = length + 2;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
