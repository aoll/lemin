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
SRC =ft_error.c ft_choose.c ft_choosebis.c ft_way.c ft_printChe.c ft_che.c ft_chebis.c ft_cheter.c main.c ft_tree.c ft_treeInit.c ft_treeRoad.c ft_road.c ft_roadInit.c ft_ncurseIni.c 
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
