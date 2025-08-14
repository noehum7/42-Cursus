# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 11:20:16 by nporras-          #+#    #+#              #
#    Updated: 2025/08/11 11:21:15 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 🔧 Docker Configuration
DC=docker-compose
DC_FILE=./srcs/docker-compose.yml
ENV_FILE=./.env
MAIN=$(DC) -f $(DC_FILE) --env-file $(ENV_FILE)
WORDPRESS_SCRIPT=$(PROJECT_ROOT)/srcs/requirements/wordpress/tools/wordpress-config.sh

# 📁 Project Paths
PROJECT_ROOT=$(PWD)
SCRIPTS_DIR=$(PROJECT_ROOT)/srcs/tools

# 🎨 Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
CYAN=\033[0;36m
NC=\033[0m

# 🎯 Phony Targets
.PHONY: all help init build up down stop restart install-wp clean fclean re

# 🌟 Default target
all: help

# 📖 Help
help:
	@echo ""
	@echo "$(CYAN)#################################################################################$(NC)"
	@echo "$(CYAN)#                                                                               #$(NC)"
	@echo "$(CYAN)#                    $(YELLOW)🌀 INCEPTION PROJECT COMMANDS 🌀$(CYAN)                           #$(NC)"
	@echo "$(CYAN)#                                                                               #$(NC)"
	@echo "$(CYAN)#                          $(GREEN)Created by: nporras-$(CYAN)                                 #$(NC)"
	@echo "$(CYAN)#                          $(GREEN)42 School Málaga$(CYAN)                                     #$(NC)"
	@echo "$(CYAN)#                                                                               #$(NC)"
	@echo "$(CYAN)#################################################################################$(NC)"
	@echo ""
	@echo "$(YELLOW)🚀 ESSENTIAL COMMANDS:$(NC)"
	@echo "  $(GREEN)make init$(NC)        - Initialize project configuration"
	@echo "  $(GREEN)make build$(NC)       - Build Docker images"
	@echo "  $(GREEN)make up$(NC)          - Start containers"
	@echo "  $(GREEN)make install-wp$(NC)  - Install WordPress"
	@echo "  $(GREEN)make down$(NC)        - Stop containers"
	@echo "  $(GREEN)make restart$(NC)     - Restart all containers"
	@echo "  $(GREEN)make clean$(NC)       - Clean containers and images"
	@echo "  $(GREEN)make fclean$(NC)      - Remove configuration files"
	@echo "  $(GREEN)make re$(NC)          - Complete rebuild (with WordPress)"
	@echo ""
	@echo "$(BLUE)💡 Quick Start: make init && make build && make up$(NC)"
	@echo "$(BLUE)🌐 Access: https://localhost:443$(NC)"
	@echo ""

# 🎯 Initialize configuration
init:
	@echo "$(BLUE)🧠 Initializing dream architecture...$(NC)"
	@$(SCRIPTS_DIR)/init-config.sh
	@echo "$(GREEN)✅ Ready! Next: make build && make up$(NC)"

# 🏗️ Build images
build:
	@echo "$(BLUE)🏗️  Building Docker images...$(NC)"
	$(MAIN) build
	@echo "$(GREEN)✅ Images built successfully!$(NC)"

# 🚀 Start containers
up:
	@echo "$(GREEN)🌀 Starting containers...$(NC)"
	$(MAIN) up -d
	@echo "$(GREEN)✨ Containers started!$(NC)"
	@echo "$(CYAN)🌐 Access: https://localhost:443$(NC)"

# 📥 Install WordPress
install-wp:
	@echo "$(BLUE)📥 Installing WordPress...$(NC)"
	@$(WORDPRESS_SCRIPT) install
	@echo "$(GREEN)✅ WordPress installed!$(NC)"
	@echo "$(CYAN)🌐 Access: https://localhost:443$(NC)"

# ⏹️ Stop containers
down:
	@echo "$(YELLOW)😴 Stopping containers...$(NC)"
	$(MAIN) down

stop: down

# 🔄 Restart
restart: down up

# 📊 Status
status:
	@echo "$(CYAN)📊 Container Status:$(NC)"
	@docker ps --format "table {{.Names}}\t{{.Image}}\t{{.Status}}\t{{.Ports}}"

# 📜 Logs
logs:
	@$(MAIN) logs --tail=50

# 🧹 Clean
clean:
	@echo "$(YELLOW)🧹 Cleaning containers and images...$(NC)"
	$(MAIN) down -v
	@docker rmi -f nginx wordpress mariadb 2>/dev/null || true
	@echo "$(GREEN)✅ Cleanup completed!$(NC)"

# 🗑️ Remove configuration
fclean:
	@echo "$(YELLOW)🗑️ Removing configuration files...$(NC)"
	@echo "$(BLUE)Files to be removed:$(NC)"
	@[ -f .env ] && echo "  - .env" || true
	@[ -f secrets/db_password.txt ] && echo "  - secrets/db_password.txt" || true
	@[ -f secrets/db_root_password.txt ] && echo "  - secrets/db_root_password.txt" || true
	@[ -f secrets/credentials.txt ] && echo "  - secrets/credentials.txt" || true
	@[ -f secrets/wp_salts ] && echo "  - secrets/wp_salts" || true
	@echo ""
	@echo "$(GREEN)These can be recreated with: make init$(NC)"
	@read -p "Continue? [y/N] " confirm && [ "$$confirm" = "y" ]
	@rm -f .env
	@rm -f secrets/db_password.txt
	@rm -f secrets/db_root_password.txt
	@rm -f secrets/credentials.txt
	@rm -f secrets/wp_salts
	@echo "$(GREEN)✅ Configuration removed!$(NC)"

# 🔄 Complete rebuild
re: down clean init build up install-wp
	@echo "$(GREEN)🎉 Project recreated successfully!$(NC)"
	@echo "$(CYAN)🌐 Access: https://localhost:443$(NC)"
