#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_struct flags =  {0,0,0, 0, 0, 0, 0,0};// can not initialise this way
	
	va_start(args, format);
	while (format[flags.i] != '\0')
	{
		if (format[flags.i] == '%')
		{
			ft_printf_flags(&format[flags.i], &args, &flags);
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
//	int test = 60;
//	int ret2;
//	int width = 123456789;
//	int width2 = 50;

	ret = printf("%010%\n");
//	ret2 = ft_printf("%-5c\n", 'v');
	printf("%d\n", ret);
//	printf("%d\n", ret2);
}


