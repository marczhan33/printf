/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:53:51 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/02 17:07:48 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void        ft_putunsign_fd(long unsigned int n, int fd)
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
