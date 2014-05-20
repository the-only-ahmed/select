# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 21:28:36 by ael-kadh          #+#    #+#              #
#    Updated: 2014/01/12 21:03:15 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
SRC = main.c ft_signal.c action.c lists.c ft_print.c select.c
HEAD = select.h
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@gcc $(FLAGS) -I libft/includes -I libft/printf/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -ltermcap libft/printf/libftprintf.a -o $(NAME)

clean :
	@make -C ./libft clean
	@rm -f $(OBJ)

fclean : clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all
