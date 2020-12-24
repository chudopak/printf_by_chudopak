/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:04:51 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/23 19:01:09 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

unsigned int	pow_nb(unsigned int nb, unsigned int pow)
{
	unsigned int	result;
	unsigned int	i;

	i = 0;
	result = nb;
	while (++i < pow)
		result *= nb;
	return (result);
}
