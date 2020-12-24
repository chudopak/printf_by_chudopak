/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:55:46 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:02 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	cycle(int i, char c, int length, int size)
{
	while (++i < size)
	{
		ft_putchar(c);
		length++;
	}
	return (length);
}

static int	handle_with_minus(t_parse parsed, unsigned int nb, int len)
{
	int		i;
	int		length;

	i = -1;
	length = len;
	if (parsed.precision > len)
	{
		length = cycle(i, '0', length, parsed.precision - len);
		ft_putnbr_u(nb);
		i += length;
		length = cycle(i, ' ', length, parsed.width);
	}
	else
	{
		ft_putnbr_u(nb);
		length = cycle(i, ' ', length, parsed.width - len);
	}
	return (length);
}

static int	handle_without_minus(t_parse parsed, unsigned int nb, int len)
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
	ft_putnbr_u(nb);
	return (length);
}

int			ft_printf_u(t_parse parsed, va_list ap)
{
	unsigned int	nb;
	int				length;
	int				i;
	int				len;

	i = -1;
	nb = va_arg(ap, unsigned int);
	len = ft_nblen_u(nb);
	if (nb == 0 && parsed.precision == 0)
	{
		while (++i < parsed.width)
			ft_putchar(' ');
		return (parsed.width);
	}
	if (parsed.flag.minus == 1)
		length = handle_with_minus(parsed, nb, len);
	else
		length = handle_without_minus(parsed, nb, len);
	return (length);
}
