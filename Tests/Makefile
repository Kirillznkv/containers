NAME = test

CPP_FILE = main.cpp

COPMILE_FERSION = -std=c++11

FLAGS = -lgtest -lgmock -pthread

all: $(NAME)

$(NAME): $(CPP_FILE)
	g++ $(CPP_FILE) $(COPMILE_FERSION) $(FLAGS) -o $(NAME)

fclean:
	@rm -f $(NAME) $(NAME2) $(NAME3)

re: fclean all

.PHONY: all fclean re