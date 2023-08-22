#include "main.h"

/**
 * printf_octal - format octal
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_octal(const char *input, va_list *list)
{
	input = tag(input, "o");
	if (!input)
		return (NULL);
	return (new_result(input, _putoctal(va_arg(*list, unsigned int))));
}

/**
 * printf_hexa - format hexa
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_hexa(const char *input, va_list *list)
{
	input = tag(input, "x");
	if (!input)
		return (NULL);
	return (new_result(input, _puthexa(va_arg(*list, unsigned int), 0)));
}

/**
 * printf_heXa - format heXa
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_heXa(const char *input, va_list *list)
{
	input = tag(input, "X");
	if (!input)
		return (NULL);
	return (new_result(input, _puthexa(va_arg(*list, unsigned int), 1)));
}

/**
 * printf_asci - format asci
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_asci(const char *input, va_list *list)
{
	input = tag(input, "S");
	if (!input)
		return (NULL);
	return (new_result(input, _putAsci(va_arg(*list, char *))));
}
