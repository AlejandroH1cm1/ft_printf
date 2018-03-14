# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 03:11:46 by aherrera          #+#    #+#              #
#    Updated: 2018/03/13 23:11:24 by aherrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_C = ft_printf.c utils.c p_fo.c s_fo.c sfs.c
FILES_O = ft_printf.o utils.o p_fo.o s_fo.o sfs.o
NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) $(FILES_C) -I libft/includes
	ar rc $(NAME) $(FILES_O)

clean:
	/bin/rm -f $(FILES_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: re
	gcc main.c $(FILES_O) -I libft/includes -L libft -lft

retest:
	/bin/rm -f ./a.out
	gcc main.c $(NAME) -I libft/includes -L libft -lft
