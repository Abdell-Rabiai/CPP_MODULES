NAME = megaphone

END=\033[0m
LIGHTRED=\033[1;31m
LightBlue=\033[1;34m
LightPurple=\033[1;35m
Cyan=\033[0;36m
GREEN = \033[92m
                                                                                            																								 
# ex00 = $(addprefix , megaphone.cpp)

# SRCS_OBJ = $(ex00)

SRC = megaphone.cpp

FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

# HEADER = src/minishell.h

CC = c++

# OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.cpp $(HEADER)
	@printf "$(GREEN) Generating objects... %-33.33s\r" $@
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(SRC) #$(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\n\n\t$(Cyan) COMPILED SUCCESSFULLY :)\n $(END)"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf *.dSYM .vscode

re : fclean all

.PHONY : all clean fclean re