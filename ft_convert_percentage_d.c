/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:03:57 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/07 11:46:51 by mzhan            ###   ########.fr       */
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
	if (res < 0)
		count++;
	while (res !=  0)
	{
		res = res / 10;
		count ++;
	}
	return (count);
}


void ft_convert_percentage_d(va_list * arguments, t_struct *flags)
{
	int res;
	char space;
	char zero;
	int len;
	int len2;

	res = va_arg(*arguments, int);
	len = ft_nbrlen(res);
	space = 32;
	zero = '0';
	if (flags->point == 1 && res == 0 && flags->precision == 0)
	{
		if (flags->width != 0)
			flags->count += ft_putchar_fd(space, 1, flags->width);
	}
	else if (flags->precision >= len)
	{
		if (flags->width != 0)
		{
			if (res >= 0)
			{
				flags->nbofspaces = (flags->width - flags->precision <= 0) ? 0 : flags->width - flags->precision;
				len2 = flags->precision - len;
				if (flags->moins == 1)
				{
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_fd(res, 1);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
				}
				else if (flags->moins == 0)
				{
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_fd(res, 1);
				}
			}
			else if (res < 0)
			{
				flags->nbofspaces = (flags->width - flags->precision - 1 <= 0) ? 0 : flags->width - flags->precision - 1;
				len2 = flags->precision - len + 1;
				if (flags->moins == 1)
				{
					flags->count += ft_putchar_fd('-', 1, 1);
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_fd((res * -1), 1);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
				}
				else if (flags->moins == 0)
				{
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + flags->precision;
					flags->count += ft_putchar_fd('-', 1, 1);
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_fd((res * -1), 1);
				}
			}
		}
		else if (flags->width == 0)
		{
			if (res < 0)
			{

				len2 = flags->precision - len + 1;
				flags->count += ft_putchar_fd('-', 1, 1);
				ft_putchar_fd(zero, 1, len2); 
				ft_putnbr_fd((res * -1), 1);
				flags->count += flags->precision;
			}
			else
			{
				len2 = flags->precision - len;
				ft_putchar_fd(zero, 1, len2); 
				ft_putnbr_fd((res), 1);
				flags->count += flags->precision;
			}
		}
	}
	else if (flags->precision < len && flags->point == 1)
	{
		flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
		flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
		if (flags->width != 0)
		{
			if (res >= 0)
			{		
				if (flags->moins == 1)
				{
					ft_putnbr_fd(res, 1);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
				}
				else if (flags->moins == 0)
				{
					if (flags->zero == 1)
					{
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 0)
					{
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
				}
			}
			else if (res < 0)
			{
				if (flags->moins == 0)
				{
					if(flags->zero == 0)
					{
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
						ft_putchar_fd(space, 1, flags->nbofzeros);
						ft_putnbr_fd(res, 1);
						flags->count += len + flags->nbofzeros;
					}
				}
				else if (flags->moins == 1)
				{
					if (flags->zero == 0 || flags->zero == 1)
					{
						ft_putnbr_fd(res, 1);
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
					}
				}
			}
		}
		else  if (flags->width == 0)
		{
			if (res < 0)
			{
				flags->count += len;
				ft_putnbr_fd(res, 1);
			}
			if (res >= 0)
			{
				flags->count += len;
				ft_putnbr_fd(res, 1);
			}
		}
	}
	else if (flags->precision < len && flags->point == 0)
	{
		flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
		flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
		if (flags->width != 0)
		{
			if (res >= 0)
			{		
				if (flags->moins == 1)
				{
					ft_putnbr_fd(res, 1);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
				}
				else if (flags->moins == 0)
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
			else if (res < 0)
			{
				if (flags->moins == 0)
				{
					if(flags->zero == 0)
					{
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
						ft_putchar_fd('-', 1, 1);
						ft_putchar_fd(zero, 1, flags->nbofzeros);
						ft_putnbr_fd((res * -1), 1);
						flags->count += len + flags->nbofzeros;
					}
				}
				else if (flags->moins == 1)
				{
						ft_putnbr_fd(res, 1);
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces) + len;
				}
			}
		}
		else  if (flags->width == 0)
		{
			flags->count += len;
			ft_putnbr_fd(res, 1);
		}
	}
}
