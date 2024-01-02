# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allblue <allblue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:35:38 by momrane           #+#    #+#              #
#    Updated: 2024/01/02 10:43:34 by allblue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR =	ar rcs
CC = 	cc -Wall -Werror -Wextra
BIN =	./bin
NAME =	libft.a
SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = 	$(patsubst %.c,bin/%.o,$(SRCS))

SRCS_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS =	$(patsubst %.c,bin/%.o,$(SRCS_BONUS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bin/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

clean:
	rm -rf $(BIN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
