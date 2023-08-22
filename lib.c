#include "main.h"

/**
 * new_result - create new result from pointer and length
 * @output: the result pointer
 * @length: the result length
 * Return: On success return the result,
 * else return NULL
 */
result_t *new_result(const char *output, int length)
{
	result_t *result;

	result = malloc(sizeof(result_t));
	if (!result)
		return (NULL);

	result->output = (char *) output;
	result->length = length;
	return (result);
}

/**
 * printf_formatted - wrapper to all formatters
 * @input: the formatted text
 * @list: the va list
 * Return: On success return the result,
 * else return NULL
 */
result_t *printf_formatted(const char *input, va_list *list)
{
	result_t *result;
	int i;
	printf_fn * formatters[] = {
		printf_space,
		printf_terminator,
		printf_string,
		printf_char,
		printf_percent,
		NULL};
	i = 0;

	while (formatters[i])
	{
		result = formatters[i](input, list);
		if (result)
			return (result);
		i++;
	}

	return (result);
}

/**
 * _doprintf - wrapper to all formatters and charachters printer
 * @fmt: the formatted text
 * @list: the va list
 * Return: On success return the result,
 * else return NULL
 */
int _doprintf(const char *fmt, va_list *list)
{
	int length;
	result_t *result;

	if (!fmt)
		return (-1);
	length = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			_putchar(*fmt);
			length++;
			fmt++;
		}
		else
		{
			fmt++; /* skip % */
			result = printf_formatted(fmt, list);
			if (result)
			{
				if (result->length == -1)
				{
					free(result);
					return (-1);
				}
				fmt = result->output;
				length += result->length;
				free(result);
			}
		}
	}
	return (length);
}

/**
 * _printf - prints a string with format
 * @format: the formatted text
 * Return: number of characters printed excluding
 * the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	va_list list;
	int done;

	va_start(list, format);
	done = _doprintf(format, &list);
	va_end(list);

	return (done);
}
