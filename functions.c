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
	char c = va_arg(list, int);

	*(buffer + *bi) = c;
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
	char *str = va_arg(list, char *);

	if (!str)
		str = "(null)";
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

/**
 * func_rot - prints an array of chars
 * @buffer: a var
 * @bi: a var
 * @list: a list
 *
 * Description: it does something
 * Return: 1
 */

int func_rot(char *buffer, int *bi, va_list list)
{
	char values[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char newVal[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(list, char *);
	int i, j;
	int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == values[j])
			{
				buffer[(*bi)++] = newVal[j];
				len++;
				break;
			}
		}
	}
	(*bi)--;
	return (len);
}

