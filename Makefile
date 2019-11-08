SRCS = ft_printf.c parser.c writer.c utils_1.c utils_2.c utils_3.c libft/libft_1.c libft/libft_2.c

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		ar rc $(NAME) ${OBJS}
		ranlib $(NAME)

.c.o : ${SRCS}
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re bonus
