#ifndef LIB_H
#define LIB_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define NULL ((void *)0)

typedef struct result_t
{
	char *output;
	int length;
} result_t;

typedef result_t *printf_fn(const char *input, va_list *list);

int _printf(const char *fmt, ...);

result_t *printf_string(const char *input, va_list *list);
result_t *printf_char(const char *input, va_list *list);
result_t *printf_percent(const char *input, va_list *list);

/* utils */
#define isdigit(d) ((d) >= '0' && (d) <= '9')
#define Ctod(c) ((c) - '0')
#define INT_MAX 2147483647
#define MAXBUF (sizeof(long int) * 8) /* enough for binary */

/* parsing */
typedef int (*predicate_t)(char);
char *take(const char *input, int length);
char *take_while(const char *input, predicate_t predicate);
char *tag(const char *input, const char *pattern);
char *take_till(const char *input, char c);

/* printers */
int _putchar(char c);
int _putstr(const char *input);
int _putint(int n);
int _putinti(int n);
int _putuint(unsigned int n);
int _putbinary(unsigned int n);
int _putoctal(unsigned int n);
int _puthexa(unsigned int n, int uppercase);
int _putAsci(const char *input);
#endif /* LIB_H */
