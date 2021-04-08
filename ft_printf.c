#include "ft_printf.h"

void	ft_f_initialize(t_struct *f)
{
	f->len2 = 0;
	f->i = 0;
	f->count = 0;
	f->chrzero = '0';
	f->space = 32;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	t_struct f;
	ft_f_initialize(&f);	
	while (format[f.i] != '\0')
	{
		ft_bzero(&f, sizeof(f) - sizeof(f.i) - sizeof(f.count));
		if (format[f.i] == '%')
		{
			f.i++;
			ft_printf_f(format, &args, &f);
			if (format[f.i] == 'c')
			{
				ft_convert_percentage_c(&args, &f); 
				f.i++;
			}
			else if (format[f.i] == '%')
			{
				ft_convert_percentage_percentage(&f);
				f.i++;
			}
			else if (format[f.i] == 's')
			{
				ft_convert_percentage_s(&args, &f);
				f.i++;
			}
			else if (format[f.i] == 'd' || format[f.i] == 'i')
			{
				ft_convert_percentage_d(&args, &f);
				f.i++;
			}
			else if (format[f.i] == 'u')
			{
				ft_convert_percentage_u(&args, &f);
				f.i++;
			}
			else if (format[f.i] == 'x')
			{
				ft_convert_percentage_x(&args, &f);
				f.i++;
			}
			else if (format[f.i] == 'X')
			{
				ft_convert_percentage_X(&args, &f);
				f.i++;
			}
			else if (format[f.i] == 'p')
			{
				ft_convert_percentage_p(&args, &f);
				f.i++;
			}
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

#include <limits.h>

int main ()
{
	int ret;
	int ret2;

	ret = printf("%-.2s\n", NULL);
	ret2 = ft_printf("%-.2s\n", NULL);
	printf("%d\n", ret);
	printf("%d\n", ret2);
}
