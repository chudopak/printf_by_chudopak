/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_auxiliary_fun.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:59:20 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:27 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	handle_width_with_zero(char *str_nb, int width)
{
	int		i;
	int		len;

	i = -1;
	if (*str_nb == '-')
	{
		i++;
		ft_putchar(*str_nb);
		++str_nb;
	}
	len = ft_strlen(str_nb);
	while (++i < width - len)
		ft_putchar('0');
	ft_putstr(str_nb);
}

int		norm_cut(char *output)
{
	int		len;

	len = ft_strlen(output);
	ft_putstr(output);
	return (len);
}
