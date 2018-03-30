
NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

SRC = *.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC)
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)
	@echo "LIBFT: Library compiled"

clean:
	@rm -f *.o
	@echo "LIBFT: Removed .o files"

fclean: clean
	@rm -f $(NAME)
	@echo "LIBFT: Removed .a and .o files"

re: fclean all