/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:27 by chudapak          #+#    #+#             */
/*   Updated: 2020/12/01 22:01:14 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER
# define FT_PARSER

typedef int bool;

typedef struct	s_flags {
    bool	minus;
	bool	plus;
	bool	zero;
	bool	space;
}				t_flags;

typedef struct	s_parse {
    t_flags	flag;
	int		width;
	int		precision;
    char	type;
}				t_parse;

t_flags	ft_parse_flags(char **str, t_flags flag);
t_parse fill_struct(void);

#endif