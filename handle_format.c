#include "main.h"
/**
 * formatCases - have a bunch of cases to print
 * @format: character after %
 * @args: list of parameters to print
 * Return: amount of printed bytes
 **/
int formatCases(const char *format, va_list args)
{
	char let;
	int res = 0;

	switch (*format)
	{
		case 'c':
			let = va_arg(args, int);
			write(1, &let, 1);
			break;
		case 's':
			res += print_str(args) - 1;
			break;
		case '%':
			write(1, format, 1);
			break;
		case 'd':
		case 'i':
			res += print_integer(args), res--;
			break;
		case 'b':
		res += print_binary(args), res--;
		break;
		default:
			write(1, format - 1, 2);
			format = skp_space_percent(format), res++;
	}
	return (res);
}
/**
 * handle_format - compares the format given with a bunch of cases to print
 * @args: list of parameters
 * @format: input given
 * Return: amount of printed bytes
 **/
int handle_format(va_list args, const char *format)
{
	int res = 0;

	while (*format)
	{
		if (*format == '%')
		{
			if (!*(++format))
				break;
			res += formatCases(format, args);
		}
		else
			write(1, format, 1);
		++format, ++res;
	}
return (res);
}
