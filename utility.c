#include "main.h"

/**
 * handle_var - it handles which function to call based on the specifier
 * @spec: the string format
 * @buffer: the string format
 * @bi: the string format
 * @list: the string format
 *
 * Description: it does MAGIC
 * Return: the size of printed chars
 */

int handle_var(const char spec, char *buffer, int *bi, va_list list)
{
	switch (spec)
	{
	case 'c':
		return (func_char(buffer, bi, list));
	case '%':
		return (func_percent(buffer, bi));
	case 's':
		return (func_string(buffer, bi, list));
	case 'd':
		return (func_int(buffer, bi, list));
	case 'i':
		return (func_int(buffer, bi, list));
	case '\0':
		return (0);
	case 'o':
	        return ( func_octal(buffer, bi, list));	
	case 'x':
		return (func_hexadecimal(buffer, bi, list , 0));
	case 'X':
	         return func_hexadecimal(buffer, bi, list, 1);
        case 'p':
                 return func_pointer(buffer, bi, list);
	case 'r':
                return func_reverse(buffer, bi, list);	 
	default:
		return (0);
	}
}

/**
 * is_enough - it checks if there is enough space in the buffer
 * @len: the string format
 * @bi: the string format
 *
 * Description: it does MAGIC
 * Return: the size of printed chars
 */

int is_enough(int *bi, int len)
{
	if ((BUFF_MAX - *bi) > len)
		return (1);
	return (0);
}

/**
 * _strlen - does something
 * @s: a variable
 *
 * Description: a function
 * Return: 0
*/

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * reset_buffer - writes the buffer and resets it's counter
 * @buff: a variable
 * @pbi: a variable
 *
 * Description: a function
*/

void reset_buffer(char *buff, int *pbi)
{
	write(1, buff, *pbi);
	*pbi = -1;
}

