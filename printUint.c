#include "main.h"

/**
  * printUint - prints unsigned int specifiers to stdout
  * @str: NULL
  * @args: variable list
  * @base: NULL
  *
  * Return: number of digits printed
  */

int printUint(va_list args, char *str, unsigned int base)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int i = 0;
	unsigned int temp, div = 1;

	str = "Hello";
	temp = num;

	while (temp > 9 && str)
	{
		div *= 10;
		temp /= 10;
	}
	while (div != 0)
	{
		temp = num / div + '0';
		write(1, &temp, 1);
		i++;
		num = (num % div);
		div /= 10;
	}
	temp = base;
	return (i);
}
