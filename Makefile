SRCS = ft_printf.c parser.c writer.c utils_1.c utilis_2.c

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		make -C libft
		ar rc $(NAME) ${OBJS}
		ranlib $(NAME)

.c.o : ${SRCSb}
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

clean :
		make clean -C libft
		rm -f ${OBJSb}

fclean : clean
		make fclean -C libft
		rm -f $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re bonus
