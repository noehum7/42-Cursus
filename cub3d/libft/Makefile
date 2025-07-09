# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 12:17:48 by nporras-          #+#    #+#              #
#    Updated: 2025/07/02 12:46:40 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
       ft_lstmap.c
SRCS_FT_PRINTF = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
		ft_putnbr_unsigned.c ft_putnbr_base.c ft_putptr.c
SRCS_GNL = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_PRINTF = $(SRCS_FT_PRINTF:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@ar rcs $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
