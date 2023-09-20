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
	char buffer[BUFF_MAX];
	int i, bi = 0, Pchars = 0;

	if (!format)
		return (-1);
	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++, bi++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				reset_buffer(buffer, &bi);
				va_end(list);
				return (-1);
			}
			i++;
			Pchars += handle_var(format[i], buffer, &bi, list);
		}
		else
		{
			buffer[bi] = format[i];
			Pchars++;
		}
		if (bi + 1 >= BUFF_MAX)
			reset_buffer(buffer, &bi);
	}
	reset_buffer(buffer, &bi);
	va_end(list);
	return (Pchars);
}
