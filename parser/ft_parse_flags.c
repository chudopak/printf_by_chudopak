/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:33:22 by chudapak          #+#    #+#             */
/*   Updated: 2020/12/23 18:57:50 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

t_flags	ft_parse_flags(char **str, t_flags flag)
{
	while (**str == ' ' || **str == '0' || **str == '+' || **str == '-')
	{
		if (**str == '-' && !flag.minus)
			flag.minus = 1;
		else if (**str == '+' && !flag.plus)
			flag.plus = 1;
		else if (**str == ' ' && !flag.space)
			flag.space = 1;
		else if (**str == '0' && !flag.zero)
			flag.zero = 1;
		++*str;
	}
	return (flag);
}
