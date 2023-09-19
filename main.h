#ifndef PRINT
#define PRINT

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#define BUFF_MAX 1024

int _printf(const char *format, ...);
int handle_var(const char spec, char *buffer, int *bi, va_list list);
int func_char(char *buffer, int *bi, va_list list);
int func_percent(char *buffer, int *bi);
int func_string(char *buffer, int *bi, va_list list);
int func_int(char *buffer, int *bi, va_list list);
int is_enough(int *bi, int len);
int _strlen(const char *s);
void reset_buffer(char *buff, int *pbi);
int func_octal(char *buffer, int *bi, va_list list);
int func_hexadecimal(char *buffer, int *bi, va_list list , int uppercase);
int func_pointer(char *buffer, int *bi, va_list list);
void reverse_string(char *str);
int func_reverse(char *buffer, int *bi, va_list list);
#endif
