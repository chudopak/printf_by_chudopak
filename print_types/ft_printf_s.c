/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:35:24 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:07 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	handle_no_minus(t_parse parsed, char *str)
{
	int		len;
	int		i;
	int		len_output;
	int		total_writen;

	i = -1;
	total_writen = 0;
	len = ft_strlen(str);
	if (parsed.precision < len && parsed.precision > -1)
		len_output = parsed.precision;
	else
		len_output = len;
	if (parsed.width > len_output)
		while (++i < parsed.width - len_output)
		{
			ft_putchar(' ');
			total_writen++;
		}
	i = -1;
	while (++i < len_output)
	{
		ft_putchar(str[i]);
		total_writen++;
	}
	return (total_writen);
}

static int	handle_flag_minus(t_parse parsed, char *str)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(str);
	if (parsed.precision > -1 && parsed.precision < len)
		while (++i < parsed.precision)
			ft_putchar(str[i]);
	else
		while (++i < len)
			ft_putchar(str[i]);
	while (i < parsed.width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			ft_printf_s(t_parse parsed, va_list ap)
{
	int		length;
	char	*str;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	if (parsed.flag.minus == 1)
		length = handle_flag_minus(parsed, str);
	else
		length = handle_no_minus(parsed, str);
	return (length);
}
