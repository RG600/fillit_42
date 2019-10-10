# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosgill <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 11:59:07 by rosgill           #+#    #+#              #
#    Updated: 2019/09/06 15:34:54 by rosgill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFILES = main.c parse.c

FLAGS = -Wall -Werror -Wextra -g -O0

GCC = gcc

LIBFT = libft

all: $(NAME)

$(NAME):
	 @make -C $(LIBFT)

	 $(GCC) $(FLAGS) $(CFILES) -L $(LIBFT) -lft -o $(NAME)

clean:
	 @rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean:	clean
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re
