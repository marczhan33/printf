/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_percentage.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:36:10 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 18:04:31 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_non_zero(t_struct *f, char c)
{
	if (f->moins == 1)
	{
		f->count += f->count + write(1, &c, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
	}
	else
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros);
			f->count += write(1, &c, 1);
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
			f->count += write(1, &c, 1);
		}
	}
}

void	ft_convert_percentage_percentage(t_struct *f)
{
	char c;

	c = '%';
	f->nbzeros = (f->width - 1 <= 1) ? 0 : f->width - 1;
	f->nbspaces = (f->width - 1 <= 1) ? 0 : f->width - 1;
	if (f->width != 0)
		ft_width_non_zero(f, c);
	else
		f->count += ft_putchar_fd(c, 1, 1);
}
