/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:07:19 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:31 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int		ft_printf_c(t_parse parsed, va_list ap)
{
	char	c;
	int		i;
	int		length;

	i = -1;
	c = va_arg(ap, int);
	length = 1;
	if (parsed.flag.minus == 1)
	{
		ft_putchar(c);
		while (++i < parsed.width - 1)
			ft_putchar(' ');
	}
	else
	{
		while (++i < parsed.width - 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	length += i;
	return (length);
}
