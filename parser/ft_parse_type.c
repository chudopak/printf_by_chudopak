/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:48:58 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:40 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char	ft_parse_type(char **str, char type)
{
	if (**str == 'c' || **str == 'd' || **str == 's' || **str == 'p'
			|| **str == 'x' || **str == 'X' || **str == 'i' || **str == 'u'
			|| **str == '%')
		type = **str;
	return (type);
}
