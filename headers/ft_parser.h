/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:27 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 19:09:06 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>

typedef int		t_bool;

typedef struct	s_flags {
	t_bool		minus;
	t_bool		plus;
	t_bool		zero;
	t_bool		space;
}				t_flags;

typedef struct	s_parse {
	t_flags		flag;
	int			width;
	int			precision;
	char		type;
}				t_parse;

t_parse			ft_parser(char **str, va_list ap);
t_flags			ft_parse_flags(char **str, t_flags flag);
t_parse			fill_struct(void);
int				ft_parse_width(char **str, int parsed, va_list ap);
int				ft_parse_precision(char **str, int precision, va_list ap);
char			ft_parse_type(char **str, char type);

#endif
