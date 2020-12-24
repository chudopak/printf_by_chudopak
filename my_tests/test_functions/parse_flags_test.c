#include "/Users/pmarash/42/printf/ft_printf/headers/libftprintf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_flags	flag;
	int		i;

	i = ac;
	flag.minus = 0;
	flag.plus = 0;
	flag.zero = 0;
	flag.space = 0;
	flag = ft_parse_flags(&av[1], flag);
	printf("minus - %d\n", flag.minus);
	printf("plus - %d\n", flag.plus);
	printf("space - %d\n", flag.space);
	printf("zero - %d\n", flag.zero);
	return (0);
}