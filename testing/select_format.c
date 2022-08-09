#include "main.h"

/**
  * select_format - Selects format to print
  * @fmt: input string
  * @args: va_list
  *
  * Return: string length
  */

int (*select_format(char *fmt))(va_list args , char *str, unsigned int base)
{
	print_t ops[] = {
		{"c", printChar},
		{"s", printStr},
		{"d", printInt},
		{"i", printInt},
		{"b", baseConversion},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].spec)
	{
		if (ops[i].spec[0] == *fmt)
			break;
		i++;
	}
	return (ops[i].f);

	/*
	switch (*fmt)
	{
		case '%':
			write(1, fmt, 1), len++;
			break;
		case 'c':
			cVal = va_arg(args, int);
			write(1, &cVal, 1), len++;
			break;
		case 's':
			for (sVal = va_arg(args, char *); *sVal;
					sVal++)
				write(1, sVal, 1), len++;
			break;
		case 'd':
			cVal = va_arg(args, int), len += printINT(cVal);
			break;
		case 'i':
			cVal = va_arg(args, int), len += printINT(cVal);
			break;
		case 'b':
			sVal = baseConversion(va_arg(args, unsigned int), 2);
			len += printSTR(sVal);
			break;
		default:
			write(1, fmt, 1), len++;
			break;
	}
	return (len); */
}
