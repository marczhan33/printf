/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:53:51 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 14:36:13 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdint.h>

void	ft_putunsign_fd(unsigned int n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd, 1);
        ft_putnbr_fd(-n, fd);
    }
    else if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putchar_fd(n % 10 + '0', fd, 1);
    }
    else
        ft_putchar_fd(n + '0', fd, 1);
}

void	ft_putnbr_hexa(long unsigned int nbr, char *base)
{
	int 			tab[100];
	int 			i;
	long int	 	longnb;

	i = 0;
	longnb = nbr;

	if (longnb == 0)
		write(1, &base[0], 1);
	if (longnb < 0)
	{
		longnb = -longnb;
		write (1, "-", 1);
	}
	while (longnb !=  0)
	{
		tab[i++] = base[(longnb % 16)];
		longnb = longnb / 16;
	}
	while (i > 0)
		write(1, &tab[--i], 1);
}

void	ft_putnbr_hexa_p(uintptr_t nbr, char *base)
{
	int 			tab[100];
	int 			i;
	long int	 	longnb;

	i = 0;
	longnb = nbr;

	if (longnb == 0)
		write(1, &base[0], 1);
	if (longnb < 0)
	{
		longnb = -longnb;
		write (1, "-", 1);
	}
	while (longnb !=  0)
	{
		tab[i++] = base[(longnb % 16)];
		longnb = longnb / 16;
	}
	while (i > 0)
		write(1, &tab[--i], 1);
}
