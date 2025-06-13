# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 13:06:04 by nporras-          #+#    #+#              #
#    Updated: 2025/05/01 21:15:30 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I libft
SRCS = src/main.c \
       src/shell_init.c \
	   src/utils.c \
       src/builtins/cd.c \
       src/builtins/echo.c \
       src/builtins/env_ops.c \
       src/builtins/env_utils.c \
       src/builtins/env_utils2.c \
       src/builtins/env.c \
       src/builtins/exit.c \
       src/builtins/export.c \
       src/builtins/pwd.c \
       src/builtins/unset.c \
       src/executor/executor_utils.c \
       src/executor/executor.c \
       src/executor/path.c \
       src/executor/pipes_processes.c \
       src/executor/pipes_utils.c \
       src/executor/redirections_heredoc.c \
       src/executor/redirections_utils.c \
       src/executor/redirections.c \
       src/executor/signal_handling.c \
       src/parser/expansions.c \
       src/parser/free_command_utils.c \
       src/parser/handle_quotes.c \
       src/parser/parser_utils.c \
       src/parser/parser_utils2.c \
       src/parser/parser.c \
       src/parser/syntax_check.c \
       src/parser/tokenizer.c \
       src/signals/signals.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

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
