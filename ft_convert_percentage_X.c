/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_X.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:08:20 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 18:22:20 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_prec_sup_len(t_struct *f, int len, int res)
{
	if (res >= 0)
	{
		f->nbspaces = (f->width - f->prec <= 0) ? 0 : f->width - f->prec;
		f->len2 = f->prec - len;
		if (f->moins == 1)
		{
			ft_putchar_fd(f->chrzero, 1, f->len2);
			ft_putnbr_hexa(res, "0123456789ABCDEF");
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
		}
		else if (f->moins == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
			ft_putchar_fd(f->chrzero, 1, f->len2);
			ft_putnbr_hexa(res, "0123456789ABCDEF");
		}
	}
}
void	ft_point_un(t_struct *f, int len, int res)
{
	f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
	f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
	if (f->width != 0)
	{
		if (res >= 0)
		{
			if (f->moins == 1)
			{
				ft_putnbr_hexa(res, "0123456789ABCDEF");
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
			}
			else if (f->moins == 0)
			{
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
				ft_putnbr_hexa(res, "0123456789ABCDEF");
			}
		}
	}
	else  if (f->width == 0)
	{
		f->count += len;
		ft_putnbr_hexa(res, "0123456789ABCDEF");
	}
}

void	ft_convert_percentage_X(va_list *arguments, t_struct *f)
{
	long unsigned int res;
	long unsigned int tmp;
	int len;

	len = 0;
	res = va_arg(*arguments, unsigned int);
	tmp = res;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		len++;
	}
	len = 1;
	if (f->point == 1 && res == 0 && f->prec == 0)
	{
		if (f->width != 0)
			f->count += ft_putchar_fd(f->space, 1, f->width);
	}
	else if (f->prec >= len)
	{
		if (f->width != 0)
			ft_prec_sup_len(f, len, res);
		else if (f->width == 0)
		{
			f->len2 = f->prec - len;
			ft_putchar_fd(f->chrzero, 1, f->len2);
			ft_putnbr_hexa(res, "0123456789ABCDEF");
			f->count += f->prec;
		}
	}
	else if (f->prec < len && f->point == 1)
		ft_point_un(f, len, res);
	else if (f->prec < len && f->point == 0)
	{
		f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
		f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
		if (f->width != 0)
		{
			if (f->moins == 1)
			{
				ft_putnbr_hexa(res, "0123456789ABCDEF");
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
			}
			else if (f->moins == 0)
			{
				if (f->zero == 1)
				{
					f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + len;
					ft_putnbr_hexa(res, "0123456789ABCDEF");
				}
				else if (f->zero == 0)
				{
					f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
					ft_putnbr_hexa(res, "0123456789ABCDEF");
				}
			}
		}
		else  if (f->width == 0)
		{
			f->count += len;
			ft_putnbr_hexa(res, "0123456789ABCDEF");
		}
	}
}
