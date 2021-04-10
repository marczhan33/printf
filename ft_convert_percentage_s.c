/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_s.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:28:57 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/10 15:27:01 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_null_s1(t_struct *f, char *str)
{
	if (f->point == 0)
	{
		f->count += ft_putstr_fd(str, 1, f->len);
	}
	else if (f->prec == 0 && f->point == 1)
	{
		if (f->moins == 0)
			f->count += ft_putstr_fd(str, 1, f->len);
	}
	else if (f->prec != 0)
		f->count += ft_putstr_fd(str, 1, f->len);
}

void	ft_prec_positive(t_struct *f, char *str)
{
	if (f->moins == 0)
	{
		if (f->zero == 0)
		{
			f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
			f->count += ft_putstr_fd(str, 1, f->len);
		}
	}
	else if (f->moins == 1)
	{
		f->count += ft_putstr_fd(str, 1, f->len);
		f->count += ft_putchar_fd(f->space, 1, f->nbspaces);
	}
}

void	ft_len_s(t_struct *f, char *str)
{
	f->len = 6;
	if (f->point == 1 && f->prec == 0)
	{
		str = "";
		f->len = 0;
	}
	else if (f->prec != 0 && f->prec <= ft_strlen(str))
		f->len = f->prec;
	else
		f->len = ft_strlen(str);
	f->nbzeros = (f->width - f->len <= 0) ? 0 : f->width - f->len;
	f->nbspaces = (f->width - f->len <= 0) ? 0 : f->width - f->len;
}

void	ft_str_null(t_struct *f, char *str)
{
	str = "(null)";
	ft_len_s(f, str);
	if (f->width == 0)
		ft_width_null_s1(f, str);
	else if (f->width != 0)
	{
		if (f->prec != 0)
			ft_prec_positive(f, str);
		else if (f->point == 0)
			ft_point_zero_s(f, str);
		else if (f->prec == 0 && f->point == 1)
			f->count += ft_putchar_fd(f->space, 1, f->width);
	}
}

void	ft_convert_percentage_s(va_list *arguments, t_struct *f)
{
	char *str;

	str = va_arg(*arguments, char *);
	if (str == NULL)
		ft_str_null(f, str);
	else if (str != NULL)
	{
		ft_non_null_len(f, str);
		if (f->width != 0)
			ft_width_positif(f, str);
		else if (f->width == 0)
			ft_width_null_s(f, str);
	}
}
