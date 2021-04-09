/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_p2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:11:15 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 15:15:46 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_p_1(t_struct *f, uintptr_t res)
{
	f->nbzeros = (f->width - f->len - 2 <= 0) ? 0 : f->width - f->len - 2;
	f->nbspaces = (f->width - f->len - 2 <= 0) ? 0 : f->width - f->len - 2;
	if (f->width != 0)
	{
		if (f->moins == 1)
		{
			ft_putnbr_hexa_p(res, "0123456789abcdef");
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
		}
		else if (f->moins == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x', 1, 1);
			ft_putnbr_hexa_p(res, "0123456789abcdef");
		}
	}
	else if (f->width == 0)
	{
		f->count += f->len;
		ft_putnbr_hexa_p(res, "0123456789abcdef");
	}
}

void	ft_prec_inf_len(t_struct *f, uintptr_t res)
{
	f->nbzeros = (f->width - f->len - 2 <= 0) ? 0 : f->width - f->len - 2;
	f->nbspaces = (f->width - f->len - 2 <= 0) ? 0 : f->width - f->len - 2;
	if (f->width != 0)
		ft_width2(f, res);
	else if (f->width == 0)
	{
		f->count += f->len + ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
		ft_putnbr_hexa_p(res, "0123456789abcdef");
	}
}

void	ft_width_2(t_struct *f, uintptr_t res)
{
	if (f->moins == 1)
	{
		f->count += ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
		ft_putnbr_hexa_p(res, "0123456789abcdef");
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
	}
	else if (f->moins == 0)
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + f->len;
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x', 1, 1);
			ft_putnbr_hexa_p(res, "0123456789abcdef");
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putchar_fd('x', 1, 1);
			ft_putnbr_hexa_p(res, "0123456789abcdef");
		}
	}
}
