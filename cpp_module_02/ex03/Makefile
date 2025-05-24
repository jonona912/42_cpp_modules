# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 13:41:23 by zkhojazo          #+#    #+#              #
#    Updated: 2025/05/24 10:15:38 by zkhojazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

INCLUDES = Fixed.hpp

SRCS = main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
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