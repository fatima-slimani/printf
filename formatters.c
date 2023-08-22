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

/**
 * _putstr - writes the string input to stdout
 * @input: The string to print
 *
 * Return: On success return the length of input.
 */
int _putstr(const char *input)
{
	const char *current;

	current = input;
	while (*current != '\0')
	{
		_putchar(*current);
		current++;
	}
	return (current - input);
}


/**
 * _putint - writes the number n to stdout
 * @n: The number to print
 *
 * Return: On success return the length of n.
 */
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

/**
 * _putuint - writes the number n to stdout
 * @n: The number to print
 *
 * Return: On success return the length of n.
 */
int _putuint(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += _putuint(n / 10);
	_putchar(n % 10 + '0');
	return (count + 1);
}

/**
 * _putbinary - writes the number n as binary to stdout
 * @n: The number to print
 *
 * Return: On success return the length of n.
 */
int _putbinary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += _putbinary(n / 2);
	_putchar(n % 2 + '0');
	return (count + 1);
}
