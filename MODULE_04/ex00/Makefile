SOURCE_NAME = ex00
OBJECT_DIR = .ex00objs

SOURCE_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.hpp *.h)

OBJECT_FILES = $(addprefix $(OBJECT_DIR)/, $(SOURCE_FILES:.cpp=.o)) 

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(SOURCE_NAME)

$(SOURCE_NAME) : $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o $(SOURCE_NAME)

$(OBJECT_DIR)/%.o: %.cpp $(HEADER_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJECT_FILES) $(Object_dir)

fclean : clean
	rm -rf $(SOURCE_NAME)

re : fclean all

.PHONY : all clean fclean re
