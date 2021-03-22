/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:25 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/22 16:53:35 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_struct
{
	_Bool zero;
	_Bool moins;
	int  width;
	int precision;
	int i;
	int count;
	int nbofzeros;
	int nbofspaces;
}				t_struct;

int	ft_atoi(const char *str);
int	ft_strchr(const char *s, char c);
void ft_putchar_fd(char c, int fd);
unsigned char ft_convert_percentage_c(va_list * arguments, t_struct *flags);
void ft_convert_percentage_percentage(t_struct *flags);
void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags);
int ft_printf(const char *format, ...);

#endif 
