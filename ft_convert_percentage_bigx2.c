/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_bigx2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:10:10 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 11:11:10 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_nonzero(t_struct *f, long unsigned int res)
{
	if (f->moins == 1)
	{
		ft_putnbr_hexa(res, "0123456789ABCDEF");
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
	}
	else if (f->moins == 0)
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + f->len;
			ft_putnbr_hexa(res, "0123456789ABCDEF");
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
			ft_putnbr_hexa(res, "0123456789ABCDEF");
		}
	}
}

void	ft_point_zero(t_struct *f, long unsigned int res)
{
	f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	if (f->width != 0)
		ft_width_nonzero(f, res);
	else if (f->width == 0)
	{
		f->count += f->len;
		ft_putnbr_hexa(res, "0123456789ABCDEF");
	}
}
