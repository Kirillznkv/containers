NAME = stdExec

SRCS = ../srcs/
CPP_FILE =	mainStd.cpp StackTestsStd.cpp VectorTestsStd.cpp
HPP_FILE = $(SRCS)deque.hpp $(SRCS)stack.hpp $(SRCS)vector.hpp
O_FILE = $(CPP_FILE:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILE)
	clang++ -std=c++98 $(O_FILE) -o $(NAME)

%.o: %.cpp $(HPP_FILE)
	@clang++ -std=c++98 -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re