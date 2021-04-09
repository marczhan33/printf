/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_u.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:12:08 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 17:07:00 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_prec_sup_len_u1(t_struct *f, unsigned int res)
{
	if (f->moins == 1)
	{
		ft_putchar_fd(f->chrzero, 1, f->len2);
		ft_putunsign_fd(res, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
	}
	else if (f->moins == 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->prec;
		ft_putchar_fd(f->chrzero, 1, f->len2);
		ft_putunsign_fd(res, 1);
	}
}

void	ft_prec_sup_len_u(t_struct *f, unsigned int res)
{
	if (f->width != 0)
	{
		f->nbspaces = (f->width - f->prec <= 0) ? 0 : f->width - f->prec;
		f->len2 = f->prec - f->len;
		ft_prec_sup_len_u1(f, res);
	}
	else if (f->width == 0)
	{	
		f->len2 = f->prec - f->len;
		ft_putchar_fd(f->chrzero, 1, f->len2); 
		ft_putunsign_fd((res), 1);
		f->count += f->prec;
	}
}

void	ft_prec_inf_len_1_u(t_struct *f, unsigned int res)
{
	f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	if (f->width != 0)
	{
		ft_putunsign_fd(res, 1);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
	}
	else  if (f->width == 0)
	{
		f->count += f->len;
		ft_putunsign_fd(res, 1);
	}
}

void	ft_prec_inf_len_2_u(t_struct *f, unsigned int res)
{
	if (f->width != 0)
	{	
		if (f->moins == 1)
		{
			ft_putunsign_fd(res, 1);
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
		}
		else if (f->moins == 0)
		{
			if (f->zero == 1)
			{
				f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros) + f->len;
				ft_putunsign_fd(res, 1);
			}
			else if (f->zero == 0)
			{
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces) + f->len;
				ft_putunsign_fd(res, 1);
			}
		}
	}
}

void ft_convert_percentage_u(va_list * arguments, t_struct *f)
{
	unsigned int res;

	res = va_arg(*arguments, unsigned int);
	f->len = ft_unsignedlen(res);
	if (f->point == 1 && res == 0 && f->prec == 0)
	{
		if (f->width != 0)
			f->count += ft_putchar_fd(f->space, 1, f->width);
	}
	else if (f->prec >= f->len)
		ft_prec_sup_len_u(f, res); 
	else if (f->prec < f->len && f->point == 1)
		ft_prec_inf_len_1_u(f, res);
	else if (f->prec < f->len && f->point == 0)
	{
		f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
		f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
		ft_prec_inf_len_2_u(f, res);
		if (f->width == 0)
		{
			f->count += f->len;
			ft_putunsign_fd(res, 1);
		}
	}
}
