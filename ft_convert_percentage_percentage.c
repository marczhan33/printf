/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage_percentage.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:36:10 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/22 16:55:57 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void ft_convert_percentage_percentage(t_struct *flags)
{
	char c;
	char space;
	char zero;

	space = 32;
	c = '%';
	zero = '0';
	flags->nbofzeros = (flags->width - 1 <= 1) ? 0 : flags->width - 1;
 	flags->nbofspaces = (flags->width -1 <= 1) ? 0 : flags->width - 1;
	if (flags->moins == 1) //peu importe si y a 0 ou pas ca affiche des espaces
		{
			flags->count = flags->count + write(1, &c, 1);
			flags->count += ft_putchar(&space, 1, flags->nbofspaces);
		}
	else 
	{
	   if (flags->zero == 1)
		   flags->count += ft_putchar(zero, 1, flags->nbofzeros) + write(1, &c, 1);
	   else if (flags->moins == 0)
		   flags->count += ft_putchar(&space, 1, flags->nbofspaces) + write(1, &space, 1);
	}
}
