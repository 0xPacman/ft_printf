SRC     =       ft_printf.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

HEADER = ft_printf.h

NAME = libftprintf.a
CC = gcc
RM = rm -f
AR = ar rcs

all: $(NAME)

clean:
                $(RM) $(OBJECTS)

rmout:
                $(RM) a.out

%.o: %.c $(HEADER)
                $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
                $(AR) $(NAME) $(OBJECTS)

fclean: clean
                $(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
