#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	t_struct flags;// =  {0, 0,0,0, 0, 0, 0, 0,0};// can not initialise this way, will have to declare a function 
	flags.i = 0;
	flags.count = 0;
	va_start(args, format);
	while (format[flags.i] != '\0')
	{
		ft_bzero(&flags, sizeof(flags) - sizeof(flags.i) - sizeof(flags.count));
		if (format[flags.i] == '%')
		{
			flags.i++;
			ft_printf_flags(format, &args, &flags);
			if (format[flags.i] == 'c')
			{
				ft_convert_percentage_c(&args, &flags); 
				flags.i++;
			}
			else if (format[flags.i] == '%')
			{
				ft_convert_percentage_percentage(&flags);
				flags.i++;
			}
			else if (format[flags.i] == 's')
			{
				ft_convert_percentage_s(&args, &flags);
				flags.i++;
			}
			else if (format[flags.i] == 'd' || format[flags.i] == 'i')
			{
				ft_convert_percentage_d(&args, &flags);
				flags.i++;
			}
			else if (format[flags.i] == 'u')
			{
				ft_convert_percentage_u(&args, &flags);
				flags.i++;
			}
			else if (format[flags.i] == 'x')
			{
				ft_convert_percentage_x(&args, &flags);
				flags.i++;
			}
			else if (format[flags.i] == 'X')
			{
				ft_convert_percentage_X(&args, &flags);
				flags.i++;
			}
			else if (format[flags.i] == 'p')
			{
				ft_convert_percentage_p(&args, &flags);
				flags.i++;
			}
		}
		else 
		{
			flags.count = flags.count + write(1, &format[flags.i], 1);
			flags.i++;
		}
	}
	va_end(args);
	return (flags.count);
}

#include <limits.h>

int main ()
{
	int ret;
	int ret2;

	ret = printf("2%cd33fHFtk%-x\n", '9', -2147483647);
	ret2 = ft_printf("2%cd33fHFtk%-x\n", '9', -2147483647);
	printf("%d\n", ret);
	printf("%d\n", ret2);
}
