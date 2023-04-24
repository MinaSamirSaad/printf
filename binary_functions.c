#include "main.h"
/**
* print_binary - function prints binary numbers
*@args: list that contains the number to convert
*Return: number of printed bytes of binary numbers
*/
int print_binary(va_list args)
{
int a[33], i, j, res = 0;
unsigned int  number, binary;
number = va_arg(args, int);
for (i = 0; number > 0; i++)
{
a[i] = number % 2;
number = number / 2;
}
for (j = i - 1; j >= 0; j--)
{
binary = a[j] + '0';
res += write(1, &binary, 1);
}
return (res);
}
