/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:47:31 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/02 14:40:05 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//verifier str != NULL ?
//verfier  width
////verifier precision && // flags->point
//verifier moins
//verifier zero
void ft_convert_percentage_s(va_list *arguments, t_struct *flags)
{
	int len;
	char space;
	char zero;
	char *str;

	space = 32;
	zero = '0';
	str = va_arg(*arguments, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = 6;
		if (flags->precision != 0 && flags->precision <= ft_strlen(str))
			len = flags->precision;
		else
			len = ft_strlen(str);
		flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
		flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
		if (flags->width == 0)
		{ 
			if (flags->point == 0)
			{
				if (flags->moins == 0)
				{
					flags->count += ft_putstr_fd(str, 1, len);
				}
			}
			else if (flags->precision == 0 && flags->point == 1)
			{
				if (flags->moins == 0)
						flags->count +=ft_putstr_fd(str, 1, len);
			}
			else if (flags->precision != 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += ft_putstr_fd(str, 1, len);
					}
				}
			}
		}
		else if (flags->width != 0)
		{
			if (flags->precision != 0)
			{
				if (flags->moins == 0)
				{
					if (flags->zero == 0)
					{
						flags->count += ft_putchar_fd(space, 1, flags->nbofspaces);
						flags->count += ft_putstr_fd(str, 1, len);
					}
				}
				else if (flags->moins == 1)
				{
					flags->count += ft_putstr_fd(str, 1, len);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces);
				}
			}
			else if (flags->point == 0)
			{
				if (flags->moins == 1)
				{
					flags->count += ft_putstr_fd(str, 1, len);
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces);
				}
				else if (flags->moins == 0)
				{
					flags->count += ft_putchar_fd(space, 1, flags->nbofspaces);
					flags->count += ft_putstr_fd(str, 1, len);
				}
			}
			else if (flags->precision == 0 && flags->point == 1)
				flags->count += ft_putchar_fd(space, 1, flags->width);
		}
	}
	else if (str != NULL)
	{
		if (flags->precision != 0 && flags->precision <= ft_strlen(str))
			len = flags->precision;
		else
			len = ft_strlen(str);
		flags->nbofzeros = (flags->width - len <= 0) ? 0 : flags->width - len;
		flags->nbofspaces = (flags->width - len <= 0) ? 0 : flags->width - len;
		if (flags->width != 0)
		{
			if (flags->point == 1 && flags->precision == 0)
			{
				if (flags->moins == 1)
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->width);
				else if (flags->moins == 0)
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->width);
			}
			else if (flags->precision != 0 && flags->point == 1)
			{
				if (flags->moins == 1)
				{
					flags->count = flags->count + ft_putstr_fd(str, 1, len);
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces);
				}
				else if (flags->moins == 0)
				{
					if (flags->zero == 1)
						flags->count +=  ft_putchar_fd(zero, 1, flags->nbofzeros) + ft_putstr_fd(str, 1, len);
					else if (flags->zero == 0)
						flags->count +=  ft_putchar_fd(space, 1, flags->nbofspaces) + ft_putstr_fd(str, 1, len);
				}
			}
			else if (flags->point == 0 && flags->precision == 0)
			{
				if (flags->moins == 1)
				{
					flags->count = flags->count + ft_putstr_fd(str, 1, len);
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces);
				}
				else if (flags->moins == 0)
				{
					if (flags->zero == 1)
						flags->count +=  ft_putchar_fd(zero, 1, flags->nbofzeros) + ft_putstr_fd(str, 1, len);
					else if (flags->zero == 0)
						flags->count +=  ft_putchar_fd(space, 1, flags->nbofspaces) + ft_putstr_fd(str, 1, len);
				}
			}
		}
		else if (flags->width == 0)
		{
			if (flags->point == 1 && flags->precision == 0)
			{
			}
			else if (flags->point == 1 && flags->precision != 0)
			{
				if (flags->moins == 1)
				{
					flags->count = flags->count + ft_putstr_fd(str, 1, len);
					flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces);
				}
				else if (flags->moins == 0)
				{
					if (flags->zero == 1)
						flags->count += ft_putchar_fd(zero, 1, flags->nbofzeros) + ft_putstr_fd(str, 1, len);
					else if (flags->zero == 0)
						flags->count += ft_putstr_fd(str, 1, len);
				}
			}
			else
				flags->count += ft_putstr_fd(str, 1, len);
		}
	}
}

