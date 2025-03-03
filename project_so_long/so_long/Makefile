# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 10:51:56 by nporras-           #+#    #+#             #
#    Updated: 2024/02/10 12:14:46 by nporras-          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I libft -I ../minilibx
SRCS =	src/init.c \
		src/main.c \
		src/render.c \
		src/map_reader.c \
		src/map_validator.c \
		src/path_checker.c \
		src/game_logic.c \
		src/events.c \
		src/utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
MLX_DIR = ../minilibx
MLX = -L $(MLX_DIR) -lmlx -Ilmlx -lXext -lX11 -lm

# Compilación principal
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

# Compilar Libft
$(LIBFT):
	make -C libft

# Compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
