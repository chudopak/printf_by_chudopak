/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:35:34 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:46:39 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	hex_len_nb(unsigned long long nb)
{
	int				len;

	len = 0;
	if (nb < 10)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int			ft_printf_p(t_parse parsed, va_list ap)
{
	int		len;
	void	*addr;
	int		i;

	i = -1;
	addr = va_arg(ap, void*);
	len = hex_len_nb((unsigned long long)addr) + 2;
	if (parsed.flag.minus == 1)
	{
		ft_putstr("0x");
		ft_puthex_long((unsigned long long)addr);
		while (++i < parsed.width - len)
			ft_putchar(' ');
	}
	else
	{
		while (++i < parsed.width - len)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_puthex_long((unsigned long long)addr);
	}
	return (len + i);
}
