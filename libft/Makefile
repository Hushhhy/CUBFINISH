NAME = libft.a

SRCS = ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isascii.c\
			ft_isalnum.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_strnstr.c\
			ft_memcmp.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strncpy.c\
			ft_strlcat.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_free.c\
			ft_hexalen.c\
			ft_printf.c\
			ft_ptrlen.c\
			ft_putcharlen.c\
			ft_putnbrlen.c\
			ft_putstrlen.c\
			ft_unsilen.c\
			get_next_line.c\
			get_next_line_utils.c\


OBJS =          ${SRCS:.c=.o}

HEADER =        libft.h

NAME =          libft.a

CFLAGS =        -Wall -Wextra -Werror

all:            ${NAME}

${NAME}:        ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:          ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}

.c.o:
	gcc ${CFLAGS} -c $^ -include ${HEADER}

clean:
	rm -rf ${OBJS} ${OBJS_BONUS}

fclean:         clean
	rm -rf ${NAME}

re:             fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
