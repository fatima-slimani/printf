#include "main.h"

/**
 * printf_terminator - return empty result if is \0
 * @input: string to print
 * @list: the va list
 * Return: NULL else empty result
 */
result_t *printf_terminator(const char *input, va_list *list)
{
	list = list;
	if (*input == '\0')
		return (new_result(NULL, -1));
	return (NULL);
}

/**
 * is_space - check caracter is space
 * @c: char
 * Return: true if c is space
 */
int is_space(char c)
{
	return (c == ' ');
}

/**
 * printf_space - ignore spaces
 * @input: string to print
 * @list: the va list
 * Return: NULL else empty result
 */
result_t *printf_space(const char *input, va_list *list)
{
	list = list;
	input = (char *)tag(input, " ");
	if (!input)
		return (NULL);
	if (*input == '\0')
	{
		return (new_result(NULL, -1));
	}
	return (printf_formatted(input, list));
}
