NAME	 	:= scavtrap

CC			:= c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 -Wshadow

RM			:= rm -rf

SRCS_DIR	:= ./src
OBJS_DIR 	:= ./obj

SRCS		:= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)


all:	$(NAME)

$(NAME): $(OBJS) main.cpp
		$(CC) main.cpp $(OBJS) -o $@
		@echo "$(GREEN)Compiled $@ successfully $(RESET)"

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) -c $< -o $@

t:	all
	./$(NAME)


clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Removed.obj$(RESET)"

fclean: clean
	@$(RM) $(NAME) t
	@echo "$(RED)Removed $(NAME)$(RESET)"
	
re:		fclean all

.PHONY: all run clean fclean t

# Colors are great!
# Formats are greater!
# https://misc.flogisoft.com/bash/tip_colors_and_formatting
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[033m
BLUE	= \033[034m
PINK	= \033[035m
TEAL	= \033[036m
WHITE	= \033[037m
RESET	= \033[0m # No Color
