#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_printf(const char *format, ...)
{
	int i;
	va_list args;
	unsigned char c;
	t_struct flags;
	
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_printf_flags(&format[i], &args, &flags)
			if (format[++i] == 'c')
			{
				ft_convert_percentage_c(&args, &flags); 
				i++;
			}
			if (format[++i] == '%')
			{
				ft_convert_percentage_percentage(&args);
				i++;
			}
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

// retourne le mauvais nombre
int main ()
{
	int ret;
	int test = 60;
	int ret2;
	int width = 123456789;
	int width2 = 50;

	ret = printf("%0000000000000030d\n",20);
//	ret2 = ft_printf("bonj%**.*c\n", 5, 6, 7, 'v');
	printf("%d\n", ret);
//	printf("%d\n", ret2);
}


