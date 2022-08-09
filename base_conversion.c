#include "main.h"

/**
  * baseConversion - converts unsigned int to binary
  * @args: variable lists
  * @base: base to be converted to
  * @str: NULL
  *
  * Return: number in converted base
  */

int baseConversion(va_list args, char *str, unsigned int base)
{
	char arr[64];
	char converted[] = "0123456789ABCDEF";
	char *ptr = &arr[63];
	unsigned int num = va_arg(args, unsigned int);
	int (*p_str)(va_list, char *, unsigned int);

	*ptr = '\0';
	*str = '\0';
	do {
		*--ptr = converted[(num % base)];
		num /= base;
	} while (num != 0);
	p_str = printStr;
	return (p_str(args, ptr, base));
}
