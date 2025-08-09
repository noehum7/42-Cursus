# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 12:49:48 by nporras-          #+#    #+#              #
#    Updated: 2025/07/08 13:41:59 by nporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aform
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	   RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
INCLUDES = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
		   RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
