# Folders and Names
NAME		= write
INCLUDES	= .

SRCS		= write_class.cpp

# Compiler options
CC			= g++
FLAGS		= -Wall -Wextra -Werror -std=c++11 #98

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Assembling $@"
	@$(CC) $(FLAGS) -o $@ $^

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test
