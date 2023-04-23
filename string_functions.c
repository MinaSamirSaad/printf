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
*@args: list that contains the string
*Return: number of printed bytes of string
*/
int print_str(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);

	return (i);
}
