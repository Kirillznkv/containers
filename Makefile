NAME = a.out

TEST1 =	main.cpp StackTests.cpp
TEST2 = main.cpp
O_FILE = $(TEST1:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILE)
	clang++ -std=c++98 $(O_FILE) -o $(NAME)

%.o: %.cpp
	@clang++ -std=c++98 -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -f $(O_FILE)
	@rm -f *_shrubbery

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re