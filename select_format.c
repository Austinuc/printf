#include "main.h"

/**
  * select_format - Selects format to print
  * @fmt: input string
  *
  * Return: string length
  */

int (*select_format(const char *fmt))(va_list args, char *str, unsigned int b)
{
	print_t ops[] = {
		{"c", printChar},
		{"%", printChar},
		{"s", printStr},
		{"S", printAllStr},
		{"d", printInt},
		{"i", printInt},
		{"u", printUint},
		{"b", baseConversion},
		{"o", baseConversion},
		{"x", baseConversion},
		{"X", baseConversion},
		{"p", printAllStr},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].spec)
	{
		if (!(ops[i + 1].spec) && ops[i].spec[0] != *fmt)
		{
			i++;
			break;
		}
		if (ops[i].spec[0] == *fmt)
			break;
		i++;
	}
	return (ops[i].f);
}
