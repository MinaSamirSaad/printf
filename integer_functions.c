#include "main.h"
/**
 * print_num - recursive function to print a number
 *@n: number to print
 *@c: length of the number
 *Return: counter
 */
int print_num(unsigned int n, int c)
{
	char num;

	if (n / 10)
		c = print_num(n / 10, c);

	num = n % 10 + '0';
	write(1, &num, 1);

	return (c + 1);
}

/**
 * print_integer - function that print an integer
 *@args: list that contains the format inserted
 *Return: counter of the integers printed
 */
int print_integer(va_list args, char flag)
{
	char negative = '-';
	char positive = '+';
	char space = ' ';
	int number, count = 0;
	unsigned int unSignNumber;

	number = va_arg(args, int);
	if (number < 0)
	{
		unSignNumber = number * -1;
		write(1, &negative, 1);
		count = print_num(unSignNumber, count);
		count += 1;
	}
	else
	{
		if (flag == '+')
			count += write(1, &positive, 1);
		if (flag == ' ')
			count += write(1, &space, 1);
		unSignNumber = number;
		count = print_num(unSignNumber, count);
	}
	return (count);
}
/**
 * print_unsigned_integer - function that print unsigned integer
 *@args: list that contains the format inserted
 * @tag: u=unsigned o=ocatal x,X=hexadecimal
 *Return: bytes of unsigned int printed
 */
int print_unsigned_integer(va_list args, char tag)
{
	int count = 0, i = 0, rem;
	char ar[32] = "0";
	unsigned int uNumber = va_arg(args, unsigned int);

	if (tag == 'u')
		count = print_num(uNumber, count);
	else
	{
		if (tag == 'o')
		{
			while (uNumber != 0)
			{
				ar[i] = uNumber % 8 + '0';
				uNumber /= 8, i++;
			}
		}
		else if (tag == 'x' || tag == 'X')
		{
			while (uNumber != 0)
			{
				rem = uNumber % 16;
				if (rem < 10)
					ar[i] = rem + '0';
				else
					ar[i] = (rem > 10 && tag == 'x') ? rem + 'W' : rem + '7';

				uNumber /= 16, i++;
			}
		}
		count = i > 0 ? i : 1;
		i = i > 0 ? i - 1 : 0;
		for (; i >= 0; i--)
			write(1, &ar[i], 1);
	}
	return (count);
}

int handle_unsigned_integer(va_list args, char tag)
{
	int res = 0;

	if (tag == 'o')
	{
		res += write(1, "0", 1);
		res += print_unsigned_integer(args, tag);
	}
	else if (tag == 'x' || 'X')
	{
		res += write(1, "0x", 2);
		res += print_unsigned_integer(args, tag);
	}
	return (res);
}
