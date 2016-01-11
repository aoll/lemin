#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 08:22:38 by aollivie          #+#    #+#              #
#    Updated: 2015/12/02 13:56:41 by aollivie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lemin

IDIR = libft/libft.a
LIB=-lncurses
SRC = src/ft_check_error.c src/ft_choose.c src/ft_choosebis.c src/ft_way.c src/ft_waybis.c src/ft_printChe.c src/ft_che.c src/ft_chebis.c src/ft_cheter.c src/main.c src/ft_tree.c src/ft_treeinit.c src/ft_treeroad.c src/ft_road.c src/ft_roadinit.c src/ft_ncurseIni.c src/ft_error.c src/ft_errorbis.c src/ft_print_ant.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft/
	@gcc $(OBJ) $(IDIR) $(LIB) -o $(NAME)
%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
