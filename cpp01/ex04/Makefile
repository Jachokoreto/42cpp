NAME	 	:= sed

CC			:= c++ -Wall -Wextra -Werror   -std=c++98

RM			:= rm -rf

SRCS_DIR	:= ./src
OBJS_DIR 	:= ./obj

SRCS		:= main.cpp

OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)


all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@
		@echo "$(GREEN)Compiled $@ successfully $(RESET)"

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) -c $< -o $@

t:	all
	./$(NAME) test hello bye
	@echo "\n$(BLUE)cat -e test $(RESET)"
	@cat -e test 
	@echo "\n\n$(BLUE)cat -e test.replace $(RESET)"
	@cat -e test.replace

clean:
	@$(RM) $(OBJS_DIR) test.replace
	@echo "$(RED)Removed.obj$(RESET)"

fclean: clean
	@$(RM) $(NAME)
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
