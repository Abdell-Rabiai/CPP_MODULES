# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:03:17 by arabiai           #+#    #+#              #
#    Updated: 2023/11/21 16:03:17 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE_NAME = ex03

SOURCE_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.hpp *.h)

OBJECT_FILES = $(SOURCE_FILES:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(SOURCE_NAME)

$(SOURCE_NAME) : $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o $(SOURCE_NAME)

%.o: %.cpp $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJECT_FILES)

fclean : clean
	rm -rf $(SOURCE_NAME)

re : fclean all

.PHONY : all clean fclean re
