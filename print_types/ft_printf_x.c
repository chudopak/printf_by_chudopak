/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:46:10 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:56:55 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	hex_len_nb(unsigned int nb)
{
	unsigned int	pow;
	int				len;

	pow = 7;
	len = 8;
	if (nb < 10)
		return (1);
	while (nb < pow_nb(16, pow))
	{
		pow--;
		len--;
	}
	return (len);
}

static int	cycle(int i, char c, int length, int size)
{
	while (++i < size)
	{
		ft_putchar(c);
		length++;
	}
	return (length);
}

static int	handle_with_minus(t_parse parsed, unsigned int nb,
			int len, int registr)
{
	int		i;
	int		length;

	i = -1;
	length = len;
	if (parsed.precision > len)
	{
		length = cycle(i, '0', length, parsed.precision - len);
		ft_puthex(nb, registr);
		i += length;
		length = cycle(i, ' ', length, parsed.width);
	}
	else
	{
		ft_puthex(nb, registr);
		length = cycle(i, ' ', length, parsed.width - len);
	}
	return (length);
}

static int	handle_without_minus(t_parse parsed, unsigned int nb,
			int len, int registr)
{
	int		i;
	int		length;
	int		biggest;

	i = -1;
	length = len;
	if (parsed.precision > len)
		biggest = parsed.precision;
	else
		biggest = len;
	if (parsed.precision < 0)
	{
		if (parsed.flag.zero == 1)
			length = cycle(i, '0', length, parsed.width - len);
		else
			length = cycle(i, ' ', length, parsed.width - len);
	}
	else
	{
		length = cycle(i, ' ', length, parsed.width - biggest);
		i = -1;
		length = cycle(i, '0', length, parsed.precision - len);
	}
	ft_puthex(nb, registr);
	return (length);
}

int			ft_printf_x(t_parse parsed, va_list ap, int registr)
{
	int				length;
	unsigned int	nb;
	int				len;
	int				i;

	nb = va_arg(ap, unsigned int);
	len = hex_len_nb(nb);
	i = -1;
	if (nb == 0 && parsed.precision == 0)
	{
		while (++i < parsed.width)
			ft_putchar(' ');
		return (parsed.width);
	}
	if (parsed.flag.minus == 1)
		length = handle_with_minus(parsed, nb, len, registr);
	else
		length = handle_without_minus(parsed, nb, len, registr);
	return (length);
}
