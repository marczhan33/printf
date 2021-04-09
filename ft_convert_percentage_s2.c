/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_s2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:48:32 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 16:25:56 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_non_null_len(t_struct *f, char *str)
{
	if (f->prec != 0 && f->prec <= ft_strlen(str))
		f->len = f->prec;
	else
		f->len = ft_strlen(str);
	f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
}

void	ft_point_zero_s(t_struct *f, char *str)
{
	if (f->moins == 1)
	{
		f->count += ft_putstr_fd(str, 1, f->len);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
	}
	else if (f->moins == 0)
	{
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
		f->count += ft_putstr_fd(str, 1, f->len);
	}
}

void	ft_width_positif2(t_struct *f, char *str)
{
	if (f->moins == 1)
	{
		f->count += ft_putstr_fd(str, 1, f->len);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
	}
	else if (f->moins == 0)
	{
		if (f->zero == 1)
		{
			f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros);
			f->count += ft_putstr_fd(str, 1, f->len);
		}
		else if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
			f->count += ft_putstr_fd(str, 1, f->len);
		}
	}
}

void	ft_width_positif(t_struct *f, char *str)
{
	if (f->point == 1 && f->prec == 0)
		f->count += ft_putchar_fd(f->space, 1, f->width);
	else if (f->prec != 0 && f->point == 1)
		ft_width_positif2(f, str);
	else if (f->point == 0 && f->prec == 0)
	{
		if (f->moins == 1)
		{
			f->count += ft_putstr_fd(str, 1, f->len);
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
		}
		else if (f->moins == 0)
		{
			if (f->zero == 1)
			{
				f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros);
				f->count += ft_putstr_fd(str, 1, f->len);
			}
			else if (f->zero == 0)
			{
				f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
				f->count += ft_putstr_fd(str, 1, f->len);
			}
		}
	}
}

void	ft_width_null_s(t_struct *f, char *str)
{
	if (f->point == 1 && f->prec == 0)
	{
	}
	else if (f->point == 1 && f->prec != 0)
	{
		if (f->moins == 1)
		{
			f->count += ft_putstr_fd(str, 1, f->len);
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
		}
		else if (f->moins == 0)
		{
			if (f->zero == 1)
			{
				f->count += ft_putchar_fd(f->chrzero, 1, f->nbzeros);
				f->count += ft_putstr_fd(str, 1, f->len);
			}
			else if (f->zero == 0)
				f->count += ft_putstr_fd(str, 1, f->len);
		}
	}
}
