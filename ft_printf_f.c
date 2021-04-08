/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:09:52 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 16:24:08 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_f(const char *format, t_struct *f)
{
	while (format[f->i] == '0' || format[f->i] == '-')
	{
		if (format[f->i] == '0')
			f->zero = 1;
		else if (format[f->i] == '-')
			f->moins = 1;
		f->i++;
	}
}

void get_width(const char *format, va_list *arguments, t_struct *f)
{
	if (ft_strchr("0123456789", format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
			f->i++;
	}
	else if (format[f->i] == '*')
	{
		f->width = va_arg(*arguments, int);
		f->i++;
	}
	if (f->width < 0)
	{
		f->width = -f->width;
		f->moins = 1;
	}
}

void ft_printf_f(const char *format, va_list *arguments, t_struct *f)
{
	get_f(format, f); 
	get_width(format, arguments, f);

	if (format[f->i] == '.')
	{
		f->point = 1;
		f->i++;
		if (ft_strchr("0123456789", format[f->i]))
		{
			f->prec = ft_atoi(&format[f->i]);	
			while (ft_isdigit(format[f->i]))
				f->i++;
		}
		else if (format[f->i] == '*')
		{
			f->prec = va_arg(*arguments, int);
			f->i++;
		}
		if (f->prec < 0)
		{
			f->prec = 0;
			f->point = 0;
		}
	}
}

	
