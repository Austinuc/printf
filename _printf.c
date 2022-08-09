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
	unsigned int len = 0, base, i = 0, b[] = {2, 8, 16, 17};
	char arr[] = "boxX";
	va_list args;
	int (*select_fmt)(va_list, char *, unsigned int);

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
		if (*pr == '\0')
			return (-1);
		for (i = 0; i < 4; i++)
		{
			if (*pr == arr[i])
				base = b[i], i = 9;
		}
		select_fmt = select_format(pr);
		if (select_fmt == NULL)
		{
			write(1, pr, 1);
			continue;
		}
		len += select_fmt(args, NULL, base);
	}
	va_end(args);
	return (len);
}
