# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 08:55:04 by zkhojazo          #+#    #+#              #
#    Updated: 2025/05/31 17:22:41 by zkhojazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= serialize
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -g -std=c++98
RM			= rm -f

SRC_DIR		= srcs
INC_DIR		= includes
OBJ_DIR		= objs

SRC_FILES	= main.cpp \
				Data.cpp \
				Serializer.cpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCS		= -I$(INC_DIR)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

make valgrind: all
	valgrind -s --leak-check=full --track-origins=yes ./$(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "Object files removed!"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re