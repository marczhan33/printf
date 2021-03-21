/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:25 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/21 16:43:41 by mzhan            ###   ########.fr       */
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
}				t_struct;

void ft_putchar_fd(char c, int fd);
unsigned char ft_convert_percentage_c(va_list * arguments);
void ft_convert_percentage_percentage(va_list *arguments);
int ft_printf(const char *format, ...);

#endif 
