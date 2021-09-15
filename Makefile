# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 22:31:08 by egomes            #+#    #+#              #
#    Updated: 2021/09/14 03:08:41 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c

NAME = so_long

INCLUD = -I . -I /usr/X11/include -g

CC = gcc -L /usr/X11/lib

CFLAGS = #-Wall -Wextra -Werror

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -l mlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

all:		$(NAME)

test:	re
		./$(NAME)

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
	@rm -f $(NAME)

re: fclean all
