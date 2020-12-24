/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconcilation_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:32:52 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 19:01:01 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

static int	reconcilation_flags(t_parse parsed)
{
	if ((parsed.flag.space == 1 || parsed.flag.plus == 1) &&
			(parsed.type != 'd' && parsed.type != 'i'))
		return (-1);
	if (parsed.flag.zero == 1 && (parsed.type == 'c'
			|| parsed.type == 'p' || parsed.type == 's'))
		return (-1);
	if (parsed.flag.plus == 1 && parsed.flag.space == 1)
		return (-1);
	return (0);
}

int			reconcilation(t_parse parsed)
{
	int		verificator;

	if ((verificator = reconcilation_flags(parsed) == -1))
		return (-1);
	if (parsed.type == '0')
		return (-1);
	return (0);
}
