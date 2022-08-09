#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int (*select_format(const char *fmt))(va_list, char *, unsigned int);
int printInt(va_list, char *, unsigned int);
int printUint(va_list, char *, unsigned int);
int printStr(va_list, char *, unsigned int);
int printChar(va_list, char *, unsigned int);
int baseConversion(va_list, char *, unsigned int);

/**
  * struct print_type - Structure for type formats
  *
  * @spec: format specifier
  * @f: printing function
  */

typedef struct print_type
{
	char *spec;
	int (*f)(va_list, char *, unsigned int);
} print_t;

#endif
