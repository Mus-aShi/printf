#include "main.h"

/**
 * _isdigit - checks if its digit
 * @c: the char to check
 *
 * Return: 1 if digit, 0 if not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the lenght of str
 * @s: the string to check
 *
 * Return: the lenght of str
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print number
 * @str: the base number as a string
 * @params: parameters struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int ng = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (ng)
	{
		str++;
		i--;
	}
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (ng)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with option
 * @str: the base num as a string
 * @params: the param struct
 *
 * Return: char printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, ng1, ng2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = ' ';
	ng1 = ng2 = (!params->unsign && *str == '-');
	if (ng && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		ng1 = 0;
	if ((params->plus_flag && !ng2) || (!params->plus_flag
				&& params->space_flag && !ng2))
		i++;
	if (ng && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !ng2 && pad_char == '0' && !parmas->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ng2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (ng1 && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !ng2 && pad_char == ' ' && !parmas->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ng2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - print num with option
 * @str: the base number as str
 * @params: the params struct
 *
 * Return: char printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, ng1, ng2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	ng1 = ng2 = (!params->unsign && *str == '-');
	if (ng1 && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		ng1 = 0;

	if (params->plus_flag && !ng2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !ng2 !params->unsign)
		n += _putchar ('-'), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
