NAME = phonebook
CC = g++
CFLAGS = -Wall -Wextra -Werror -g --std=c++98

INCLUDES = ClassContact.hpp \
			ClassPhoneBook.hpp

SRCS = ClassContact.cpp \
		ClassPhoneBook.cpp \
		addToPhoneBook.cpp \
		confirmExit.cpp \
		MainPhoneBook.cpp \
		searchPhoneBook.cpp \
		stringConversions.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

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
