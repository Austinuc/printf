#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
  * _printf - formatted output conversion and print data to stdout
  * @format: input string
  *
  * Return: number of character printed
  */

int _printf(const char *format, ...)
{
	const char *pr;
	int cVal;
	char *sVal;
	unsigned int len = 0;
	va_list args;

	va_start(args, format);
	for (pr = format; *pr; pr++)
	{
		if (*pr != '%')
		{
			write(1, pr, 1);
			len++;
			continue;
		}

		switch (*++pr)
		{
			case 'c':
				cVal = va_arg(args, int);
				write(1, &cVal, 1);
				len++;
				break;
			case 's':
				for (sVal = va_arg(args, char *); *sVal;
						sVal++)
				{
					write(1, sVal, 1);
					len++;
				}
				break;
		}
	}
	va_end(args);
	return (len);
}
