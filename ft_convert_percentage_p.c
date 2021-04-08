/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:40:37 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 16:18:39 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void ft_putnbr_hexa_p(uintptr_t nbr, char *base)
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
	while (longnb !=  0)
	{
		tab[i++] = base[(longnb % 16)];
		longnb = longnb / 16;
	}
	while (i > 0)
		write(1, &tab[--i], 1);
}

void ft_convert_percentage_p(va_list *arguments, t_struct *f)
{
	void *str;
	uintptr_t res;
	uintptr_t tmp;
	char space;
	char zero;
	int len;
	int len2;

	len = 0;
	str  = va_arg(*arguments, void *);
	tmp = (uintptr_t)str;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		len++;
	}
	res = (uintptr_t)str;
	space = 32;
	zero = '0';
	if (res == 0)
		len = 1;
	if (f->point == 1 && res == 0 && f->prec == 0) 
	{
		if (f->width != 0) 
		{
			f->count += ft_putchar_fd(space, 1, f->width - 2);
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x', 1, 1);
		}
		else if (f->width == 0)
		{
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x', 1, 1);
		}
	}
	else if (f->prec >= len)
	{
		if (f->width != 0)
		{
			if (res >= 0)
			{
				f->nbspaces = (f->width - f->prec - 2 <= 0) ? 0 : f->width - f->prec - 2;
				len2 = f->prec - len;
				if (f->moins == 1)
				{
					f->count += ft_putchar_fd('0', 1, 1);
					f->count += ft_putchar_fd('x', 1, 1);
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_hexa_p(res, "0123456789abcdef");
					f->count += ft_putchar_fd(space, 1, f->nbspaces) + f->prec - 2;
				}
				else if (f->moins == 0)
				{
					f->count += ft_putchar_fd(space, 1, f->nbspaces) + f->prec;
					f->count +=	ft_putchar_fd('0', 1, 1);
					f->count +=	ft_putchar_fd('x', 1, 1);
					ft_putchar_fd(zero, 1, len2);
					ft_putnbr_hexa_p(res, "0123456789abcdef");
				}
			}
		}
		else if (f->width == 0)
		{
			{
				len2 = f->prec - len;
				f->count += ft_putchar_fd('0', 1, 1);
				f->count += ft_putchar_fd('x', 1, 1);
				ft_putchar_fd(zero, 1, len2);
				ft_putnbr_hexa_p(res, "0123456789abcdef");
				f->count += f->prec;
			}
		}
	}
	else if (f->prec < len && f->point == 1)
	{
		f->nbzeros = (f->width - len - 2<= 0) ? 0 : f->width - len - 2;
		f->nbspaces = (f->width - len - 2<= 0) ? 0 : f->width - len - 2;
		if (f->width != 0)
		{
			if (res >= 0)
			{
				if (f->moins == 1)
				{
					ft_putnbr_hexa_p(res, "0123456789abcdef");
					f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
				}
				else if (f->moins == 0)
				{
					if (f->zero == 1)
					{
						f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
						f->count += ft_putchar_fd('0', 1, 1);
						f->count += ft_putchar_fd('x', 1, 1);
						ft_putnbr_hexa_p(res, "0123456789abcdef");
					}
					else if (f->zero == 0) 
					{
						f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
						f->count += ft_putchar_fd('0', 1, 1);
						f->count += ft_putchar_fd('x', 1, 1);
						ft_putnbr_hexa_p(res, "0123456789abcdef");
					}
				}
			}
		}
		else  if (f->width == 0)
		{
			f->count += len;
			ft_putnbr_hexa_p(res, "0123456789abcdef");
		}
	}
	else if (f->prec < len && f->point == 0)
	{
		f->nbzeros = (f->width - len - 2 <= 0) ? 0 : f->width - len - 2;
		f->nbspaces = (f->width - len - 2 <= 0) ? 0 : f->width - len - 2;
		if (f->width != 0)
		{
			if (res >= 0)
			{
				if (f->moins == 1)
				{
					f->count += ft_putchar_fd('0', 1, 1);
					f->count += ft_putchar_fd('x', 1, 1);
					ft_putnbr_hexa_p(res, "0123456789abcdef");
					f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
				}
				else if (f->moins == 0)
				{
					if (f->zero == 1)
					{
						f->count += ft_putchar_fd(zero, 1, f->nbzeros) + len;

						f->count += ft_putchar_fd('0', 1, 1);
						f->count += ft_putchar_fd('x', 1, 1);
						ft_putnbr_hexa_p(res, "0123456789abcdef");
					}
					else if (f->zero == 0)
					{
						f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
						f->count += ft_putchar_fd('0', 1, 1);
						f->count += ft_putchar_fd('x', 1, 1);
						ft_putnbr_hexa_p(res, "0123456789abcdef");
					}
				}
			}
		}
		else  if (f->width == 0)
		{
			f->count += len + ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x',1 ,1) ;
			ft_putnbr_hexa_p(res, "0123456789abcdef");
		}
	}
}
