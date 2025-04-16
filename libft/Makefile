# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 12:50:54 by abdennac          #+#    #+#              #
#    Updated: 2024/01/03 10:37:28 by abdennac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c			\
		ft_isalnum.c ft_isalpha.c		\
		ft_isascii.c ft_isdigit.c		\
		ft_isprint.c ft_memcmp.c		\
		ft_memcpy.c	ft_memset.c			\
		ft_putchar_fd.c ft_putstr_fd.c 	\
		ft_strdup.c	ft_strjoin.c		\
		ft_strlen.c	ft_strncmp.c		\
		ft_strlcpy.c ft_tolower.c		\
		ft_toupper.c ft_memmove.c		\
		ft_strchr.c	ft_strrchr.c		\
		ft_putnbr_fd.c ft_strnstr.c		\
		ft_calloc.c ft_memchr.c			\
		ft_itoa.c ft_strlcat.c			\
		ft_putendl_fd.c ft_substr.c		\
		ft_strtrim.c ft_split.c 		\
		ft_striteri.c ft_strmapi.c		\
		ft_lstmap.c

SRCB =	ft_lstsize_bonus.c		\
		ft_lstnew_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstlast_bonus.c		\
		ft_lstdelone_bonus.c 	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(NAME) $(OBJB)
	ar -rcs $(NAME) $^
	
$(NAME): $(OBJ)
	ar -rcs $@ $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
