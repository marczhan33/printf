/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:50:18 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/25 16:56:19 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void ft_convert_percentage_c(va_list * arguments, t_struct *flags)
{
	unsigned char c;
	char space;
	char zero;

	c = va_arg(*arguments, int);
	space = 32;
	zero = '0';
	flags->nbofzeros = (flags->width - 1 <= 1) ? 0 : flags->width - 1;
	flags->nbofspaces = (flags->width - 1 <= 1) ? 0 : flags->width - 1;
	if (flags->moins == 1)
	{
		flags->count = flags->count + write(1, &c, 1);
		flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces);
	}
	else
	{
		if (flags->zero == 1)
			flags->count = flags->count + ft_putchar_fd(zero, 1, flags->nbofzeros) + write (1, &c, 1);
		else if (flags->moins == 0)
			flags->count = flags->count + ft_putchar_fd(space, 1, flags->nbofspaces) + write(1, &space, 1);
	}
}

