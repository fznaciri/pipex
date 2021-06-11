# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:09:35 by mac               #+#    #+#              #
#    Updated: 2021/06/11 19:19:44 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

D = -g

SRC = ./srcs/execute.c \
		./srcs/get_path.c \
		./srcs/pipe.c \
		./utils/ft_split.c \
		./utils/ft_strdup.c \
		./utils/ft_strjoin.c \
		./utils/ft_strlen.c \
		./utils/ft_substr.c \
		./utils/ft_putendl_fd.c \
		./utils/linkedlist.c \
		./utils/ft_delete_arg.c

all: $(NAME)

$(NAME):
	@$(C)  -o $(NAME) main.c $(SRC)
bonus:
	@$(C)  -o $(NAME) main_bonus.c $(SRC)
debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address 

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all