NAME = vmiachko.filler

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c parsing.c array_figure.c manage_lst.c algorithm.c create_heat_map.c

LIB_DIR = libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) all
	$(CC) $(FLAGS) $(OBJ) -o $@ -L./libft/ -lft 
	@echo "Filler done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
