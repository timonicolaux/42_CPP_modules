# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 14:35:08 by tnicolau          #+#    #+#              #
#    Updated: 2024/07/22 15:01:51 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	Bureaucrat.hpp \
			Form.hpp

SRC =	Bureaucrat.cpp \
		Form.cpp \
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
