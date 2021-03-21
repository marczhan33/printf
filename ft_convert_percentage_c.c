/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:50:18 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/21 16:43:44 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned char ft_convert_percentage_c(va_list * arguments, t_struct *flags) 
{
	unsigned char c;

	c = va_arg(*arguments, int);
	if (flags->moins == 1)
	{
		write(1, &c, 1);
	}
	while (flags->width != 1)
	{
		write(1, ' ', 1);
		flags->width--;
	}
	return (c);
}

