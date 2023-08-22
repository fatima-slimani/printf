#include "main.h"

result_t *printf_string(const char *input, va_list *list)
{
	char *str;

	input = (char *)tag(input, "s");
	if (!input)
		return (NULL);
	str = va_arg(*list, char *);
	if (!str)
		str = "(null)";
	return (new_result(input, _putstr(str)));
}

result_t *printf_char(const char *input, va_list *list)
{
	input = (char *)tag(input, "c");
	if (!input || _putchar(va_arg(*list, int)) != 1)
		return (NULL);
	return (new_result(input, 1));
}

result_t *printf_percent(const char *input, va_list *list)
{
	list = list;
	input = (char *)tag(input, "%");
	if (!input || _putchar('%') != 1)
		return (NULL);
	return (new_result(input, 1));
}
