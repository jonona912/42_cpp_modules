NAME = zombie
CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

INCLUDES = Zombie.hpp main.hpp

SRCS = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)


$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# $< is an automatic variable representing the first prerequisite (the .cpp file)
# -o $@ specifies the output file name, where $@ is the target (the .o file)
$(OBJS_DIR)/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

