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

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft
SRCS = src/main.c src/pipex.c src/execute.c src/utils.c
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

# # Definición de variables
# NAME = pipex          # Nombre del ejecutable final
# CC = gcc             # Compilador a utilizar
# CFLAGS = -Wall -Wextra -Werror    # Flags de compilación para mostrar warnings y errores
# INCLUDES = -I includes -I libft    # Directorios donde buscar archivos de cabecera (.h) personalizados, sino buscaria en el sistema por defecto
# SRCS = src/main.c src/pipex.c src/execute.c src/utils.c # Archivos fuente del proyecto

# # Convierte los archivos .c en .o (objeto), que representan una etapa intermedia en el proceso de compilacion. 1º Archivo fuente .c, 2º archivo objeto .o y 3º archivo ejecutable
# OBJS = $(SRCS:.c=.o)    # Sustituye la extensión .c por .o en SRCS. 

# # Ruta a la biblioteca libft
# LIBFT = libft/libft.a    # Archivo de la biblioteca estática libft

# # Regla principal que compila todo el proyecto
# all: $(NAME)

# # Compilación del ejecutable final: Enlazado de .o para crear el ejecutable
# $(NAME): $(OBJS) $(LIBFT)    # Depende de los objetos y la biblioteca libft
#     $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)    # Enlaza archivos .o con las bibliotecas para crear el ejecutable

# # Compilación de la biblioteca libft. -C se usa para cambiar el directorio de trabajo antes de ejecutar el make. Equivalente a: cd libf, make, cd ..
# $(LIBFT):
#     make -C libft    # Entra en el directorio libft y ejecuta su Makefile

# # Regla patrón para compilar archivos .c a .o
# %.o: %.c
#     $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@    # Compila cada archivo fuente

# # Limpia archivos objeto
# clean:
#     make clean -C libft    # Limpia objetos en libft
#     rm -f $(OBJS)         # Elimina archivos objeto del proyecto principal

# # Limpieza completa (objetos y ejecutable)
# fclean: clean             # Ejecuta clean primero
#     make fclean -C libft  # Limpieza completa en libft
#     rm -f $(NAME)         # Elimina el ejecutable

# # Recompila todo el proyecto
# re: fclean all    # Limpia todo y recompila

# # Declara reglas que no son archivos
# .PHONY: all clean fclean re    # Evita conflictos con archivos del mismo nombre
