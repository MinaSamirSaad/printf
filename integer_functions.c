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
int print_integer(va_list args)
{
char negative = '-';
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
		unSignNumber = number;
		count = print_num(unSignNumber, count);
	}
	return (count);
}
