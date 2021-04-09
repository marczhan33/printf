/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:40:37 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 15:18:07 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_width_null(t_struct *f, uintptr_t res)
{
	f->len2 = f->prec - f->len;
	f->count += ft_putchar_fd('0', 1, 1);
	f->count += ft_putchar_fd('x', 1, 1);
	ft_putchar_fd(f->chrzero, 1, f->len2);
	ft_putnbr_hexa_p(res, "0123456789abcdef");
	f->count += f->prec;
}

void	ft_widt_positive(t_struct *f, uintptr_t res)
{
	f->nbspaces = (f->width - f->prec - 2 <= 0) ? 0 : f->width - f->prec - 2;
	f->len2 = f->prec - f->len;
	if (f->moins == 1)
	{
		f->count += ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
		ft_putchar_fd(f->chrzero, 1, f->len2);
		ft_putnbr_hexa_p(res, "0123456789abcdef");
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec - 2;
	}
	else if (f->moins == 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
		f->count += ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
		ft_putchar_fd(f->chrzero, 1, f->len2);
		ft_putnbr_hexa_p(res, "0123456789abcdef");
	}
}

void	ft_spec_case(t_struct *f, uintptr_t res)
{
	if (f->width != 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->width - 2);
		f->count += ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
	}
	else if (f->width == 0)
	{
		f->count += ft_putchar_fd('0', 1, 1);
		f->count += ft_putchar_fd('x', 1, 1);
	}
}

void	ft_len(t_struct *f, uintptr_t res)
{
	uintptr_t tmp;

	tmp = res;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		f->len++;
	}
	if (res == 0)
		f->len = 1;
}

void	ft_convert_percentage_p(va_list *arguments, t_struct *f)
{
	uintptr_t res;

	res = va_arg(*arguments, uintptr_t);
	ft_len(f, res);
	if (f->point == 1 && res == 0 && f->prec == 0)
		ft_spec_case(f, res);
	else if (f->prec >= f->len)
	{
		if (f->width != 0)
			ft_widt_positive(f, res);
		else if (f->width == 0)
			ft_width_null(f, res);
	}
	else if (f->prec < f->len && f->point == 1)
		ft_p_1(f, res);
	else if (f->prec < f->len && f->point == 0)
		ft_prec_inf_len(f, res);
}
