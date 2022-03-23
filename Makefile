CC = gcc

NAME = fdf

FLAGS = -g -Wall -Werror -Wextra

SRC = main.c \
	  file_operations.c \
	  matrix_operations.c \
	  keys.c \
	  utils.c \
	  draw.c \
	  draw_prep.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -L /usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
