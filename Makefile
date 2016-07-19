# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 16:00:52 by aribeiro          #+#    #+#              #
#    Updated: 2016/03/25 19:02:52 by aribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	main.c \
		ft_bzero.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_set_reset_bit.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strnew_exit.c \
		pswap_atoi.c \
		pswap_check_justone.c \
		pswap_check_justone_rev.c \
		pswap_check_order.c \
		pswap_display.c \
		pswap_do_push.c \
		pswap_do_revrotate.c \
		pswap_do_rotate.c \
		pswap_do_swap.c \
		pswap_global_sort.c \
		pswap_merge_sort.c \
		pswap_param.c \
		pswap_param_bonus.c \
		pswap_piles.c \
		pswap_sort_list.c \
		pswap_tools.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	@echo
	@echo "\033[1;33m--> $(NAME) created\033[0m\033[22;37m"
	@echo

%.o:%.c
	gcc -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)
	@echo "\033[1;33m--> Obj deleted\033[0m\033[22;37m"
	@echo

fclean: clean
	rm -rf $(NAME)
	@echo "\033[1;33m--> $(NAME) deleted\033[0m\033[22;37m"
	@echo

re: fclean all
