#include "main.h"

/**
  * select_format - Selects format to print
  * @fmt: input string
  * @args: va_list
  *
  * Return: string length
  */

int select_format(const char *fmt, va_list args)
{
	int cVal;
	char *sVal;
	unsigned len = 0;

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
			{
				write(1, sVal, 1), len++;
			}
			break;
		default:
			write(1, fmt, 1), len++;
			break;
	}
	return (len);
}
