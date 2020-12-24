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

PARSER.O = $(PARSER.C:.c=.o)

BASE.O = ./base/ft_printf.o

TYPES.O = ./print_types/ft_printf_di.o ./print_types/ft_printf_di_auxiliary_fun.o \
		  ./print_types/ft_printf_s.o ./print_types/ft_printf_c.o ./print_types/ft_printf_pct.o \
		  ./print_types/ft_printf_u.o ./print_types/ft_printf_x.o ./print_types/ft_printf_p.o

UTILS.O = ./utils/reconcilation_flags.o ./utils/pow_nb.o

OBJ = $(PARSER.O) $(BASE.O) $(TYPES.O) $(UTILS.O)

FLAGS = -Wall -Wextra -Werror -c

LIBA = libft.a

.PHONY: compile_libft $(NAME)
all: $(LIBFT_A) $(NAME)
	
%.o: %.c
	gcc $(FLAGS) $< -o $(<:.c=.o)

compile_libft: $(LIBFT_A)

$(LIBFT_A):
	cd ./libft; \
	make; \
	cp $(LIBA) ../; \
	make clean; \
	cd ..; \
	mv $(LIBA) $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?
clean:
	rm -rf $(PARSER.O) $(TYPES.O) $(UTILS.O) $(BASE.O)
	rm -rf *.o

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