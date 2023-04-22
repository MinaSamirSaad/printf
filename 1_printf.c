#include "main.h"
/**
 * _printf - printf mimic
 * @format: string
 * Return: number of printed
*/
int _printf(const char *format, ...)
{
	int res = 0;
	va_list args;
	char let;
	char *st;

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
	    			if (!st)
	    				break;
	    			while (*st)
	    			{
	    				write(1, st, 1);
	    				++st;
	    				++res;
	    			}
	    			break;
	    		case '%':
	    			write(1, format, 1);
	    			break;
	    		default:
	    			write(1, format, 1);
    		}
    	}
    	else
    	{
    		write(1, format, 1);
    	}
    	++format;
    	++res;
	}
	va_end(args);

	return (res);
}
