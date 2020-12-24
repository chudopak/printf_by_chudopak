/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:51:40 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:13 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int		ft_printf_pct(t_parse parsed)
{
	int		i;
	int		length;
	char	space;

	space = ' ';
	i = -1;
	length = 1;
	if (parsed.flag.minus == 1)
	{
		ft_putchar('%');
		while (++i < parsed.width - 1)
			ft_putchar(space);
	}
	else
	{
		if (parsed.flag.zero == 1)
			space = '0';
		while (++i < parsed.width - 1)
			ft_putchar(space);
		ft_putchar('%');
	}
	length += i;
	return (length);
}
