#include "main.h"

/**
  * printChar - prints characters to stdout
  * @args: variable lists
  * @str: NULL
  * @base: NULL
  *
  * Return: 1 - no of character printed
  */

int printChar(va_list args, char *str, unsigned int base)
{
	char c = va_arg(args, int), len = 0;

	write(1, &c, 1);
	return (++len);
}
