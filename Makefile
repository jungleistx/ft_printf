FLAGS=-Wall -Wextra -Werror -O3
SRC=srcs/address.c srcs/assign.c srcs/bonus.c srcs/char.c srcs/flags.c srcs/flags2.c srcs/float.c \
	srcs/ft_printf.c srcs/helpers.c srcs/hex_flags.c srcs/hex.c srcs/int_flags.c srcs/int.c \
	srcs/octal_flags.c srcs/octal.c srcs/percent.c srcs/string.c srcs/unsigned.c
SRCLIB=libft/ft_atoi.c libft/ft_isdigit.c libft/ft_putchar.c libft/ft_strlen.c
NAME=libftprintf.a

all : $(NAME)

$(NAME) :
	gcc ${FLAGS} -c ${SRC} ${SRCLIB} -I ./includes/ -I ./libft/
	ar rc ${NAME} *.o

clean:
	rm -f *.o

fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
