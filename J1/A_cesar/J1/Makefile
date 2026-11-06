EXEC = cesar
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

Debug: all

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c cesar.h
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -f $(OBJ) core
fclean: clean
	rm -f $(EXEC)
re: fclean all
.PHONY: all clean fclean re
