#include "main.h"
/**
 * printstr - print string
 * @s: string
 * Return: number of printed
*/
int printstr(char *s)
{
	int printed = 0;

	while (s && *s)
	{
		write(1, s, 1);
		++s;
		++printed;
	}
	return (printed);
}
/**
 * _printf - printf mimic
 * @format: string
 * Return: number of printed
*/
int _printf(const char *format, ...)
{
	int res = 0;
	char let, *st;
	va_list args;

	if (!format)
		return (res);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (!format)
				break;
			switch (*format)
			{
				case 'c':
					let = va_arg(args, int);
					write(1, &let, 1);
					break;
				case 's':
					st = va_arg(args, char *);
					res--;
					res += printstr(st);
					break;
				case '%':
					write(1, format, 1);
				default:
					write(1, forma - 1, 2);
					res++;
			}
		}
		else
			write(1, format, 1);
		++format;
		++res;
	}
	va_end(args);
	return (res);
}
