# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:09:35 by mac               #+#    #+#              #
#    Updated: 2021/06/12 15:07:40 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

NAME_BONUS = pipex_bonus
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

SRC_BONUS = ./srcs/execute_bonus.c \
		./srcs/get_path.c \
		./srcs/pipe.c \
		./utils/ft_split.c \
		./utils/ft_strdup.c \
		./utils/ft_strjoin.c \
		./utils/ft_strndup_bonus.c \
		./utils/ft_strchr_bonus.c \
		./utils/ft_strcmp_bonus.c \
		./utils/gnl_bonus.c \
		./utils/ft_strlen.c \
		./utils/ft_substr.c \
		./utils/ft_putendl_fd.c \
		./utils/linkedlist.c \
		./utils/ft_delete_arg.c \
		./srcs/set_in_bonus.c

all: $(NAME)

$(NAME):
	@$(C)  -o $(NAME) main.c $(SRC)
bonus:
	@$(C)  -o $(NAME_BONUS) main_bonus.c $(SRC_BONUS)
debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address 

clean:
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)	
re: fclean all

.PHONY: re fclean clean all