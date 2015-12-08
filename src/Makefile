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

NAME = test

IDIR = ../libft/libft.a
LIB=-lncurses
SRC = test.c ft_check_error.c ft_error.c ft_errorbis.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ../libft/
	@gcc $(OBJ) $(IDIR) $(LIB) -o $(NAME)
%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
