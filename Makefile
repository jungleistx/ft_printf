# FLAGSO=-Wall -Wextra -Werror -O3
# FLAGS=-Wall -Wextra -Werror
# SRC=ft_printf.c
# NAME=libftprintf.a

# all : $(NAME)

# $(NAME) :
# 	gcc ${FLAGS} -c ${SRC} -I ft_printf.h
# 	ar rc ${NAME} ft_printf.o

# clean:
# 	rm -f ft_printf.o

# fclean:
# 	rm -f ${NAME}

# re: fclean all

FLAGSO=-Wall -Wextra -Werror -O3
FLAGS=-Wall -Wextra -Werror
SRC=srcs/*.c
SRCC=libft/*.c
NAME=libftprintf.a

all : $(NAME)

$(NAME) :
	gcc ${FLAGS} -c ${SRC} ${SRCC} -I ./includes/ft_printf.h ./libft/libft.h
	ar rc ${NAME} *.o
	gcc testmain.c libftprintf.a -o test

clean:
	rm -f *.o

fclean:	clean
	rm -f ${NAME}
	rm test

re: fclean all
	clear