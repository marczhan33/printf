/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:50:18 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/22 16:53:32 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned char ft_convert_percentage_c(va_list * arguments, t_struct *flags) 
{
	unsigned char c;
	char space;

	c = va_arg(*arguments, int);
	space = 32;
	while (flags->width != 0)
	{
		if (flags->moins == 1)
	{
		flags->count = write(1, &c, 1);
	}



		flags->count = flags->count + write(1, &space, 1);
		flags->width--;
	}
	return (c);
}

