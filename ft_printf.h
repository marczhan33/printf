/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:25 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/07 16:45:00 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_struct
{
	int zero;
	int moins;
	int width;
	int point;
	int precision;
	int nbofzeros;
	int nbofspaces;	
	int count;
	int i;
}				t_struct;


void ft_convert_percentage_c(va_list * arguments, t_struct *flags);
void ft_convert_percentage_percentage(t_struct *flags);
void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags);
int ft_printf(const char *format, ...);
void ft_convert_percentage_s(va_list *arguments, t_struct *flags);
void ft_convert_percentage_d(va_list *arguments, t_struct *flags);
void ft_convert_percentage_u(va_list *arguments, t_struct *flags);
int ft_nbrlen(long int res);
void ft_putunsign_fd(long unsigned int n, int fd);
void ft_convert_percentage_x(va_list *arguments, t_struct *flags);
void ft_putnbr_hexa(long unsigned int nbr, char *base);
void ft_convert_percentage_X(va_list *arguments, t_struct *flags);
void ft_convert_percentage_p(va_list *arguments, t_struct *flags);

#endif 
