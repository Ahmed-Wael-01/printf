#include "main.h"

/**
 * func_octal - prints octal
 * @buffer: var
 * @bi: var
 * @list: a list
 *
 * Description: it does something
 * Return: i
 */

int func_octal(char *buffer, int *bi, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char octalRepresentation[12];
	int i = 0;

	do {
		octalRepresentation[i++] = '0' + (num % 8);
		num /= 8;
	} while (num > 0);
	while (i > 0)
	{
		*(buffer + (*bi)++) = octalRepresentation[--i];
	}
	(*bi)--;
	return (i);
}

/**
 * func_hexadecimal - prints octal
 * @buffer: var
 * @bi: var
 * @list: a list
 * @uppercase: a var
 *
 * Description: it does something
 * Return: i
 */

int func_hexadecimal(char *buffer, int *bi, va_list list, int uppercase)
{
	int i;
	unsigned int num = va_arg(list, unsigned int);
	char hexDigitsLower[] = "0123456789abcdef";
	char hexDigitsUpper[] = "0123456789ABCDEF";
	char *hexDigits = uppercase ? hexDigitsUpper : hexDigitsLower;
	char hexRepresentation[9];

	i = 0;
	do {
		hexRepresentation[i++] = hexDigits[num % 16];
		num /= 16;
	} while (num > 0);
	while (i > 0)
	{
		*(buffer + (*bi)++) = hexRepresentation[--i];
	}
	(*bi)--;
	return (i);
}

/**
 * func_pointer - prints octal
 * @buffer: var
 * @bi: var
 * @list: a list
 *
 * Description: it does something
 * Return: i
 */

int func_pointer(char *buffer, int *bi, va_list list)
{
	int i;
	uintptr_t address = (uintptr_t)va_arg(list, void *);
	char hexDigits[] = "0123456789abcdef";
	char hexRepresentation[17];

	buffer[(*bi)++] = '0';
	buffer[(*bi)++] = 'x';

	i = 0;
	do {
	hexRepresentation[i++] = hexDigits[address % 16];
	address /= 16;
	} while (address > 0);

	while (i > 0)
	{
		*(buffer + (*bi)++) = hexRepresentation[--i];
	}
	(*bi)--;
	return (i + 2);
}

/**
 * func_reverse - prints octal
 * @buffer: var
 * @bi: var
 * @list: a list
 *
 * Description: it does something
 * Return: i
 */

int func_reverse(char *buffer, int *bi, va_list list)
{
	char *str = va_arg(list, char *);
	int i = 0;
	int len;

	if (str[i] == '\0')
		return(0);
	while (str[i + 1] != '\0')
		i++;
	len = i + 1;
	while (i >= 0)
	{
		buffer[(*bi)++] = str[i];
		i--;
	}
	(*bi)--;

	return (len);
}
