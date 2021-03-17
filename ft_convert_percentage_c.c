/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_c.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:50:18 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/17 15:57:09 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned char ft_convert_percentage_c(va_list * arguments) 
{
	unsigned char c;

	c = va_arg(*arguments, int);
	ft_putchar_fd(c, 1);
	return (c);
}

