# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 10:47:23 by tnicolau          #+#    #+#              #
#    Updated: 2024/07/11 12:47:10 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	Animal.hpp \
			Dog.hpp \
			Cat.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Brain.hpp

SRC =	Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp \
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
