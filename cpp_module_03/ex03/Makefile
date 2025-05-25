# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 19:37:00 by zkhojazo          #+#    #+#              #
#    Updated: 2025/05/25 18:48:28 by zkhojazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = main.cpp \
	ClapTrap.cpp \
	FragTrap.cpp \
	ScavTrap.cpp \
	DiamondTrap.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
