#include "main.h"

/**
 * _printf - prints anything to the screen
 * @format: the string format
 *
 * Description: it does MAGIC
 * Return: the size of printed chars
 */

int _printf(const char *format, ...)
{
	va_list list;
	char *buffer;
	int i, bi = 0, Pchars = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	buffer = malloc(BUFF_MAX);
	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++, bi++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			Pchars += handle_var(format[i], buffer, &bi, list);

		}
		else
		{
			buffer[bi] = format[i];
			Pchars++;
		}
		if (bi + 2 >= BUFF_MAX)
			reset_buffer(buffer, &bi);
	}
	reset_buffer(buffer, &bi);
	free(buffer);
	va_end(list);
	return (Pchars);
}
