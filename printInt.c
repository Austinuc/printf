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
	int temp = 1000000000;

	str = "Hello";
	if (!num && str)
		return (-1);
	if (num < 0)
	{
		write(1, &n, 1), num = -1 * num;
		i++;
	}
	if (num / 10 == 0)
	{
		n = num % temp + 48;
		write(1, &n, 1), i++;
		return (i);
	}
	while (num / temp == 0)
		temp /= 10;
	while (temp != 10)
	{
		n = ((num / temp) + 48);
		write(1, &n, 1);
		num %= temp, temp /= 10, i++;
	}
	n = ((num / temp) + 48), write(1, &n, 1);
	n = ((num % temp) + 48), write(1, &n, 1), i += 2;

	n = (char)base;
	return (i);
}
