# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 19:43:14 by ksudyn            #+#    #+#              #
#    Updated: 2026/01/05 15:30:46 by ksudyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp DiamondTrap.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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