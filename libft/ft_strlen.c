/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:08:49 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/05 13:13:04 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
