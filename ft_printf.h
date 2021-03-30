/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:25 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/30 16:06:10 by mzhan            ###   ########.fr       */
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
	_Bool zero;
	_Bool moins;
	int  width;
	_Bool point;
	int precision;
	int i;
	int count;
	int nbofzeros;
	int nbofspaces;
}				t_struct;

void ft_convert_percentage_c(va_list * arguments, t_struct *flags);
void ft_convert_percentage_percentage(t_struct *flags);
void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags);
int ft_printf(const char *format, ...);
void ft_convert_percentage_s(va_list *arguments, t_struct *flags);
void ft_convert_percentage_d(va_list *arguments, t_struct *flags);

#endif 
