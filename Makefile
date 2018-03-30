MAKE = make -C
NAME = rzarate.filler
LIB = src/libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = src/libft/libft.a \
			src/main.c \
			src/parsing.c

OBJECTS = $(CFILES:.c=.o)

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

$(NAME):
	@$(LIBM)
	@echo "LIBFT: Library successfully compiled"
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME) 
	@echo "Filler: Successfull compilation"

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)
	@echo "Filler: Removed .o files"

fclean: clean
	@$(LIBF)
	@echo "LIBFT: Removed .a"
	@/bin/rm -f $(NAME)
	@echo "Filler: Removed exacutable"

re: fclean all
