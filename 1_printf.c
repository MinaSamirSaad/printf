#include "main.h"
/**
 * skp_space_percent - goto last space after percent
 * @s: string
 * Return: last space in string pointer if existed
*/
const char *skp_space_percent(const char *s)
{
	while (s && *s == ' ' && *(s + 1) == ' ')
		++s;
	return (s);
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
 * nullCheck - compute length of s
<<<<<<< HEAD
 * @st: string
 * Return: length of s
*/
int nullCheck(char *st)
{
	int res = 0;

=======
 * @args: list that contains the format inserted
 * Return: res
*/
int nullCheck(va_list args)
{
	char *st;
	int res;

	st = va_arg(args, char *);
>>>>>>> 9df2f4346365441512c343d4706f63943b2ff2cf
	if (st == NULL)
	{
		st = "(null)";
		res += write(1, st, lenstr(st)) - 1;
	}
	else
	{
	res += write(1, st, lenstr(st)) - 1;
	}
	return (res);

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
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(++format))
				break;
			switch (*format)
			{
				case 'c':
					let = va_arg(args, int);
					write(1, &let, 1);
					break;
				case 's':
<<<<<<< HEAD
					st = va_arg(args, char *);
					res += nullCheck(st);
=======
					res += nullCheck(args);
>>>>>>> 9df2f4346365441512c343d4706f63943b2ff2cf
					break;
				case '%':
					write(1, format, 1);
					break;
				case '\0':
					res -= 2;
					break;
				default:
					write(1, format - 1, 2);
					format = skp_space_percent(format), res++;
			}
		}
		else
			write(1, format, 1);
		++format, ++res;
	}
	va_end(args);
	return (res > 0 ? res : -1);
}
