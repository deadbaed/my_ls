##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## try not to segfault, good luck :)
##

CFLAGS += -Wall -Wextra -Iinclude
LDFLAGS +=
CC = cc

INC = include/my_ls.h
OBJ = $(SRC:c=o)
SRC = src/my_ls.c \
      src/directory.c \
      src/ls/no_flags.c \
      src/ls/flag_l.c \
      library/put_char.c \
      library/len_str.c \
      library/put_str.c \
      library/put_str_n.c \
      library/put_str_err.c \
      library/put_nbr.c \
      library/str_compare.c \

all: my_ls

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

my_ls: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) my_ls

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
