#include "main.h"

/**
 * print_char - print char
 * @ap: arg ptr
 * @params: param struct
 *
 * Return: n of char printed
 */
int print_char(va_list ap, params_t *params)
{
	char pd_char = ' ';
	unsigned int pd = 1, count = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		count += _putchar(ch);
	while (pd++ < params->width)
		count += _putchar(pd_char);
	if (!params->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * print_int - print inttegers
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number of char printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_str - print str
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: n of chars printed
 */
int print_str(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pd_char = ' ';
	unsigned int pd = 0, count = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;
	j = pd = _strlen(str);
	if (params->precision < pd)
		j = pd = params->precision;
	if (params->minus_flag)
	{
		if (params->precision != UNIT_MAX)
			for (i = 0; i < pd; i++)
				count += _putchar(*str++);
		else
			count += _puts(str);
	}
	while (j++ < params->width)
		count += _putchar(pd_char);
	if (!params->minus_flag)
	{
		if (params->precision != UNIT_MAX)
			for (i = 0; i < pd; i++)
				count += _putchar(*str++);
		else
			count  += _puts(str);
	}
	return (count);
}

/**
 * print_percent - print sting
 * @ap: arg ptr
 * @params: struct params
 *
 * Return: number of chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_s - custom format specifier
 * @ap: arg ptr
 * @params: struct params
 *
 * Return: number of chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int count = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (*str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				count += _putchar('0');
			count += _puts(hex);
		}
		else
		{
			count += _putchar(*str);
		}
	}
	return (count);
}
