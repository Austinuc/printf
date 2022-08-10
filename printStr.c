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

	if (args)
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

/**
  * printAllStr - Print all strings
  * @args: var list
  * @str: NULL
  * @base: NULL
  *
  * Description: Non printable characters (0 < ASCII value < 32 or >= 127)
  * are printed this way: \x, followed by the ASCII code value in hexadecimal
  * (upper case - always 2 characters)
  * Return: num of char printed
  */

int printAllStr(va_list args, char *str, unsigned int base)
{
	char *hex, *s;
	unsigned int i = 0, len = 0;

	if (*str == 'p')
	{
		hex = "0x";
		write(1, hex, 2);
		len += 2;
		len += baseHexConversion(args, str, 16);
	}
	else
	{
		s = va_arg(args, char *);
		hex = "\\x";
		for (; *s; i++, s++)
		{
			if (*s >= 32 && *s < 127 && str)
				write(1, s, 1), len++;
			else
			{
				write(1, hex, 2);
				len += 2;
				len += baseHexConversion(NULL, s, 19);
			}
		}
	}
	i = base;
	return (len);
}
