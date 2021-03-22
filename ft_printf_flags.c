/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:09:52 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/22 16:55:59 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && (str[i] != '-' || str[i] != '.'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}


int	ft_strchr(const char *s, const char c) // pas la meme fonction que libft, a modifier dans la libft
{
	char	*tmp_s;
	char 	tmp_c;
	int		i;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != '\0' && tmp_s[i] != tmp_c)
		i++;
	if (tmp_s[i] == tmp_c)
		return (1);
	return (0);
}

void ft_printf_flags(const char *format, va_list *arguments, t_struct *flags) 
{

	while ((format[flags->i] != 'c') && format[flags->i] != '\0')/* && format[i] != 's' && format[i] != 'p' && format[i] != 'd' && format[i] != 'i' && format[i] != 'd' && format[i] != 'i' && format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && format[i] != '%') && format[i] != '\0')*/
	{
		if (format[flags->i] == '0')
			flags->zero = 1;
		else if (format[flags->i] == '-')
			flags->moins = 1;
		else if (ft_strchr("0123456789", format[flags->i]))
			flags->width = ft_atoi(&format[flags->i]);
		else if (format[flags->i] == '*')
			flags->width = va_arg(*arguments, int);
	//	if (format[i] == '.') pas encore bien compris comment marchait ce flag
	//		flags.precision = ft_atoi()	
		flags->i++;
	}
}
	
