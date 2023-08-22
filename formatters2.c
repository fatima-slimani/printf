#include "main.h"

/**
 * _putoctal - writes the number n as octal to stdout
 * @n: The number to print
 *
 * Return: On success return the length of n.
 */
int _putoctal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += _putoctal(n / 8);
	_putchar(n % 8 + '0');
	return (count + 1);
}

/**
 * _puthexa - writes the number n as hexa to stdout
 * @n: The number to print
 * @uppercase: if 1 print number as uppercase
 * Return: On success return the length of n.
 */
int _puthexa(unsigned int n, int uppercase)
{
	int count = 0;

	if (n / 16)
		count += _puthexa(n / 16, uppercase);
	if (n % 16 < 10)
		_putchar(n % 16 + '0');
	else if (uppercase)
		_putchar(n % 16 - 10 + 'A');
	else
		_putchar(n % 16 - 10 + 'a');
	return (count + 1);
}


/**
 * _putAsci - writes characters as asci to stdout
 * @input: The characters to print
 *
 * Return: On success return the length of input.
 */
int _putAsci(const char *input)
{
	const char *current;

	current = input;
	while (*current != '\0')
	{
		if (*current < 32 || *current >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (*current < 16)
				_putchar('0');
			_puthexa(*current, 1);
		}
		else
			_putchar(*current);
		current++;
	}
	return (current - input);
}
