


NAME = ft_gkrellm

SRC =  src/CPU.cpp  src/Graphic.cpp src/LoadAvg.cpp src/main.cpp src/Network.cpp src/OSinfo.cpp src/Processes.cpp \
		src/RAM.cpp src/Text.cpp src/Time.cpp src/Unicorn.cpp src/Userinfo.cpp

INC = inc/CPU.hpp  inc/Graphic.hpp inc/LoadAvg.hpp inc/Network.hpp inc/OSinfo.hpp inc/Processes.hpp \
		inc/RAM.hpp inc/Text.hpp inc/Time.hpp inc/Unicorn.hpp inc/Userinfo.hpp inc/IMonitorDisplay.hpp \
		inc/IMonitorModule.hpp inc/ft_gkrellm.h

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98

CC = clang++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lncurses

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
