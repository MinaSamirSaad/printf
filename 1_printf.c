#include "main.h"
/**
 * cntspaces - compute length of spaces in s
 * @s: string
 * Return: length of spaces
*/
int cntspaces(const char *s)
{
	int space = 0;

	while (s && *s == ' ')
	{
		++s;
		++space;
	}
	return (space);
}
/**
 * lenstr - compute length of s
 * @s: string
 * Return: length of s
*/
int lenstr(char *s)
{
	int len = 0;

	while (s && *s)
	{
		++s;
		++len;
	}
	return (len);
}
/**
 * _printf - printf mimic
 * @format: string
 * Return: number of printed
*/
int _printf(const char *format, ...)
{
	int res = 0, skipspaces = 0;
	char let, *st;
	va_list args;

	if (!format)
		return (res);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (++format))
		{
			switch (*format)
			{
				case 'c':
					let = va_arg(args, int);
					write(1, &let, 1);
					break;
				case 's':
					st = va_arg(args, char *);
					res += write(1, st, lenstr(st)) - 1;
					break;
				case '%':
					write(1, format, 1);
					break;
				default:
					write(1, format - 1, 2);
					/* count multi spaces after current space*/
					skipspaces = cntspaces(format + 1);
					/* skip multi spaces after % */
					/* and stop at last one */
					format += skipspaces, res++, skipspaces = 0;
			}
		}
		else
			write(1, format, 1);
		++format, ++res;
	}
	va_end(args);
	return (res);
}
