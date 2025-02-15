CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= src/main.c \
		  src/input/input.c \
		  src/threads/spawn.c \
		  src/init/init.c
OBJ		= $(SRC:.c=.o)
INC		= lib/
NAME	= philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
