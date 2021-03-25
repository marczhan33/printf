/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:09:52 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/25 17:03:10 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void get_width(const char *format, va_list *arguments, t_struct *flags)
{
	while (ft_strchr("cspdiuxX%", format[flags->i]) == '0' && format[flags->i] != '.' && format[flags->i] != '\0')
	{
		if (format[flags->i] == '0')
			flags->zero = 1;
		else if (format[flags->i] == '-')
			flags->moins = 1;
		else if (ft_strchr("0123456789", format[flags->i]))
			flags->width = ft_atoi(&format[flags->i]);
		else if (format[flags->i] == '*')
			flags->width = va_arg(*arguments, int);
		flags->i++; // le pb c est que si meme si c est un nombre a 10 chiffres pour le largeur de champs je n avance que de 1, faudrait surenebt faire un ITOA
	}
}


void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags)
{
	get_width(&format[flags->i], arguments, flags);

	if (format[flags->i] == '.')
	{
		flags->i++;
		if (ft_strchr("0123456789", format[flags->i]))
			flags->precision = ft_atoi(&format[flags->i]);
		else if (format[flags->i] == '*')
			flags->precision = va_arg(*arguments, int);
	}
}

	
