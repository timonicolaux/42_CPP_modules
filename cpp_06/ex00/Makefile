# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timonicolaux <timonicolaux@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 14:15:03 by tnicolau          #+#    #+#              #
#    Updated: 2024/08/19 16:52:09 by timonicolau      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	ScalarConverter.hpp

SRC =	ScalarConverter.cpp \
		main.cpp

OBJS_DIR = .objs/
OBJS = $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRC))

$(OBJS_DIR)%.o: %.cpp $(HEADER)
				@mkdir -p $(@D)
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf ${OBJS_DIR}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
