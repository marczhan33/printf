/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:47:31 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 17:13:58 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_convert_percentage_s(va_list *arguments, t_struct *f)
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
		if (f->point == 1 && f->prec == 0)
		{
			str = "";
			len = 0;
		}
		else if (f->prec != 0 && f->prec <= ft_strlen(str))
			len = f->prec;
		else
			len = ft_strlen(str);
		f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
		f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
		if (f->width == 0)
		{ 
			if (f->point == 0)
			{
					f->count += ft_putstr_fd(str, 1, len);
			}
			else if (f->prec == 0 && f->point == 1)
			{
				if (f->moins == 0)
						f->count +=ft_putstr_fd(str, 1, len);
			}
			else if (f->prec != 0)
				f->count += ft_putstr_fd(str, 1, len);
		}
		else if (f->width != 0)
		{
			if (f->prec != 0)
			{
				if (f->moins == 0)
				{
					if (f->zero == 0)
					{
						f->count += ft_putchar_fd(space, 1, f->nbspaces);
						f->count += ft_putstr_fd(str, 1, len);
					}
				}
				else if (f->moins == 1)
				{
					f->count += ft_putstr_fd(str, 1, len);
					f->count += ft_putchar_fd(space, 1, f->nbspaces);
				}
			}
			else if (f->point == 0)
			{
				if (f->moins == 1)
				{
					f->count += ft_putstr_fd(str, 1, len);
					f->count += ft_putchar_fd(space, 1, f->nbspaces);
				}
				else if (f->moins == 0)
				{
					f->count += ft_putchar_fd(space, 1, f->nbspaces);
					f->count += ft_putstr_fd(str, 1, len);
				}
			}
			else if (f->prec == 0 && f->point == 1)
				f->count += ft_putchar_fd(space, 1, f->width);
		}
	}
	else if (str != NULL)
	{
		if (f->prec != 0 && f->prec <= ft_strlen(str))
			len = f->prec;
		else
			len = ft_strlen(str);
		f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
		f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
		if (f->width != 0)
		{
			if (f->point == 1 && f->prec == 0)
			{
				if (f->moins == 1)
					f->count += ft_putchar_fd(space, 1, f->width);
				else if (f->moins == 0)
					f->count += ft_putchar_fd(space, 1, f->width);
			}
			else if (f->prec != 0 && f->point == 1)
			{
				if (f->moins == 1)
				{
					f->count += ft_putstr_fd(str, 1, len);
					f->count += ft_putchar_fd(space, 1, f->nbspaces);
				}
				else if (f->moins == 0)
				{
					if (f->zero == 1)
						f->count +=  ft_putchar_fd(zero, 1, f->nbzeros) + ft_putstr_fd(str, 1, len);
					else if (f->zero == 0)
						f->count +=  ft_putchar_fd(space, 1, f->nbspaces) + ft_putstr_fd(str, 1, len);
				}
			}
			else if (f->point == 0 && f->prec == 0)
			{
				if (f->moins == 1)
				{
					f->count +=  ft_putstr_fd(str, 1, len);
					f->count +=  ft_putchar_fd(space, 1, f->nbspaces);
				}
				else if (f->moins == 0)
				{
					if (f->zero == 1)
						f->count +=  ft_putchar_fd(zero, 1, f->nbzeros) + ft_putstr_fd(str, 1, len);
					else if (f->zero == 0)
						f->count +=  ft_putchar_fd(space, 1, f->nbspaces) + ft_putstr_fd(str, 1, len);
				}
			}
		}
		else if (f->width == 0)
		{
			if (f->point == 1 && f->prec == 0)
			{
			}
			else if (f->point == 1 && f->prec != 0)
			{
				if (f->moins == 1)
				{
					f->count += ft_putstr_fd(str, 1, len);
					f->count += ft_putchar_fd(space, 1, f->nbspaces);
				}
				else if (f->moins == 0)
				{
					if (f->zero == 1)
						f->count += ft_putchar_fd(zero, 1, f->nbzeros) + ft_putstr_fd(str, 1, len);
					else if (f->zero == 0)
						f->count += ft_putstr_fd(str, 1, len);
				}
			}
			else
				f->count += ft_putstr_fd(str, 1, len);
		}
	}
}

