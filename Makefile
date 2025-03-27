# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 21:10:41 by hkemmoun          #+#    #+#              #
#    Updated: 2025/03/22 21:10:43 by hkemmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc 
FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext 
SRC = main.c fractol.c utils.c render.c math_utils.c events.c errors.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
