# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 19:51:47 by ksudyn            #+#    #+#              #
#    Updated: 2026/01/05 15:31:56 by ksudyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp \
      	AMateria.cpp Ice.cpp Cure.cpp \
      	Character.cpp MateriaSource.cpp
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re