NAME	 	:= whatever

CC			:= c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98

RM			:= rm -rf

SRCS_DIR	:= ./src
OBJS_DIR 	:= ./obj

SRCS		:= 

OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

INCLUDES	:= -Ilibjttool -I.

LIB			:= -ljttool -Llibjttool


all:	$(NAME)

$(NAME): $(OBJS) main.cpp libjttool/libjttool.a whatever.hpp
	$(CC) main.cpp $(OBJS) $(INCLUDES) $(LIB) -o $@
	@echo "$(GREEN)Compiled $@ successfully $(RESET)"

libjttool/libjttool.a:
	@make -C libjttool

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) -c $< $(INCLUDES) -o $@

m:	all
	./$(NAME)

t:	$(OBJS) test.cpp
	$(CC) test.cpp $(OBJS) -o $@
	@echo "$(GREEN)Compiled $@ successfully, running $@ $(RESET)"
	./$@
	@rm t

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Removed.obj$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	
re:		fclean all

.PHONY: all run clean fclean

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
