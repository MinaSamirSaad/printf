#include "main.h"
/**
 * _printf - mimic printf from stdio to standard output
 * @format: input to print
 * Return: printed bytes
 */
int _printf(const char *format, ...)
{
	int printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed = handle_format(args, format);

	va_end(args);

	return (printed > 0 ? printed : -1);
}
