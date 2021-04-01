/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:47:31 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/01 17:08:11 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_convert_percentage_s(va_list *arguments, t_struct *flags)
{
	int len;
	char space;
	char zero;
	char *str;
	int i;

	i = 0;
	space = 32;
	zero = '0';
	str = va_arg(*arguments, char *);
	if (flags->precision != 0 && flags->precision <= ft_strlen(str))
		len = flags->precision;
	else
		len = ft_strlen(str);
	flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
	flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
	if (str == NULL)
	{
		str = "(null)";
		len = 6;
		if (flags->width == 0)
		{
			if (flags->moins == 0)
			{
				if (flags->zero == 0)
				{
					flags->count +=ft_putstr_fd(str, 1, len);
				}
			}
		}
	}
	else if (str != NULL)
	{
		if (flags->point == 1 && flags->precision == 0)
		{
		}
		else if (flags->width != 0)
		{
			if (flags->moins == 1)
			{
				flags->count = flags->count + ft_putstr_fd(str, 1, len);
				flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces);
			}
			else
			{
				if (flags->zero == 1)
					flags->count = flags->count + ft_putchar_fd(zero, 1, flags->nbofzeros) + ft_putstr_fd(str, 1, len);
				else if (flags->zero == 0)
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces) + ft_putstr_fd(str, 1, len);
			}
		}
		else
			flags->count += ft_putstr_fd(str, 1, len);
	}
}
