/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:19:13 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 19:09:22 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	convert_to_nb(int dec, char nb, int width)
{
	width = width * dec + (nb - '0');
	return (width);
}

int			ft_parse_width(char **str, int width, va_list ap)
{
	int		dec;

	dec = 10;
	if (**str >= '0' && **str <= '9')
		while (**str >= '0' && **str <= '9')
		{
			width = convert_to_nb(dec, **str, width);
			++*str;
		}
	else if (**str == '*')
	{
		width = va_arg(ap, int);
		++*str;
	}
	return (width);
}
