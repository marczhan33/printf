/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:29:10 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/04 16:15:17 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_hexa(int nbr, char *base)
{
	int 			tab[100];
	int 			i;
	long int	 	longnb;

	i = 0;
	longnb = nbr;

	if (longnb == 0)
		write(1, &base[0], 1);
	if (longnb < 0)
	{
		longnb = -longnb;
		write (1, "-", 1);
	}
	while (longnb > 0)
	{
		tab[i++] = base[(longnb % 16)];
		longnb = longnb / 16;
	}
	while (i > 0)
		write(1, &tab[--i], 1);
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
			flags->count = ft_putchar_fd(space, 1, flags->width);
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
						flags->count = ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
						ft_putchar_fd(space, 1, flags->nbofzeros);
						ft_putnbr_fd(res, 1);
						flags->count = len + flags->nbofzeros;
					}
				}
				else if (flags->moins == 1)
				{
					if (flags->zero == 0 || flags->zero == 1)
					{
						ft_putnbr_fd(res, 1);
						flags->count = ft_putchar_fd(space, 1, flags->nbofspaces) + len;
					}
				}
			}
		}
		else  if (flags->width == 0)
		{
			if (res < 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
					}
				}
				else if (flags->moins == 1)
				{
					if (flags->zero == 0)
					{
					}
				}
			}
			if (res >= 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
					}
				}
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
						flags->count = ft_putchar_fd(space, 1, flags->nbofspaces) + len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
						ft_putchar_fd('-', 1, 1);
						ft_putchar_fd(zero, 1, flags->nbofzeros);
						ft_putnbr_fd((res * -1), 1);
						flags->count = len + flags->nbofzeros;
					}
				}
				else if (flags->moins == 1)
				{
					if (flags->zero == 0)
					{
						ft_putnbr_fd(res, 1);
						flags->count = ft_putchar_fd(space, 1, flags->nbofspaces) + len;
					}
				}
			}
		}
		else  if (flags->width == 0)
		{
			if (res < 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
					}
				}
				else if (flags->moins == 1)
				{
					if (flags->zero == 0)
					{
					}
				}
			}
			if (res >= 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += len;
						ft_putnbr_fd(res, 1);
					}
					else if (flags->zero == 1)
					{
					}
				}
			}
		}
	}
}
