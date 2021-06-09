# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:09:35 by mac               #+#    #+#              #
#    Updated: 2021/06/09 18:38:06 by mac              ###   ########.fr        #
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
		./utils/ft_cmd_last.c \
		./utils/ft_cmd_new.c \
		./utils/ft_cmd_add_back.c 

all: $(NAME)

$(NAME):
	@$(C)  -o $(NAME) main.c $(SRC)

debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address 

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all