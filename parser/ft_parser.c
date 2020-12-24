/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:28:16 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 19:10:15 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

t_parse	fill_struct(void)
{
	t_parse	tmp;

	tmp.flag.minus = 0;
	tmp.flag.plus = 0;
	tmp.flag.zero = 0;
	tmp.flag.space = 0;
	tmp.width = 0;
	tmp.precision = 0;
	tmp.type = '0';
	return (tmp);
}

t_parse	ft_parser(char **str, va_list ap)
{
	t_parse	parse;

	parse = fill_struct();
	++*str;
	parse.flag = ft_parse_flags(str, parse.flag);
	parse.width = ft_parse_width(str, parse.width, ap);
	if (parse.width < 0)
	{
		parse.width *= -1;
		parse.flag.minus = 1;
	}
	parse.precision = ft_parse_precision(str, parse.precision, ap);
	parse.type = ft_parse_type(str, parse.type);
	return (parse);
}
