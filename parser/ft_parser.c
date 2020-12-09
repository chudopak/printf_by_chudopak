/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:28:16 by chudapak          #+#    #+#             */
/*   Updated: 2020/12/07 19:34:56 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/chudapak/code/42/printf/printf/headers/libftprintf.h"

t_parse fill_struct(void)
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
    
    //write code that parse width, precision, type (handle * in width and precision)
}