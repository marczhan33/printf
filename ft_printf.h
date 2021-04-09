/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:25 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/09 11:06:17 by mzhan            ###   ########.fr       */
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
	char chrzero;
	char space;
	int len;
	int len2;
	int zero;
	int moins;
	int width;
	int point;
	int prec;
	int nbzeros;
	int nbspaces;
	int count;
	int i;
}				t_struct;


void ft_convert_percentage_c(va_list * arguments, t_struct *flags);
void ft_convert_percentage_percentage(t_struct *flags);
void ft_printf_f(const char *format, va_list *arguments, t_struct *flags);
void ft_convert_percentage_s(va_list *arguments, t_struct *flags);

void ft_convert_percentage_d(va_list *arguments, t_struct *flags);
void ft_point_1_global(t_struct *f, int len, long int res);
void ft_prec_inf_len3(t_struct *f, long int res, int len);
void ft_prec_inf_len2(t_struct *f, long int res, int len);
void ft_prec_inf_len_global(t_struct *f, long int res, int len);
int ft_nbrlen(long int res);

void ft_convert_percentage_u(va_list *arguments, t_struct *flags);
int ft_unsignedlen(unsigned int res);
void ft_putunsign_fd(unsigned int n, int fd);

void ft_convert_percentage_x(va_list *arguments, t_struct *flags);
void ft_putnbr_hexa(long unsigned int nbr, char *base);

void ft_convert_percentage_X(va_list *arguments, t_struct *flags);
void ft_width_nonzero(t_struct *f, long unsigned int res);
void ft_point_zero(t_struct *f, long unsigned int res);

void ft_convert_percentage_p(va_list *arguments, t_struct *flags);

int ft_printf(const char *format, ...);
#endif 
