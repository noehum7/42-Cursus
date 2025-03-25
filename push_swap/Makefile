# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 10:51:56 by nporras-          #+#    #+#              #
#    Updated: 2025/03/13 12:35:46 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I libft
SRCS = src/init_stack.c \
       src/main.c \
       src/stack_position.c \
       src/utils.c \
       src/validation.c \
       src/operations/swap.c \
       src/operations/push.c \
       src/operations/rotate.c \
       src/operations/reverse_rotate.c \
       src/sorting/algorithm.c \
       src/sorting/indexing.c \
       src/sorting/sort_small.c \
       src/sorting/sort_cost/cost_calc.c \
       src/sorting/sort_cost/execution.c 
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

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
