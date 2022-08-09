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
		if (*pr == '%')
		{
			write(1, pr, 1), len++;
			continue;
		}
		select_fmt = select_format(pr);
		if (select_fmt == NULL)
		{
			printStr(args, "Unkwown specifier after '%'\n", 0);
			return (-1);
		}
		len += select_fmt(args, NULL, 2);
	}
	va_end(args);
	return (len);
}
int main()
{
	char c = 'Q';
	char *s = "String";
	int d = 98, i = -890;

	return (_printf("Hello, %%, c:%c, s:%s, b:%b, i:%i, :%", c, s, d, i));
}
