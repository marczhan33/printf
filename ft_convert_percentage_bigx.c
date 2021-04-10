/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_bigx.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:10:56 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/10 12:27:49 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point_un(t_struct *f, long unsigned int res)
{
	f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	if (f->width != 0)
	{
		if (res >= 0)
		{
			if (f->moins == 1)
			{
				ft_putnbr_hexa(res, "0123456789ABCDEF");
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
			}
			else if (f->moins == 0)
			{
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
				ft_putnbr_hexa(res, "0123456789ABCDEF");
			}
		}
	}
	else if (f->width == 0)
	{
		f->count += f->len;
		ft_putnbr_hexa(res, "0123456789ABCDEF");
	}
}

void	ft_prec_sup_len(t_struct *f, long unsigned int res)
{
	if (res >= 0)
	{
		f->nbspaces = (f->width - f->prec <= 0) ? 0 : f->width - f->prec;
		f->len2 = f->prec - f->len;
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

void	ft_prec_sup_global(t_struct *f, long unsigned int res)
{
	if (f->width != 0)
		ft_prec_sup_len(f, res);
	else if (f->width == 0)
	{
		f->len2 = f->prec - f->len;
		ft_putchar_fd(f->chrzero, 1, f->len2);
		ft_putnbr_hexa(res, "0123456789ABCDEF");
		f->count += f->prec;
	}
}

void	ft_len_hexa(t_struct *f, long unsigned int res)
{
	long unsigned int tmp;

	tmp = res;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		f->len++;
	}
	if (res == 0)
		f->len = 1;
}

void	ft_convert_percentage_bigx(va_list *arguments, t_struct *f)
{
	long unsigned int res;

	res = va_arg(*arguments, unsigned int);
	ft_len_hexa(f, res);
	if (f->point == 1 && res == 0 && f->prec == 0)
	{
		if (f->width != 0)
			f->count += ft_putchar_fd(f->space, 1, f->width);
	}
	else if (f->prec >= f->len)
		ft_prec_sup_global(f, res);
	else if (f->prec < f->len && f->point == 1)
		ft_point_un(f, res);
	else if (f->prec < f->len && f->point == 0)
		ft_point_zero(f, res);
}
