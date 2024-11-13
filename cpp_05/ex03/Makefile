# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 11:24:24 by tnicolau          #+#    #+#              #
#    Updated: 2024/08/13 13:10:30 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	Bureaucrat.hpp \
			AForm.hpp \
			ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp \
			Intern.hpp

SRC =	Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp \
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
