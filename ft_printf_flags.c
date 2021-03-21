/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:09:52 by mzhan             #+#    #+#             */
/*   Updated: 2021/03/21 16:43:38 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
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


int	ft_strchr(const char *s, char c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != '\0' && tmp_s[i] != c)
		i++;
	if (tmp_s[i] == c)
		return (1);
	return (0);
}

void ft_printf_flags(const char *format, va_list *arguments, t_struct * flags) 
{
	int i;

	i = 0;
	while (format[i] != 'c' || format[i] != 's' || format[i] != 'p' || format[i] != 'd' || format[i] != 'i' ||format[i] != 'd' || format[i] != 'i' || format[i] != 'u' || format[i] != 'x' || format[i] != 'X' || format[i] != '%')
	{
	//	if (format[i] == '0')
	//		flags.zero = 1;
	//		ft_atoi(format); je fais un ft_atoi psk si y a 00009 bah du coup ca veut dire aussi directement 9 de width et rempli de 0
		if (format[i] == '-')
			flags->moins = 1;
		if (ft_strchr("0123456789", &format[i]) //regrouper cette ligne la et la ligne du dessous
				flags->width = ft_atoi(&format[i]);
		if (format[i] == '*')
			flags->width = va_arg(arguments, int);
	//	if (format[i] == '.') pas encore bien compris comment marchait ce flag
	//		flags.precision = ft_atoi()	
		i++;
	}
}
	
