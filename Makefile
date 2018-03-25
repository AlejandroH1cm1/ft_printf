# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 03:11:46 by aherrera          #+#    #+#              #
#    Updated: 2018/03/23 11:32:40 by aherrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_C = ft_printf.c utils.c p_fo.c s_fo.c sfs.c pfos.c sfs2.c pfos2.c utils2.c
FILES_O = ft_printf.o utils.o p_fo.o s_fo.o sfs.o pfos.o sfs2.o pfos2.o utils2.o
NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	cp libft/libft.a ./$(NAME)
	gcc $(FLAGS) $(FILES_C) -I libft/includes
	ar rc $(NAME) $(FILES_O) 
	ranlib $(NAME)

clean:
	/bin/rm -f $(FILES_O)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

test: 
	gcc main.c $(FILES_O) -I libft/includes -L libft -lft

retest: 
	/bin/rm -f ./a.out
	gcc -o test main.c $(NAME) -I libft/includes -L libft -lft
	gcc -o leak main.c kane_alloc_wrap.c $(NAME) -I libft/includes -L libft -lft
