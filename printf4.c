#include "main.h"

/**
 * printf_int - format int
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_int(const char *input, va_list *list)
{
	input = tag(input, "d");
	if (!input)
		return (NULL);
	return (new_result(input, _putint(va_arg(*list, int))));
}

/**
 * printf_inti - format inti
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_inti(const char *input, va_list *list)
{
	input = tag(input, "i");
	if (!input)
		return (NULL);
	return (new_result(input, _putint(va_arg(*list, int))));
}

/**
 * printf_uint - format uint
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_uint(const char *input, va_list *list)
{
	input = tag(input, "u");
	if (!input)
		return (NULL);
	return (new_result(input, _putuint(va_arg(*list, unsigned int))));
}

/**
 * printf_binary - format binary
 * @input: string to print
 * @list: the va list
 * Return: new result of pointer and length
 */
result_t *printf_binary(const char *input, va_list *list)
{
	input = tag(input, "b");
	if (!input)
		return (NULL);
	return (new_result(input, _putbinary(va_arg(*list, unsigned int))));
}
