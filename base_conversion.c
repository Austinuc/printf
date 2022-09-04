#include "main.h"

/**
  * baseConversion - converts unsigned int to hexadecimal
  * @args: variable lists
  * @base: base to be converted to - 16 in this case
  * @str: NULL
  *
  * Return: number in converted base
  */

int baseConversion(va_list args, char *str, unsigned int base)
{
	char arr[64];
	char converted[] = "0123456789abcdef";
	char convertB[] = "0123456789ABCDEF";
	char *ptr = &arr[63];
	unsigned int num = va_arg(args, unsigned int), div = 16;
	int (*p_str)(va_list, char *, unsigned int);

	*ptr = '\0';
	str = "Hello";
	do {
		if (base == 17)
		{
			*--ptr = convertB[(num % div)];
			num /= div;
		}
		else
		{
			*--ptr = converted[(num % base)];
			num /= base;
		}
	} while (num != 0 && str);
	p_str = printStr;
	return (p_str(NULL, ptr, base));
}

/**
  * baseHexConversion - converts unsigned int to any base
  * @args: variable lists
  * @base: base to be converted to
  * @str: input string of numbers
  *
  * Return: number in converted base
  */

int baseHexConversion(va_list args, char *str, unsigned int base)
{
	char arr[64];
	char convertB[] = "0123456789ABCDEF";
	char *ptr = &arr[63];
	unsigned int num;
	int len = 0;
	int (*p_str)(va_list, char *, unsigned int);

	*ptr = '\0';
	if (!args)
	{
		num = (unsigned int)*str;
		if (num < 16 && str)
		{
			write(1, convertB, 1);
		}
		do {
			*--ptr = convertB[(num % base)];
			num /= base;
		} while (num != 0);
		write(1, ptr, 2);
		len = 2;
		return (len);
	}
	num = va_arg(args, unsigned int);
	if (num < 16 && str)
	{
		write(1, convertB, 1);
		len++;
	}
	do {
		*--ptr = convertB[(num % base)];
		num /= base;
	} while (num != 0);
	p_str = printStr;
	return (p_str(NULL, ptr, base) + len);
}
