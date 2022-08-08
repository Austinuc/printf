#include "main.h"

/**
  * printINT - prints d & i specifiers to stdout
  * @num: input number to print
  *
  * Return: number of digits printed
  */

int printINT(int num)
{
	unsigned int i = 0;
	char n = '-';
	int temp = 1000000000;

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

	return (i);
}
