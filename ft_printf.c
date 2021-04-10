/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:27:23 by mzhan             #+#    #+#             */
/*   Updated: 2021/04/10 17:05:22 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parsing_1(const char *format, t_struct *f, va_list *args)
{
	if (format[f->i] == 'c')
		ft_convert_percentage_c(args, f);
	else if (format[f->i] == '%')
		ft_convert_percentage_percentage(f);
	else if (format[f->i] == 's')
		ft_convert_percentage_s(args, f);
	else if (format[f->i] == 'd' || format[f->i] == 'i')
		ft_convert_percentage_d(args, f);
	else if (format[f->i] == 'u')
		ft_convert_percentage_u(args, f);
	else if (format[f->i] == 'x')
		ft_convert_percentage_x(args, f);
	else if (format[f->i] == 'X')
		ft_convert_percentage_bigx(args, f);
	else if (format[f->i] == 'p')
		ft_convert_percentage_p(args, f);
	else
		f->i--;
}

void	ft_f_initialize(t_struct *f)
{
	f->chrzero = '0';
	f->space = ' ';
	f->i = 0;
	f->count = 0;
}

void	ft_f_reset(t_struct *f)
{
	f->len = 0;
	f->len2 = 0;
	f->zero = 0;
	f->moins = 0;
	f->width = 0;
	f->point = 0;
	f->prec = 0;
	f->nbzeros = 0;
	f->nbspaces = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	f;

	va_start(args, format);
	ft_f_initialize(&f);
	while (format[f.i] != '\0')
	{
		ft_f_reset(&f);
		if (format[f.i] == '%')
		{
			f.i++;
			ft_printf_f(format, &args, &f);
			ft_parsing_1(format, &f, &args);
			f.i++;
		}
		else
		{
			f.count = f.count + write(1, &format[f.i], 1);
			f.i++;
		}
	}
	va_end(args);
	return (f.count);
}
/*
#include <limits.h>

  int		main ()
  {
  int ret;
  int ret2;

  ret = printf("%p %p ", LONG_MIN, LONG_MAX);
  ret2 = ft_printf("%p %p ", LONG_MIN, LONG_MAX);
  printf("%d\n", ret);
  printf("%d\n", ret2);
  }*/
