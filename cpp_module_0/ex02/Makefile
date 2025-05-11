NAME = account
CC = g++
CFLAGS = -Wall -Wextra -Werror -g --std=c++98

SRCS = Account.cpp \
		tests.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
OBJS_DIR = objs

INCLUDES = Account.hpp

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make