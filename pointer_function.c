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
	unsigned long int address;
	int printed = 0, i = 0;
	char ar[32];
	char convert_to[] = "0123456789abcdef";
	void *ptr = va_arg(args, void *);

	if (!ptr)
		printed = write(1, "(nil)", 5);
	else
	{
		address = (unsigned long int)ptr;
		while (address > 0)
		{
			ar[i] = convert_to[address % 16];
			address /= 16;
			i++;
			printed++;
		}
		ar[i++] = 'x';
		ar[i++] = '0';
		printed += 2;
		for (--i; i >= 0; i--)
			write(1, &ar[i], 1);
	}
	return (printed);
}
