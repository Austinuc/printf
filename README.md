# Printf()

This printf project was done during the Full Stack Software Engineering program at ALX-Africa. The function named "_printf" imitates the actual "printf" command located in the stdio.h library. It contains some of the basic features and functions found in the manual 3 of "printf".

**_printf()** is a function that performs formatted output conversion and print data. Its prototype is the following:

```
int _printf(const char *format, ...)
```

Where **format** contains the string that is printed. The **_printf()** is variadic function, it can receive n arguments that get replaced by corresponding tag specifiers respectively.

The format tag prototype is as follows:

```
%[flags][length]specifier
```

**If the program runs successfully, the return value is the amount of chars printed (excluding the null byte used to end output to strings)**

Specifier | Output
--- | ---
c	| Character
d or i	| Signed decimal integer
s	| String of characters
b	| Signed binary
o	| Signed octal
u	| Unsigned integer
x	| Unsigned hexadecimal
X	| Unsigned hexadecimal (uppercase)
p	| Pointer address
S	| String with special chars replaced by their ASCII value
%	| Character

## Examples

1. Printing the string of chars "Hello, Holberton":
   - **Usage:** _printf("Hello Hol%s.", "berton");
   - **Output:** Hello Holberton.

2. Printing an integer number:
   - **Usage:** _printf("10 + 10 is equal to %d.", (10 + 10));
   - **Output:** 10 + 10 is equal to 20.

3. Printing a binary, octal and hexadecimal:
   - **Usage:** _printf("10 in binary is [%b], in octal is [%o] and in hexadecimal is [%x]", 10, 10, 10);
   - **Output:** 10 in binary is [1010], in octal is [12] and in hexadecimal is [A]

## File Functions

### _printf.c
***
Performs Formatted Output Conversion And Prints the Data.

### main.h
***
Header file where all function and structure prototypes are saved

### select_format.c
***
Function pointer that calls a particular function for any valid specifier

### base_conversion.c
***
Contains functions that converts any given number to any desired base
```
/* Specifier : %b(decimal to binary) or %o(decimal to octa) or %x(decimal to lowercase hexadecimal) or %X(decimal to UPPERCASE hexadecimal) */
```

### printChar.c
***
Function that writes character to **STDOUT**
```
/* Specifier : %c */
```
### printStr.c
***
Contain functions that prints strings of characters to the **STDOUT** and another function that Prints A String And ASCII Values Of Non-Printed Chars to **STDOUT**.
```
/* Specifier : %s or %S(ASCII values for non-print chars) */
```

### printint.c
***
Prints an integer to stdout
```
/* Indetifier : %i or %d */
```
### printUint.c
***
Prints unsigned int to stdout
```
/* Indetifier : %u */
```
## END
