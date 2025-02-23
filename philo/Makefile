CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
SRC_DIR	:= src
OBJ_DIR := obj
SRC		:= $(wildcard $(SRC_DIR)/**/*.c)
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
NAME	= philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
