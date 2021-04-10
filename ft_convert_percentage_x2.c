/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_x2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:48:34 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/10 15:52:57 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_moins_1_x(t_struct *f, long unsigned int res)
{
	if (f->moins == 1)
	{
		ft_putnbr_hexa(res, "0123456789abcdef");
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
	}
	else if (f->moins == 0)
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + f->len;
			ft_putnbr_hexa(res, "0123456789abcdef");
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
			ft_putnbr_hexa(res, "0123456789abcdef");
		}
	}
}
