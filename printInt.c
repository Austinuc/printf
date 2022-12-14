#include "main.h"

/**
  * printInt - prints d & i specifiers to stdout
  * @str: NULL
  * @args: variable list
  * @base: NULL
  *
  * Return: number of digits printed
  */

int printInt(va_list args, char *str, unsigned int base)
{
	int num = va_arg(args, int);
	unsigned int i = 0;
	char n = '-';
	unsigned int temp, div = 1;

	str = "Hello";
	if (num < 0 && str)
	{
		write(1, &n, 1), num = -1 * num;
		i++;
	}
	temp = num;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	while (div != 0)
	{
		n = num / div + '0';
		write(1, &n, 1);
		i++;
		num = (num % div);
		div /= 10;
	}
	n = (char)base;
	return (i);
}
