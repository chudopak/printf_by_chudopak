/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:40:48 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/14 14:52:56 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return ((char*)str);
		str++;
	}
	if (*str == ch)
		return ((char*)str);
	return (0);
}
