FLAGSO=-Wall -Wextra -Werror -O3
FLAGS=-Wall -Wextra -Werror
SRC=ft_printf.c
NAME=libftprintf.a

all : $(NAME)

$(NAME) :
	gcc ${FLAGS} -c ${SRC} -I ft_printf.h
	ar rc ${NAME} ft_printf.o

clean:
	rm -f ft_printf.o

fclean:
	rm -f ${NAME}

re: fclean all
