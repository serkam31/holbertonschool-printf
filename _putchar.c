#include <unistd.h>
#include "main.h"

/**
 * _putchar - affiche un caractère sur stdout
 * @c: caractère à afficher
 *
 * Return: 1 si succès, -1 sinon
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
