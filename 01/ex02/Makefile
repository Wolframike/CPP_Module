# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 20:08:23 by misargsy          #+#    #+#              #
#    Updated: 2024/01/31 23:28:37 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -std=c++98
cc			= c++

NAME		= h-t-i-b
SRCS		= main.cpp

GRAY		= \033[1;37m
CYAN		= \033[1;36m
MAGENTA		= \033[1;35m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
GREEN		= \033[1;32m
RED			= \033[1;31m
RESET		= \033[0m
MAX			= 50
CONVERSION	= %-$(MAX).$(MAX)s\r

all: $(NAME)

$(NAME): $(SRCS)
	@printf "$(YELLOW)Compiling $@... $(CONVERSION)$(RESET)"
	@$(cc) $(FLAGS) $(SRCS) -o $(NAME)
	@printf "$(GREEN)⪼ $(NAME): compilation done ⪻$(CONVERSION)$(RESET)\n"

clean:
	@printf "$(YELLOW)Removing $(NAME)... $(CONVERSION)$(RESET)"
	@rm -f $(NAME)
	@printf "$(RED)Removed $(NAME)$(CONVERSION)$(RESET)\n"

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re