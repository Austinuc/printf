#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int select_format(const char *fmt, va_list);
int printINT(int);
int baseConversion(unsigned int, int);


#endif
