#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstr(const char *input)
{
	char *current;

	current = input;
	while (*current != '\0')
	{
		_putchar(*current);
		current++;
	}
	return (current - input);
}
int _putint(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}
	if (n / 10)
		count += _putint(n / 10);
	_putchar(n % 10 + '0');
	return (count + 1);
}

int _putuint(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += _putuint(n / 10);
	_putchar(n % 10 + '0');
	return (count + 1);
}
int _putbinary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += _putbinary(n / 2);
	_putchar(n % 2 + '0');
	return (count + 1);
}
