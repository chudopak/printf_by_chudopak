/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:14:31 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:45 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	convert_to_nb(int dec, char nb, int precision)
{
	precision = precision * dec + (nb - '0');
	return (precision);
}

static int	type_check(char c)
{
	if (c == 'c' || c == 'd' || c == 's' || c == 'p'
			|| c == 'x' || c == 'X' || c == 'i'
			|| c == 'u' || c == '%')
		return (-1);
	return (0);
}

int			ft_parse_precision(char **str, int precision, va_list ap)
{
	int		dec;

	dec = 10;
	if (**str == '.')
	{
		++*str;
		if (**str >= '0' && **str <= '9')
		{
			while (**str >= '0' && **str <= '9')
			{
				precision = convert_to_nb(dec, **str, precision);
				++*str;
			}
		}
		else if (**str == '*')
		{
			precision = va_arg(ap, int);
			++*str;
		}
		else
			precision = 0;
	}
	else if (type_check(**str) == -1)
		precision = -1;
	return (precision);
}
