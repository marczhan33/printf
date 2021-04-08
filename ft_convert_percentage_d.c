/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:03:57 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 17:41:59 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_third(t_struct *f, int len2, long int res, int len)
{
	f->chrzero = '0';
	if (res < 0)
	{
		len2 = f->prec - len + 1;
		f->count += ft_putchar_fd('-', 1, 1);
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd((res * -1), 1);
		f->count += f->prec;
	}
	else
	{
		len2 = f->prec - len;
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd((res), 1);
		f->count += f->prec;
	}
}

void	ft_second(t_struct *f, int len2, long int res, int len)
{
	f->nbspaces = (f->width - f->prec - 1 <= 0) ? 0 : f->width - f->prec - 1;
	len2 = f->prec - len + 1;
	if (f->moins == 1)
	{
		f->count += ft_putchar_fd('-', 1, 1);
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd((res * -1), 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
	}
	else if (f->moins == 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
		f->count += ft_putchar_fd('-', 1, 1);
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd((res * -1), 1);
	}
}

void	ft_one(t_struct *f, int len2, long int res)
{
	f->nbspaces = (f->width - f->prec <= 0) ? 0 : f->width - f->prec;
	if (f->moins == 1)
	{
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd(res, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
	}
	else if (f->moins == 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
		ft_putchar_fd(f->chrzero, 1, len2);
		ft_putnbr_fd(res, 1);
	}
}

void	ft_prec_sup_len_global(t_struct *f, int res, int len)
{
	int len2;

	len2 = f->prec - len;
	if (f->width != 0)
	{
		if (res >= 0)
			ft_one(f, len2, res);
		else if (res < 0)
			ft_second(f, len2, res, len);
	}
	else if (f->width == 0)
		ft_third(f, len2, res, len);
}

void	ft_convert_percentage_d(va_list *arguments, t_struct *f)
{
	long int	res;
	int			len;

	res = va_arg(*arguments, int);
	len = ft_nbrlen(res);
	if (f->point == 1 && res == 0 && f->prec == 0)
	{
		if (f->width != 0)
			f->count += ft_putchar_fd(f->space, 1, f->width);
	}
	else if (f->prec >= len)
		ft_prec_sup_len_global(f, res, len);
	else if (f->prec < len && f->point == 1)
		ft_point_1_global(f, len, res);
	else if (f->prec < len && f->point == 0)
		ft_prec_inf_len_global(f, res, len);
}
