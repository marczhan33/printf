/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:03:57 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/29 16:52:35 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (res !=  0)
	{
		res = res / 10;
		count ++;
	}
	return (count);
}

void ft_printd_precisionsup(t_struct *flags, int *len, int *res)
{
	int len2;
	char zero;
	char space;

	zero = 0;
	space = 32;
	len2 = flags->precision - *len;
	flags->nbofzeros = (flags->width - flags->precision <= 0) ? 0 : flags->width - flags->precision;
	if (flags->width != 0)
	{
		if (flags->moins == 1)
		{
			ft_putchar_fd(zero, 1, len2);
			ft_putnbr_fd(*res, 1);
			flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
		}
		else
		{
			if (flags->zero == 1 || flags->zero == 0)
			{
				flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
				ft_putchar_fd(zero, 1, len2);
				ft_putnbr_fd(*res, 1);
			}
		}
	}
	else 
	{
		ft_putchar_fd(zero, 1, len2); 
		ft_putnbr_fd(*res, 1);
		flags->count += flags->precision;
	}
}

void ft_convert_percentage_d(va_list * arguments, t_struct *flags)
{
	int res;
	char space;
	char zero;
	int len;

	res = va_arg(*arguments, int);
	len = ft_nbrlen(res);
	space = 32;
	zero = '0';
	if (flags->precision > len)
		ft_printd_precisionsup(flags, &len, &res);
	else 
	{
		flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
		flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
	}
	if (flags->width != 0)
	{
		if (flags->moins == 1)
		{
			ft_putnbr_fd(res, 1);
			flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
		}
		else
		{
			if (flags->zero == 1)
			{
				flags->count += ft_putchar_fd(zero, 1, flags->nbofzeros) + len;
				ft_putnbr_fd(res, 1);
			}
			else if (flags->zero == 0)
			{
				flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
				ft_putnbr_fd(res, 1);
			}
		}
	}
	else 
	{
		flags->count += len;
		ft_putnbr_fd(res, 1);
	}
}
