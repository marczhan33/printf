/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:09:52 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/30 15:49:12 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_flags(const char *format, t_struct *flags)
{
	while (format[flags->i] == '0' || format[flags->i] == '-')
	{
		if (format[flags->i] == '0')
			flags->zero = 1;
		else if (format[flags->i] == '-')
			flags->moins = 1;
		flags->i++;
	}
}

void get_width(const char *format, va_list *arguments, t_struct *flags)
{
	if (ft_strchr("0123456789", format[flags->i]))
	{
		flags->width = ft_atoi(&format[flags->i]);
		while (ft_isdigit(format[flags->i]))
			flags->i++;
	}
	else if (format[flags->i] == '*')
	{
		flags->width = va_arg(*arguments, int);
		flags->i++;
	}
}

void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags)
{
	get_flags(format, flags); 
	get_width(format, arguments, flags);

	if (format[flags->i] == '.')
	{
		flags->point = 1;
		flags->i++;
		if (ft_strchr("0123456789", format[flags->i]))
		{
			flags->precision = ft_atoi(&format[flags->i]);	
			while (ft_isdigit(format[flags->i]))
				flags->i++;
		}
		else if (format[flags->i] == '*')
		{
			flags->precision = va_arg(*arguments, int);
			flags->i++;
		}
	}
}

	
