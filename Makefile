# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 22:31:08 by egomes            #+#    #+#              #
#    Updated: 2021/09/29 18:14:10 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c src/ft_itoa.c src/gnl.c src/init_map.c src/src.c src/draw_game.c src/enemi.c src/key_hook.c src/make_move.c src/map_validate.c src/key_hook_player_movs.c

NAME = so_long

INCLUD = -I . -I /usr/X11/include -g

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

LIB = #-L /usr/X11/lib

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(LIB) -l mlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

all:		$(NAME)

test:	re
		./$(NAME)

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
	@rm -f $(NAME)

re: fclean all
