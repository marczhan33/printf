/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:45:56 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 17:08:50 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long int res)
{
	int count;

	count = 0;
	if (res == 0)
	{
		count = 1;
		return (count);
	}
	if (res < 0)
		count++;
	while (res != 0)
	{
		res = res / 10;
		count++;
	}
	return (count);
}

int	ft_unsignedlen(unsigned int res)
{
	int count;

	count = 0;
	if (res == 0)
	{
		count = 1;
		return (count);
	}
	if (res < 0)
		count++;
	while (res != 0)
	{
		res = res / 10;
		count++;
	}
	return (count);
}
