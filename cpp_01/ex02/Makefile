# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 10:33:05 by tnicolau          #+#    #+#              #
#    Updated: 2024/06/21 10:09:21 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp

OBJS_DIR = .objs/
OBJS = $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRC))

$(OBJS_DIR)%.o: %.cpp
				@mkdir -p $(@D)
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf ${OBJS_DIR}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
