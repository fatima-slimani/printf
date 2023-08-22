#include "main.h"

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


result_t *printf_formatted(const char *input, va_list *list)
{
	result_t *result;
	int i;
	printf_fn * formatters[] = {
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

int _doprintf(const char *fmt, va_list *list)
{
	int length;
	result_t *result;

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
 * returns: number of characters printed excluding
 * the null byte used to end output to strings
 */
int _printf(const char *fmt, ...)
{
	va_list list;
	int done;

	va_start(list, fmt);
	done = _doprintf(fmt, &list);
	va_end(list);

	return (done);
}
