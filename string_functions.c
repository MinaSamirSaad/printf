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
 * print_str - function prints string
 * @args: list that contains the string
 * @tag: s = normal string print - r = reverse string print
 * Return: number of printed bytes of string
 */
int print_str(va_list args, char tag)
{
	char *str;
	int i, j;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	if (tag == 's')
	{
		for (i = 0; str[i] != '\0'; i++)
			write(1, &str[i], 1);
	}
	else if (tag == 'r')
	{
		for (i = 0; str[i] != '\0'; i++)
			;

		for (j = i - 1; j >= 0; j--)
			write(1, &str[j], 1);
	}
	return (i);
}
/**
 * print_custom_str - function prints custom conversion specifier string
 * @args: list that contains the string
 * Return: number of printed bytes of string
 */
int print_custom_str(va_list args)
{
	unsigned char *str;
	char st[6] = "(null)";
	int res = 0;

	str = va_arg(args, unsigned char *);
	if (str == NULL)
		res += write(1, st, 6);
	else
	{
		while (*str != '\0')
		{
			if (*str < ' ' || *str >= 127)
			{
				res += write(1, "\\x", 2);
				res += write(1, "0123456789ABCDEF" + ((*str >> 4) & 0xF), 1);
				res += write(1, "0123456789ABCDEF" + (*str & 0xF), 1);
			}
			else
			{
				res += write(1, str, 1);
			}
			str++;
		}
	}
	return (res);
}
