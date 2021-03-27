#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	t_struct flags =  {0,0,0, 0, 0, 0, 0,0};// can not initialise this way, will have to declare a function 
	
	va_start(args, format);
	while (format[flags.i] != '\0')
	{
		if (format[flags.i] == '%')
		{
			flags.i++;
			ft_printf_flags(format, &args, &flags);
			if (format[flags.i] == 'c')
			{
				ft_convert_percentage_c(&args, &flags); 
				flags.i++;
			}
			if (format[flags.i] == '%')
			{
				ft_convert_percentage_percentage(&flags);
				flags.i++;
			}
			if (format[flags.i] == 's')
			{
				ft_convert_percentage_s(&args, &flags);
				flags.i++;
			}
		}
		flags.count = flags.count + write(1, &format[flags.i], 1);
		flags.i++;
	}
	va_end(args);
	return (flags.count);
}

// retourne le mauvais nombre
int main ()
{
	int ret;
	int ret2;


	ret = printf("%.1s\n", "hey");
	ret2 = ft_printf("%.1s\n", "hey");
	printf("%d\n", ret);
	printf("%d\n", ret2);
}

