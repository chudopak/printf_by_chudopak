/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:19:39 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:48:45 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	print_type_and_return_len(t_parse parsed, va_list ap)
{
	if (parsed.type == 'd' || parsed.type == 'i')
		return (ft_printf_di(parsed, ap));
	if (parsed.type == 's')
		return (ft_printf_s(parsed, ap));
	if (parsed.type == 'c')
		return (ft_printf_c(parsed, ap));
	if (parsed.type == '%')
		return (ft_printf_pct(parsed));
	if (parsed.type == 'u')
		return (ft_printf_u(parsed, ap));
	if (parsed.type == 'x')
		return (ft_printf_x(parsed, ap, 0));
	if (parsed.type == 'X')
		return (ft_printf_x(parsed, ap, 1));
	if (parsed.type == 'p')
		return (ft_printf_p(parsed, ap));
	return (-1);
}

static int	printed_arguments(char **str, va_list ap)
{
	t_parse	parsed;
	int		length;

	parsed = ft_parser(str, ap);
	length = reconcilation(parsed);
	if (length == -1)
		return (-1);
	length = print_type_and_return_len(parsed, ap);
	if (length == -1)
		return (-1);
	return (length);
}

static int	handle_string(char *str, va_list ap, int printed_characters)
{
	int		characters_in_argument;

	while (*str)
	{
		if (*str == '%')
		{
			characters_in_argument = printed_arguments(&str, ap);
			if (characters_in_argument == -1)
				return (printed_characters);
			printed_characters += characters_in_argument;
		}
		else
		{
			ft_putchar(*str);
			printed_characters++;
		}
		str++;
	}
	return (printed_characters);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed_characters;

	printed_characters = 0;
	va_start(ap, str);
	printed_characters = handle_string((char*)str, ap, printed_characters);
	va_end(ap);
	return (printed_characters);
}
