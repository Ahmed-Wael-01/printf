#include "main.h"

/**
 * func_char - prints a single char
 * @buffer: a var
 * @bi: a var
 * @list: a list
 *
 * Description: it does something
 * Return: 1
 */

int func_char(char *buffer, int *bi, va_list list)
{
	*(buffer + *bi) = (char)va_arg(list, int);
	return (1);
}

/**
 * func_percent - prints a single char
 * @buffer: a var
 * @bi: a var
 *
 * Description: it does something
 * Return: 1
 */

int func_percent(char *buffer, int *bi)
{
	*(buffer + *bi) = '%';
	return (1);
}

/**
 * func_int - prints an integer
 * @buffer: a var
 * @bi: a var
 * @list: a list
 *
 * Description: it does something
 * Return: 1
 */

int func_int(char *buffer, int *bi, va_list list)
{
	long int i = 1;
	long int n = va_arg(list, int);
	long int num;
	int counter = 1;
	int len = 0;

	if (n < 0)
	{
		num = -n;
		buffer[(*bi)++] = '-';
		len++;
	}
	else
		num = n;

	while (num / i > 9)
	{
		i *= 10;
		counter++;
	}

	if (!is_enough(bi, counter))
	{
		reset_buffer(buffer, bi);
		(*bi)++;
	}

	while (i > 0)
	{
		buffer[(*bi)++] = ('0' + ((num / i) % 10));
		len++;
		i /= 10;
	}
	*(bi) -= 1;
	return (len);
}

/**
 * func_string - prints an array of chars
 * @buffer: a var
 * @bi: a var
 * @list: a list
 *
 * Description: it does something
 * Return: 1
 */

int func_string(char *buffer, int *bi, va_list list)
{
	int i;
	int len;
	const char *str = va_arg(list, const char *);

	if (str)
	{
	len = _strlen(str);
	if (!is_enough(bi, len))
	{
		reset_buffer(buffer, bi);
		(*bi)++;
	}
	for (i = 0; i < len; i++)
		buffer[(*bi)++] = str[i];
	(*bi)--;
	return (len);
	}
	return (0);
}

