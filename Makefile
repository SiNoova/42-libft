SRC_M = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c
OBJS_M = $(SRC_M:.c=.o)
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

all: $(NAME)

$(NAME): $(OBJS_M)
	$(AR) $@ $^

%.o : %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_M)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean 