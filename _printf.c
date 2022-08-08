#include "main.h"

/**
  * _printf - formatted output conversion and print data to stdout
  * @format: input string
  *
  * Return: number of character printed
  */

int _printf(const char *format, ...)
{
	const char *pr;
	unsigned int len = 0;
	va_list args;

	int (*select_fmt)(const char *, va_list);
	va_start(args, format);
	if (!format || (*format == '%' && !format[1]))
		return (-1);
	if (!(*format))
		return (0);
	for (pr = format; *pr; pr++)
	{
		if (*pr != '%')
		{
			write(1, pr, 1), len++;
			continue;
		}
		pr++;
		select_fmt = select_format;
		len += select_fmt(pr, args);
/*
		switch (*++pr)
		{
			case '%':
				write(1, pr, 1), len++;
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
				write(1, pr, 1), len++;
				break;
		} */
	}
	va_end(args);
	return (len);
}

int main()
{
	char c = 'H';
	char *st = "Austin";

	return (_printf("Hello, %c, %s\n", c, st));
}
