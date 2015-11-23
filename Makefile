#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 08:22:38 by aollivie          #+#    #+#              #
#    Updated: 2015/03/31 20:43:22 by aollivie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lemin

IDIR = libft/libft.a
LIB=-lncurses
SRC = ft_way.c main.c ft_tree.c ft_treeInit.c  ft_treeRoad.c ft_road.c ft_roadInit.c ft_ncurseIni.c 
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
