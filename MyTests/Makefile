NAME = stdExec
NAME2 = ftExec
NAME3 = a.out

SRCS = ../container/
STD_FOLDER = ./stdTests/
FT_FOLDER = ./ftTests/

CPP_FILE_STD =		$(STD_FOLDER)mainStd.cpp $(STD_FOLDER)StackTestsStd.cpp \
					$(STD_FOLDER)VectorTestsStd.cpp

CPP_FILE_FT =		$(FT_FOLDER)mainFt.cpp $(FT_FOLDER)StackTestsFt.cpp \
					$(FT_FOLDER)VectorTestsFt.cpp

CPP_FILE_FINISH =	CompareTests.cpp

HPP_FILE =	$(SRCS)deque.hpp \
			$(SRCS)stack.hpp \
			$(SRCS)vector.hpp \
			$(SRCS)iterator.hpp \
			$(SRCS)reverse_iterator.hpp \
			$(SRCS)is_integral.hpp \
			$(SRCS)enable_if.hpp

O_FILE_STD = $(CPP_FILE_STD:.cpp=.o)
O_FILE_FT = $(CPP_FILE_FT:.cpp=.o)
O_FILE_FINISH = $(CPP_FILE_FINISH:.cpp=.o)

all: $(NAME) $(NAME2) $(NAME3)

$(NAME): $(O_FILE_STD)
	clang++ -std=c++98 $(O_FILE_STD) -o $(NAME)

$(NAME2): $(O_FILE_FT)
	clang++ -std=c++98 $(O_FILE_FT) -o $(NAME2)

$(NAME3): $(O_FILE_FINISH)
	clang++ -std=c++98 $(O_FILE_FINISH) -o $(NAME3)

%.o: %.cpp $(HPP_FILE)
	@clang++ -std=c++98 -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -f $(O_FILE_STD) $(O_FILE_FT) $(O_FILE_FINISH)

fclean: clean
	@rm -f $(NAME) $(NAME2) $(NAME3)

re: fclean all

.PHONY: all clean fclean re