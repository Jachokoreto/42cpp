NAME = btc
CC = g++
CFLAGS = -Wall -Wextra -Werror
SRCS = BitcoinExchange.cpp main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all