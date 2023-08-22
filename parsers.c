#include "main.h"

/**
 * take - take a number of characters
 * @input: string to check
 * @length: number of characters to take
 * returns: pointer to the end of the found string otherwise NULL
 */
char *take(const char *input, int length)
{
	while (*input != '\0' && length > 0)
	{
		length--;
		input++;
	}
	if (length > 0)
		return (NULL);

	return ((char *)input);
}
/**
 * take_while - take characters while a predicate is true
 * @input: string to check
 * @predicate: function to check
 * returns: pointer to the end of the found string
 */
char *take_while(const char *input, predicate_t predicate)
{
	while (*input != '\0' && predicate(*input))
		input++;

	return ((char *)input);
}

/**
 * tag - recognize a pattern in a string
 * @input: string to check
 * @pattern: string to compare
 *
 * Returns: pointer to the end of the found pattern otherwise NULL
 */
char *tag(const char *input, const char *pattern)
{

	while (*input != '\0' && *pattern != '\0' && *input == *pattern)
	{
		input++;
		pattern++;
	}
	if (*pattern != '\0')
		return (NULL);

	return ((char *)input);
}

/**
 * take_till - take characters until a character is found
 * @input: string to check
 * @c: character to check
 * returns: pointer to the end of the found string otherwise NULL
 */
char *take_till(const char *input, char c)
{
	while (*input != '\0' && *input != c)
		input++;

	if (*input != c)
		return (NULL);

	return ((char *)input);
}
