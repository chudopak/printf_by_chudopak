/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:19:39 by chudapak          #+#    #+#             */
/*   Updated: 2020/12/07 19:34:42 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/chudapak/code/42/printf/printf/headers/libftprintf.h"

static int     printed_arguments(char **str, va_list ap)
{
	t_parse	parsed;
	int		length;
	
	parsed = ft_parser(str, ap);
	
}

static int     handle_string(char *str, va_list ap)
{
    int     printed_characters;
    int     characters_in_argument;

    while (*str)
    {
        //make function that count char after "/" and "%"
        if (*str == '%')
        {
            characters_in_argument = print_argument(&str, ap);
        }
        str++;
    }
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    int     printed_characters;

    va_start(ap, str);
    printed_characters = handle_string((char*)str, ap);
    va_end(ap);
    return (printed_characters);
}