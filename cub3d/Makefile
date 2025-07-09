# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 10:51:56 by nporras-          #+#    #+#              #
#    Updated: 2025/07/07 16:26:31 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./libft -I./MLX42/include
INCLUDES_BONUS = -I./include_bonus -I./libft -I./MLX42/include
MLX_FLAGS = -lglfw -ldl -pthread -lm
OBJ_DIR = obj
SRCDIR = src
SRCDIR_BONUS = src_bonus
SRCS =			$(SRCDIR)/draw.c \
				$(SRCDIR)/events.c \
				$(SRCDIR)/init.c \
				$(SRCDIR)/main.c \
				$(SRCDIR)/movement.c \
				$(SRCDIR)/parse_config.c \
				$(SRCDIR)/parse_map.c \
				$(SRCDIR)/parse_utils.c \
				$(SRCDIR)/player.c \
				$(SRCDIR)/raycasting.c \
				$(SRCDIR)/render.c \
				$(SRCDIR)/rotation.c \
				$(SRCDIR)/utils.c \
				$(SRCDIR)/utils2.c \
				$(SRCDIR)/validate_map.c \
				$(SRCDIR)/validate_map_utils.c \
				$(SRCDIR)/handlers.c
SRCS_BONUS =	$(SRCDIR_BONUS)/draw_bonus.c \
				$(SRCDIR_BONUS)/events_bonus.c \
				$(SRCDIR_BONUS)/init_bonus.c \
				$(SRCDIR_BONUS)/main_bonus.c \
				$(SRCDIR_BONUS)/minimap_bonus.c \
				$(SRCDIR_BONUS)/movement_bonus.c \
				$(SRCDIR_BONUS)/parse_config_bonus.c \
				$(SRCDIR_BONUS)/parse_map_bonus.c \
				$(SRCDIR_BONUS)/parse_utils_bonus.c \
				$(SRCDIR_BONUS)/player_bonus.c \
				$(SRCDIR_BONUS)/raycasting_bonus.c \
				$(SRCDIR_BONUS)/render_bonus.c \
				$(SRCDIR_BONUS)/rotation_bonus.c \
				$(SRCDIR_BONUS)/utils_bonus.c \
				$(SRCDIR_BONUS)/utils2_bonus.c \
				$(SRCDIR_BONUS)/validate_map_bonus.c \
				$(SRCDIR_BONUS)/validate_map_utils_bonus.c \
				$(SRCDIR_BONUS)/handlers_bonus.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRCDIR_BONUS)/%.c=$(OBJ_DIR)/%.o)
LIBFT = libft/libft.a
MLX42 = MLX42/build/libmlx42.a
NORMINETTE = norminette include include_bonus libft src src_bonus

################################################################################
##                                    COLOURS                                 ##
################################################################################

WHITE=\033[0m
BOLD=\033[1m
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m

################################################################################
##                                    RULES                                   ##
################################################################################

all: head $(LIBFT) $(MLX42) $(NAME)

head:
	@echo "$(BLUE)"
	@echo "\t                                                                               "
	@echo "\t      ▌  ▄▖▄ "
	@echo "\t  ▛▘▌▌▛▌ ▄▌▌▌"
	@echo "\t  ▙▖▙▌▙▌ ▄▌▙▘"
	@echo "\t        By analba-s & nporras-" 
	@echo "\tProyect: \033[36m cub3D $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re bonus norminette $(WHITE)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Executable created: $(NAME)$(WHITE)"

bonus: head $(LIBFT) $(MLX42) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(MAGENTA)✓ Bonus executable created: $(NAME_BONUS)$(WHITE)"

$(OBJ_DIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)  ✓ Compiled: $(notdir $<)$(WHITE)"

$(OBJ_DIR)/%.o: $(SRCDIR_BONUS)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@
	@echo "$(MAGENTA)  ✓ Compiled (bonus): $(notdir $<)$(WHITE)"

$(LIBFT):
	@$(MAKE) -C libft

$(MLX42):
	@if [ ! -f $(MLX42) ]; then \
		echo "$(YELLOW)↻ Building MLX42...$(WHITE)"; \
		cmake MLX42 -B MLX42/build -DCMAKE_BUILD_TYPE=Release > /dev/null 2>&1; \
		$(MAKE) -C MLX42/build -j4 > /dev/null 2>&1; \
		echo "$(GREEN)✓ MLX42 built successfully.$(WHITE)"; \
	fi

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C libft clean
	@$(MAKE) -C MLX42/build clean
	@echo "$(GREEN)Clean  ✓ $(WHITE)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C libft fclean
	@echo "$(GREEN)Hardly clean  ✓ $(WHITE)"

norminette:
	$(NORMINETTE)

re: fclean all

.PHONY: all clean fclean re bonus norminette
