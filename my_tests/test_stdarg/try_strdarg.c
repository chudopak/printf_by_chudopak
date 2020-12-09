#include <stdarg.h>
#include <stdio.h>
#include "/Users/chudapak/code/42/printf/printf/libft/libft.h"

void	test_dif_fun(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
}

void	test_va(char *str, ...)
{
	va_list ap;
	int 	i;
	char 	*p;
	//char	c;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_strnstr(str, "%s", 2))
			{
				p = va_arg(ap, char*);
				str += 2;
				ft_putstr(p);
			}
			else if (ft_strnstr(str, "%d", 2))
			{
				i = va_arg(ap, int);
				str += 2;
				ft_putnbr(i);
			}
			
			else if (ft_strnstr(str, "%c", 2))
			{
				test_dif_fun(ap);
				str += 2; 
				//c = va_arg(ap, int);
				//ft_putchar(c);
			}
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
	}
	va_end(ap);
}

int		main(int ac, char **av)
{
	int 	i;
	char 	c = 'c';
	//int		nb = 65;

	i = ac;
	test_va(av[1], c, -11, 99, av[2]);
	printf("\ntest printf char but passed nb - %d\n", c);
	return (0);
}
