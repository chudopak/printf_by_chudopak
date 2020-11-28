/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:07:36 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/11 13:00:55 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (!s || !f)
		return (0);
	if (!(new_s = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = -1;
	while (s[++i])
		new_s[i] = (*f)(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
