/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_d2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:13:55 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 17:43:34 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point_1_global(t_struct *f, int len, long int res)
{
	f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
	f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
	if (f->width != 0)
	{
		if (f->moins == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
			ft_putnbr_fd(res, 1);
		}
		else if (f->moins == 1)
		{
			ft_putnbr_fd(res, 1);
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
		}
	}
	else if (f->width == 0)
	{
		f->count += len;
		ft_putnbr_fd(res, 1);
	}
}

void	ft_prec_inf_len3(t_struct *f, long int res, int len)
{
	if (f->moins == 0)
	{
		if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
			ft_putnbr_fd(res, 1);
		}
		else if (f->zero == 1)
		{
			ft_putchar_fd('-', 1, 1);
			ft_putchar_fd(f->chrzero, 1, f->nbzeros);
			ft_putnbr_fd((-1 * res), 1);
			f->count += len + f->nbzeros;
		}
	}
	else if (f->moins == 1)
	{
		ft_putnbr_fd(res, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
	}
}

void	ft_prec_inf_len_2(t_struct *f, long int res, int len)
{
	if (f->moins == 1)
	{
		ft_putnbr_fd(res, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
	}
	else if (f->moins == 0)
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + len;
			ft_putnbr_fd(res, 1);
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + len;
			ft_putnbr_fd(res, 1);
		}
	}
}

void	ft_prec_inf_len_global(t_struct *f, long int res, int len)
{
	f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
	f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
	if (f->width != 0)
	{
		if (res >= 0)
			ft_prec_inf_len_2(f, res, len);
		else if (res < 0)
			ft_prec_inf_len3(f, res, len);
	}
	else if (f->width == 0)
	{
		f->count += len;
		ft_putnbr_fd(res, 1);
	}
}
