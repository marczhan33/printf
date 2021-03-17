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
	
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[++i] == 'c')
			{
				ft_convert_percentage_c(&args); 
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

	ret = printf("bonj%c%%our\n", test);
	ret2 = ft_printf("bonj%c%%our\n", test);
	printf("%d\n", ret);
	printf("%d\n", ret2);
}


