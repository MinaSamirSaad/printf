#include "main.h"
/**
 * print_address - print %p as 0x hexadecimal
 * @args: list from we get address of pointer
 * if (pointer is null) print (nil)
 * else printe hexademical representaion of address
 * Return: printed characaters
*/
int print_address(va_list args)
{
	unsigned long address;
	int printed = 0, rem, i = 0;
	char ar[32] = "(nil)";
	void *ptr = va_arg(args, void *);

	if (!ptr)
		printed = write(1, ar, 5);
	else
	{
		address = (unsigned long) ptr;
		while (address != 0)
		{
			rem = address % 16;
			ar[i] = rem < 10 ? rem + '0' : rem + 'W';
			address /= 16;
			i++;
		}
		ar[i++] = 'x';
		ar[i++] = '0';
		printed = i;
		for (--i; i >= 0; i--)
			write(1, &ar[i], 1);
	}
	return (printed);
}
