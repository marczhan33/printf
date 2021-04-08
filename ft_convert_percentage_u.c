/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_u.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:12:08 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/08 16:49:51 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_convert_percentage_u(va_list * arguments, t_struct *f)
{
	unsigned int res;
	char space;
	char zero;
	int len;

	res = va_arg(*arguments, unsigned int);
	len = ft_unsignedlen(res);
	space = 32;
	zero = '0';
	if (f->point == 1 && res == 0 && f->prec == 0)
	{
		if (f->width != 0)
			f->count += ft_putchar_fd(space, 1, f->width);
	}
	else if (f->prec >= len)
	{
		int len2;
		if (f->width != 0)
		{
			f->nbspaces = (f->width - f->prec <= 0) ? 0 : f->width - f->prec;
			len2 = f->prec - len;
			if (f->moins == 1)
			{
				ft_putchar_fd(zero, 1, len2);
				ft_putunsign_fd(res, 1);
				f->count += ft_putchar_fd(space, 1, f->nbspaces) + f->prec;
			}
			else if (f->moins == 0)
			{
				f->count += ft_putchar_fd(space, 1, f->nbspaces) + f->prec;
				ft_putchar_fd(zero, 1, len2);
				ft_putunsign_fd(res, 1);
			}
		}
		else if (f->width == 0)
		{	
			len2 = f->prec - len;
			ft_putchar_fd(zero, 1, len2); 
			ft_putunsign_fd((res), 1);
			f->count += f->prec;
		}
	}
	else if (f->prec < len && f->point == 1)
	{
		f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
		f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
		if (f->width != 0)
		{
			if (f->moins == 1)
			{
				ft_putunsign_fd(res, 1);
				f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
			}
			else if (f->moins == 0)
			{
				f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
				ft_putunsign_fd(res, 1);
			}
		}
		else  if (f->width == 0)
		{
			f->count += len;
			ft_putunsign_fd(res, 1);
		}
	}
	else if (f->prec < len && f->point == 0)
	{
		f->nbzeros = (f->width - len <= 0) ? 0 : f->width - len;
		f->nbspaces = (f->width - len <= 0) ? 0 : f->width - len;
		if (f->width != 0)
		{	
			if (f->moins == 1)
			{
				ft_putunsign_fd(res, 1);
				f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
			}
			else if (f->moins == 0)
			{
				if (f->zero == 1)
				{
					f->count += ft_putchar_fd(zero, 1, f->nbzeros) + len;
					ft_putunsign_fd(res, 1);
				}
				else if (f->zero == 0)
				{
					f->count += ft_putchar_fd(space, 1, f->nbspaces) + len;
					ft_putunsign_fd(res, 1);
				}
			}
		}
		else if (f->width == 0)
		{
				f->count += len;
				ft_putunsign_fd(res, 1);
		}
	}
}
