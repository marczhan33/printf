#include "ft_printf.h"

int ft_nbrlen(int res)
{
	int count;

	count = 0;
	if (res == 0)
	{
		count = 1;
		return (count);
	}
	if (res < 0)
		count++;
	while (res != 0)
	{
		res = res / 10;
		count ++;
	}
	return (count);
}

void ft_convert_percentage_d(va_list *arguments, t_struct *flags)
{
	int res;
	int space;
	char zero;
	int nblen;
	int len2;

	res = va_arg(*arguments, int);
	nblen = ft_nbrlen(res);
	space = 32;
	zero = '0';

	if (flags->point == 1 && flags->precision > nblen)
	{
		flags->nbofspaces = (flags->width - flags->precision <= 0) ? 0 : flags->width - flags->precision;
		if (res < 0)
		{
			len2 = flags->precision - nblen + 1;
			if (flags->width != 0)
			{




			}
		}
		if (res >= 0)
		{
			len2 = flags->precision - nblen;
		}
	}
}
			




