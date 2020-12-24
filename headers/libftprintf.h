/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:24:43 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 19:40:06 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "ft_parser.h"

int				reconcilation(t_parse parsed);
int				ft_printf_di(t_parse parsed, va_list ap);
int				ft_printf(const char *str, ...);
void			handle_width_with_zero(char *str_nb, int width);
int				norm_cut(char *output);
int				ft_printf_s(t_parse parsed, va_list ap);
int				ft_printf_c(t_parse parsed, va_list ap);
int				ft_printf_pct(t_parse parsed);
int				ft_printf_u(t_parse parsed, va_list ap);
unsigned int	pow_nb(unsigned int nb, unsigned int pow);
int				ft_printf_x(t_parse parsed, va_list ap, int registr);
int				ft_printf_p(t_parse parsed, va_list ap);

#endif
