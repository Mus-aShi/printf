#include "main.h"

/**
 * _puts - print str with new line
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - write a char
 * @c: the char to print
 *
 * Return: 1 on success and -1 on error
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_SIZE || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buf[i++] = c;
	return (1);
}
