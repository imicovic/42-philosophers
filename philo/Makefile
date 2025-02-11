CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= main.c
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
