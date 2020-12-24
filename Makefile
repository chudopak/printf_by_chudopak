# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 13:02:42 by pmarash           #+#    #+#              #
#    Updated: 2020/12/24 20:20:25 by pmarash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = -L libft -lft

LIBFT_C = ./libft/*.c

LIBFT_A = ./libft/libft.a

NAME = libftprintf.a

PARSER.C = ./parser/ft_parse_flags.c ./parser/ft_parse_precision.c ./parser/ft_parse_type.c \
		   ./parser/ft_parse_width.c ./parser/ft_parser.c 

BASE.C = ./base/ft_printf.c

HEADERS = ./headers/ft_parser.h ./headers/libftprintf.h

TYPES.C = ./print_types/ft_printf_di.c ./print_types/ft_printf_di_auxiliary_fun.c \
		  ./print_types/ft_printf_s.c ./print_types/ft_printf_c.c ./print_types/ft_printf_pct.c \
		  ./print_types/ft_printf_u.c ./print_types/ft_printf_x.c ./print_types/ft_printf_p.c

UTILS.C = ./utils/reconcilation_flags.c ./utils/pow_nb.c

PARSER.O = ./parser/ft_parse_flags.o ./parser/ft_parse_precision.o ./parser/ft_parse_type.o \
		   ./parser/ft_parse_width.o ./parser/ft_parser.o 

BASE.O = ./base/ft_printf.o

TYPES.O = ./print_types/ft_printf_di.o ./print_types/ft_printf_di_auxiliary_fun.o \
		  ./print_types/ft_printf_s.o ./print_types/ft_printf_c.o ./print_types/ft_printf_pct.o \
		  ./print_types/ft_printf_u.o ./print_types/ft_printf_x.o ./print_types/ft_printf_p.o

UTILS.O = ./utils/reconcilation_flags.o ./utils/pow_nb.o

OBJE = ft_printf_di.o ft_printf_di_auxiliary_fun.o ft_printf_s.o ft_printf_c.o ft_printf_pct.o \
		ft_printf_u.o ft_printf_x.o ft_printf_p.o ft_printf.o pow_nb.o reconcilation_flags.o \
		ft_parser.o ft_parse_width.o ft_parse_type.o ft_parse_precision.o ft_parse_flags.o

OBJ = $(PARSER.O) $(BASE.O) $(TYPES.O) $(UTILS.O)

SRC = $(PARSER.C) $(BASE.C) $(TYPES.C) $(UTILS.C)

FLAGS = -Wall -Wextra -Werror -c

LIBA = libft.a

%.o: %.c
	gcc $(FLAGS) $< -o $(<:.c=.o)

all: $(NAME)
	
compile_libft: $(LIBFT_A)


$(LIBFT_A):
	cd ./libft; \
	make; \
	cp $(LIBA) ../; \
	make clean; \
	cd ..; \
	mv $(LIBA) $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(PARSER.O) $(TYPES.O) $(UTILS.O) $(BASE.O)
	rm -rf $(OBJE)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_A)

fclean_lib:
	cd ./libft; \
	rm -rf $(LIBA)

re: fclean all

norm:
	@norminette $(TYPES.C) $(HEADERS) $(BASE.C) $(PARSER.C) $(UTILS.C); \
	cd libft; \
	norminette *.c *.h

test:
	cd pft; \
	./enable-test 21; \
	./test d; \
	./test i; \
	./test u; \
	./test p; \
	./test x; \
	./test X; \
	./test c; \
	./test s; \
	./test

.PHONY: test norm clean fclean fclean_lib re compile_libft
