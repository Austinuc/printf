#include "main.h"

/**
  * printStr - prints strings to stdout
  * @args: variable list
  * @str: NULL
  * @base: NULL
  *
  * Return: length of string printed
  */

int printStr(va_list args, char *str, unsigned int base)
{
	unsigned int len = 0, temp = len;
	char *ptr;

	if (!str)
	{
		ptr = va_arg(args, char *);
		if (!ptr)
			return (-1);
		while (*ptr != '\0')
		{
			write(1, ptr, 1), len++, temp++;
			ptr++;
		}
	}
	else
	{
		while (*str != '\0')
		{
			write(1, str, 1), len++;
			str++;
		}
	}
	temp = base;
	return (len);
}
