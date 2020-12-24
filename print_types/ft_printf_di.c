/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:20:13 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 18:57:21 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static char	*write_without_sign(char *str_nb, int size, int sign, int len)
{
	char	*output;
	int		i;

	i = -1;
	output = ft_calloc(sizeof(char), size + 1);
	output[size] = '\0';
	if (sign == 1)
	{
		str_nb++;
		i++;
	}
	else if (sign == 2)
		i++;
	while (++i <= size - len)
		output[i] = '0';
	while (*str_nb)
	{
		output[i] = *str_nb;
		str_nb++;
		i++;
	}
	return (output);
}

static char	*include_prcision(t_parse parsed, char *str_nb, int len)
{
	char	*output;
	int		i;

	i = 0;
	if (*str_nb == '-')
	{
		output = write_without_sign(str_nb, parsed.precision + 1, 1, len);
		output[0] = '-';
	}
	else if (parsed.flag.plus || parsed.flag.space)
	{
		output = write_without_sign(str_nb, parsed.precision + 1, 2, len + 1);
		if (parsed.flag.plus)
			*output = '+';
		else
			*output = ' ';
	}
	else
		output = write_without_sign(str_nb, parsed.precision, 0, len + 1);
	return (output);
}

static void	include_width(t_parse parsed, char *output)
{
	int		i;

	i = -1;
	if (parsed.flag.minus)
	{
		i = ft_strlen(output);
		ft_putstr(output);
		while (++i <= parsed.width)
			ft_putchar(' ');
	}
	else
	{
		if (parsed.flag.zero == 1 && parsed.precision < 0)
			handle_width_with_zero(output, parsed.width);
		else
		{
			while (++i < parsed.width - (int)ft_strlen(output))
				ft_putchar(' ');
			ft_putstr(output);
		}
	}
}

static int	handle_with_flags(t_parse parsed, char *str_nb)
{
	int		len;
	char	*output;
	int		track_free;

	track_free = 0;
	output = NULL;
	len = ft_strlen(str_nb);
	if (parsed.precision > len)
		output = include_prcision(parsed, str_nb, len);
	else
	{
		output = str_nb;
		track_free = 1;
	}
	if (parsed.width > (int)ft_strlen(output))
	{
		include_width(parsed, output);
		len = parsed.width;
	}
	else
		len = norm_cut(output);
	if (track_free == 0)
		free(output);
	return (len);
}

int			ft_printf_di(t_parse parsed, va_list ap)
{
	int		length;
	int		nb;
	char	*str_nb;

	nb = va_arg(ap, int);
	str_nb = ft_itoa(nb);
	if (*str_nb == '0' && parsed.precision == 0 && parsed.width == 0)
		return (0);
	else if (*str_nb == '0' && parsed.precision == 0)
		*str_nb = ' ';
	if (!str_nb)
		return (-1);
	length = handle_with_flags(parsed, str_nb);
	free(str_nb);
	return (length);
}
